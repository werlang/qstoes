<?php
    include_once "connection.php";
    if (isset($_GET)){
        if (isset($_GET['q'])){
            $cod = $_GET['q'];
            $sql = "SELECT *, avg(av.dificuldade) as avg_dif, avg(av.elaboracao) as avg_elab, group_concat(DISTINCT a.nome) as assuntos FROM questoes q LEFT JOIN avaliacoes av ON av.questao = q.cod  INNER JOIN assunto_questao aq ON q.cod = aq.ce_questao INNER JOIN assuntos a ON a.cod = aq.ce_assunto WHERE q.cod = '$cod' GROUP BY q.cod";
            $tipo = "Questão";
        }
        elseif (isset($_GET['s'])){
            $cod = $_GET['s'];
            $sql = "SELECT *, group_concat(a.nome) as assuntos FROM submissoes s INNER JOIN assunto_submissao ass ON s.cod = ass.ce_submissao INNER JOIN assuntos a ON a.cod = ass.ce_assunto WHERE s.cod = '$cod' GROUP BY s.cod";
            $tipo = "Submissão";
        }
        if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
        $row = $result->fetch();
        
        $texto = $row['texto'];
        
        $assuntos = $row['assuntos'];
        $assuntos = str_replace(",",", ",$assuntos);
        
        $imagem = $row['imagem'];
        if (isset($imagem))
            $imagem .= "?d=".rand();
        
        if (isset($_GET['q'])){
            $dificuldade = $row['avg_dif'];
            $elaboracao = $row['avg_elab'];
        }
        if (!isset($dificuldade))
            $dificuldade = "-";
        else
            $dificuldade = number_format($dificuldade,1);

        if (!isset($elaboracao))
            $elaboracao = "-";
        else
            $elaboracao = number_format($elaboracao,1);
    }
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8' />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
    <title>Qstoes - Resoluções</title>
    <link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
    <link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
    <link type='text/css' rel='stylesheet' href='css/popups.css'/> 
    <link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
    <link type='text/css' rel='stylesheet' href='css/lists.css'/> 
    <link type='text/css' rel='stylesheet' href='css/prism.css'/> 
    <link type='text/css' rel='stylesheet' href='css/questao.css'/> 
    <script type="text/javascript" src="script/jquery.min.js"></script>
    <script type="text/javascript" src="script/popups.js"></script>
    <script type="text/javascript" src="script/buttons.js"></script>
    <script type="text/javascript" src="script/prism.js"></script>
    <script type="text/javascript" src="script/questao.js"></script>
</head>

<body>
    <?php include "header.php"; ?>
    <div id='frame-wrapper'>
        <div id='frame'>
            <ol class='rounded-list'>
                <li>
                    <div class='linha'>
                        <div><?php echo "$tipo <strong>#$cod</strong>" ?></div>
                        <div class='container-rating' <?php if(isset($_GET['s'])) echo "hidden"?>>
                            <div class='item'>
                                <img src='icon/think_brain.png'>
                                <div class='rating'><?php echo $dificuldade ?></div>
                            </div>
                            <div class='item'>
                                <img src='icon/like.png'>
                                <div class='rating'><?php echo $elaboracao ?></div>
                            </div>
                        </div>
                    </div>
                    <div class='assuntos'>
                        <p>Assuntos:</p>
                        <span><?php echo $assuntos ?></span>
                    </div>
                    <div class='texto'><?php echo $texto ?></div>
                    <div class='imagem'>
                        <img class='grafico' src='<?php echo $imagem ?>'>
                    </div>
                </li>
            </ol>
            <h3>Resoluções</h3>
            <ol class='rounded-list' id='resolucoes'></ol>
        </div>
        <div class='credits'>
            <span>© 2023 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pablowerlang@ifsul.edu.br'>pablowerlang@ifsul.edu.br</a></span>
        </div>
    </div>
</body>
</html>
