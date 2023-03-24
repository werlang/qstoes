<?php
    session_start();
    include_once "connection.php";
    if((!isset ($_SESSION['user']) == true)) {
        unset($_SESSION['user']);
        header('location:index.php');
    }
    $user = $_SESSION['user'];
    $private_key = "a3f05c8283e5350106829f855c93c07d";
    $sql = "SELECT * FROM professores WHERE email = '$user';";
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
    $row = $result->fetch();

    $titulo = $row['titulo'];
    $nome = $row['nome'];
    $email = $row['email'];
    
    $sql = "SELECT d.cod as cod, d.nome as nome FROM disciplinas d INNER JOIN professor_disciplina pd ON d.cod = pd.disciplina WHERE pd.professor = '$email';";
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
    while($row = $result->fetch()){
        $cod = md5( $private_key . md5($row['cod']) );
        $disciplinas[ $cod ] = $row['nome'];
    }
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8' />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
    <title>Qstoes - Editar</title>
    <link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
    <link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
    <link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
    <link type='text/css' rel='stylesheet' href='css/selects.css'/> 
    <link type='text/css' rel='stylesheet' href='css/popups.css'/> 
    <link type='text/css' rel='stylesheet' href='css/checkboxes.css'/> 
    <link type='text/css' rel='stylesheet' href='css/lists.css'/> 
    <link type='text/css' rel='stylesheet' href='css/e-cards.css'/> 
    <link type='text/css' rel='stylesheet' href='css/editar.css'/> 
    <script type="text/javascript" src="script/jquery.min.js"></script>
    <script type="text/javascript" src="script/inputs.js"></script>
    <script type="text/javascript" src="script/buttons.js"></script>
    <script type="text/javascript" src="script/selects.js"></script>
    <script type="text/javascript" src="script/popups.js"></script>
    <script type="text/javascript" src="script/checkboxes.js"></script>
    <script type="text/javascript" src="script/editar.js"></script>
</head>

<body>
    <?php include "side_menu.php"; ?>
    <div id='frame-wrapper'>
        <div id='frame'>
            <form id="formsubmit">
                
                <h1>Pesquisa de questões</h1>

                <div id='disciplina-container'>
                    <p><?php echo "$titulo $nome"; ?>, escolha uma de suas disciplinas</p>

                    <select class='select search' id='select-disciplinas' name='disciplina'>
                        <?php foreach($disciplinas as $cod=>$nome) echo "<option value='$cod'>$nome</option>"; ?>
                    </select>
                </div>
                
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
                <div id='texto' class='e-button'>
                    <span>Alterar texto</span>
                    <img src='icon/texto.png'>
                </div>
                <div id='assuntos' class='e-button'>
                    <span>Alterar assuntos</span>
                    <img src='icon/assuntos.png'>
                </div>
                <div id='imagem' class='e-button'>
                    <span>Alterar imagem</span>
                    <img src='icon/imagem.png'>
                </div>
                <div id='resolucao' class='e-button'>
                    <span>Alterar resoluções</span>
                    <img src='icon/upload_round.png'>
                </div>
                <div id='apagar' class='e-button'>
                    <span>Apagar questão</span>
                    <img src='icon/x.png'>
                </div>
            </div>
            <div id='alteracoes' class='linha e-button-container'>
                <div id='texto'></div>
                <div id='sim' class='e-button'>
                    <img src='icon/check.png'>
                </div>
                <div id='nao' class='e-button'>
                    <img src='icon/x_plain.png'>
                </div>
            </div>
            
            <form id='formupdate' hidden>
                <input type='text' id='id' name='id'>
                <input type='text' id='field' name='field'>
                <textarea id='info' name='info'></textarea>
                <input type="file" name="imageToUpload" id="imageToUpload" accept=".gif,.jpg,.png,.bmp">
                <input type="file" name="fileToUpload" id="fileToUpload">
            </form>
            
        </div>
        <div class='credits'>
            <span>© 2023 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pablowerlang@ifsul.edu.br'>pablowerlang@ifsul.edu.br</a></span>
        </div>
    </div>
</body>
</html>
