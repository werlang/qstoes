<?php
    include_once "connection.php";
    session_start();
    if (isset($_GET['d'])){
        $disciplina = $_GET['d'];
        $_SESSION['disciplina'] = $disciplina;
    }
    if((!isset ($_SESSION['disciplina']) == true)) {
        unset($_SESSION['disciplina']);
        header('location:index.php');
    }
    $private_key = "a3f05c8283e5350106829f855c93c07d";
    $sql = "SELECT nome FROM disciplinas WHERE md5(concat('$private_key',md5(cod))) = '$disciplina'";
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
    $row = $result->fetch();
    $nome_disciplina = $row['nome'];
?>

<!DOCTYPE html>
<html>
<head>
<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-92603732-1"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-92603732-1');
</script>

    <meta charset='utf-8' />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
    <title><?php echo $nome_disciplina; ?></title>
    <link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
    <link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
    <link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
    <link type='text/css' rel='stylesheet' href='css/selects.css'/> 
    <link type='text/css' rel='stylesheet' href='css/popups.css'/> 
    <link type='text/css' rel='stylesheet' href='css/lists.css'/> 
    <link type='text/css' rel='stylesheet' href='css/checkboxes.css'/> 
    <link type='text/css' rel='stylesheet' href='css/e-cards.css'/>
    <link type='text/css' rel='stylesheet' href='css/gerar.css'/> 
    <script type="text/javascript" src="script/jquery.min.js"></script>
    <script type="text/javascript" src="script/inputs.js"></script>
    <script type="text/javascript" src="script/buttons.js"></script>
    <script type="text/javascript" src="script/selects.js"></script>
    <script type="text/javascript" src="script/popups.js"></script>
    <script type="text/javascript" src="script/checkboxes.js"></script>
    <script type="text/javascript" src="script/gerar.js"></script>
</head>

<body>
    <?php include "header.php"; ?>
    <div id='frame-wrapper'>
        <div id='frame'>
            <form id="formsubmit">
                
                <div id='container-titulo'>
                    <h1>Pesquisa de questões</h1>
                </div>
                
                <input name='disciplina' type='hidden' value='<?php echo $disciplina ?>'>
                
                <h3>Incluir questões que possuam obrigatoriamente estes assuntos:</h3>
                <div class='e-card-container' id='div-assuntos-e'><span class='nao-achou'>Nenhum assunto selecionado</span></div>
                <div id='add-assunto-e' class='button-opa'><div class='texto'>Adicionar assunto</div></div>
                <h3>Incluir questões que possuam pelo menos um destes assuntos:</h3>
                <div class='e-card-container' id='div-assuntos-ou'><span class='nao-achou'>Todos assuntos selecionados</span></div>
                <div id='add-assunto-ou' class='button-opa'><div class='texto'>Adicionar assunto</div></div>
                <h3>Excluir questões que possuam algum destes assuntos:</h3>
                <div class='e-card-container' id='div-assuntos-not'><span class='nao-achou'>Nenhum assunto selecionados</span></div>
                <div id='add-assunto-not' class='button-opa'><div class='texto'>Adicionar assunto</div></div>

                <h3>Incluir na pesquisa:</h3>
                <div id='texto-container'>
                    <select id='select-texto' name='opt-texto' class='select'>
                        <option value='palavras'>Palavras deste texto</option>
                        <option value='exatamente'>Exatamente esta frase</option>
                        <option value='id'>Os IDs das questões</option>
                    </select>
                    <input type='text' id='campo-busca' name='campo-busca' class='red-input' placeholder='EX: menu idade pessoas banco'>
                </div>
                <div id='filtro'>
                    <div class='linha'>
                        <span id='texto-ordem'>Ordenar por:</span>
                        <select id='select-ordem' name='select-ordem' class='select'>
                            <option value='relevancia'>Relevância na busca</option>
                            <option value='id'>Código da questão</option>
                            <option value='dif-up'>Maior dificuldade</option>
                            <option value='dif-down'>Menor dificuldade</option>
                            <option value='elaboracao'>Melhor avaliação</option>
                        </select>
                    </div>
                    <label>
                        <input type='checkbox' id='check-resolucao' name='check-resolucao' class='checkslider'>
                        Mostrar somente questões que possuem resolução
                    </label>
                </div>

                <div id='button-wrapper'>
                    <button id='bpesquisa' class='button-red can-disable'>Pesquisar</button>
                </div>
                
                <input type='hidden' name='limit' id='offset-limit' value='0|10'>
            </form>
                
            <div id='div-questoes'></div>

            <div id='opcoes' class='linha e-button-container'>
                <div id='denuncia' class='e-button'>
                    <span>Reportar</span>
                    <img src='icon/exclam.png'>
                </div>
                <div id='resolucao' class='e-button'>
                    <span>Resolução</span>
                    <img class='download' src='icon/bulb.png'>
                    <img class='upload' src='icon/bulb_off.png'>
                </div>
                <div id='avaliacao' class='e-button'>
                    <span>Avaliar</span>
                    <img src='icon/star.png'>
                </div>
                <div id='link' class='e-button'>
                    <span>Questão</span>
                    <img src='icon/link.png'>
                </div>
            </div>	
        </div>
        <div class='credits'>
            <span>© 2023 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pablowerlang@ifsul.edu.br'>pablowerlang@ifsul.edu.br</a></span>
        </div>
    </div>
</body>
</html>
