<?php
    include_once "connection.php";
    session_start();
    if((!isset ($_SESSION['user']) == true)) {
        unset($_SESSION['user']);
        header('location:index.php');
    }
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
    <title>Qstoes - Gerenciar disciplinas</title>
    <link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
    <link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
    <link type='text/css' rel='stylesheet' href='css/popups.css'/> 
    <link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
    <link type='text/css' rel='stylesheet' href='css/tables.css'/> 
    <link type='text/css' rel='stylesheet' href='css/checkboxes.css'/> 
    <link type='text/css' rel='stylesheet' href='css/e-cards.css'/> 
    <link type='text/css' rel='stylesheet' href='css/disciplinas.css'/> 
    <script type="text/javascript" src="script/jquery.min.js"></script>
    <script type="text/javascript" src="script/popups.js"></script>
    <script type="text/javascript" src="script/buttons.js"></script>
    <script type="text/javascript" src="script/checkboxes.js"></script>
    <script type="text/javascript" src="script/disciplinas.js"></script>
</head>
<body>
    <?php include "side_menu.php"; ?>
    <div id='frame-wrapper'>
        <div id='frame'>
            <h1>Gerenciar disciplinas</h1>
            <div class='table'>
                <div class='thead'>
                    <div class='row'>
                        <div class='cell m-show'>Nome</div>
                        <div class='cell'>Questões</div>
                        <div class='cell'>Assuntos</div>
                        <div class='cell'>Resoluções</div>
                        <div class='cell t-hide'>Avaliações</div>
                        <div class='cell t-hide'>Votadas</div>
                    </div>
                </div>
                <div class='tbody'></div>
            </div>
            
            <div id='opcoes' class='linha'>
                <div id='adicionar' class='e-card'>
                    <img src='icon/plus.png'>
                </div>
                <div id='editar' class='e-card disabled'>
                    <img src='icon/edit2.png'>
                </div>
                <div id='remover' class='e-card disabled'>
                    <img src='icon/x.png'>
                </div>
                <div id='visualizar' class='e-card disabled'>
                    <img src='icon/show.png'>
                </div>
            </div>
        </div>
        <div class='credits'>
            <span>© 2023 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pablowerlang@ifsul.edu.br'>pablowerlang@ifsul.edu.br</a></span>
        </div>
    </div>
</body>
</html>