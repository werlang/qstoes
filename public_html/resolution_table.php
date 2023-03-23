<?php
    include_once "connection.php";
    session_start();
    if((!isset ($_SESSION['user']) == true)) {
        unset($_SESSION['user']);
        header('location:index.php');
    }
    $user = $_SESSION['user'];

    $private_key = "a3f05c8283e5350106829f855c93c07d";
    $public_key = $_POST['disciplina'];
    $sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
    $row = $result->fetch();
    $disciplina = $row['cod'];	


    $limit = $_POST['limit'];
    if (isset($_POST['offset']))
        $offset = $_POST['offset'];
    else
        $offset = 0;

    $msg = "";
    $sql_count = "(SELECT count(*) FROM resolucoes r INNER JOIN questoes q ON q.cod = r.questao INNER JOIN disciplinas d ON d.cod = q.disciplina WHERE d.professor = '$user' AND d.cod = $disciplina) as qresolucoes";
    $sql = "SELECT r.cod as cod, r.envio as envio, r.questao as questao, r.mensagem as mensagem, r.arquivo as arquivo, r.nome, $sql_count FROM resolucoes r INNER JOIN questoes q ON q.cod = r.questao WHERE q.disciplina = $disciplina ORDER BY r.envio DESC LIMIT $limit OFFSET $offset";
    //echo $sql;
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

    while($row = $result->fetch()){
        $envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
        $questao = $row['questao'];
        $mensagem = $row['mensagem'];
        $nrows = $row['qresolucoes'];
        $arquivo =  $row['arquivo'];
        $nome =  $row['nome'];
        $cod =  $row['cod'];
        $msg .= "
        <div class='row' id='resol$cod' data-file='$arquivo'>
            <div class='cell m-show'>$envio</div>
            <div class='cell m-show'>$questao</div>
            <div class='cell t-hide'>$nome</div>
            <div class='cell'>$mensagem</div>
        </div>
        ";
    }
    
    if ($result->rowCount() > 0 && $nrows > $limit){
        $offsetlim = $offset+$limit;
        $offset_show = $offset+1;
        $msg .= "
        <div id='container-pages' data-nrows='$nrows' data-offset='$offset'>
            <img id='prev' src='icon/anterior.png'>
            <div>$offset_show - $offsetlim de $nrows</div>
            <img id='next' src='icon/proximo.png'>
        </div>
        ";
    }
    
    echo $msg;
?>