<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$user = $_SESSION['user'];
	$disciplina = $_POST['disciplina'];
	$limit = $_POST['limit'];
	if (isset($_POST['offset']))
		$offset = $_POST['offset'];
	else
		$offset = 0;

	$msg = "";
	$sql_count = "(SELECT count(*) FROM submissoes s WHERE s.disciplina = $disciplina) as qsubmissoes";
	$sql = "SELECT s.cod as cod, s.envio as envio, s.nome as nome, s.email as email, $sql_count FROM submissoes s WHERE s.disciplina = $disciplina ORDER BY s.envio LIMIT $limit OFFSET $offset";
	//echo $sql;
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

	while($row = $result->fetch_assoc()){
		$envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
		$nome = $row['nome'];
		$email = $row['email'];
		$nrows = $row['qsubmissoes'];
		$cod =  $row['cod'];
		$msg .= "
		<div class='row' id='sub$cod'>
			<div class='cell m-show'>$envio</div>
			<div class='cell'>$nome</div>
			<div class='cell'>$email</div>
		</div>
		";
	}
	
	if ($result->num_rows > 0 && $nrows > $limit){
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