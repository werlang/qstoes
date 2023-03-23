<?php
	include_once "connection.php";
	session_start();
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
	
	$private_key = "af0d6a3af83fd3f7db47d068b3c7bc5a";
	$msg = "";
	$sql_count = "(SELECT count(*) FROM listas WHERE disciplina = $disciplina) AS qlistas";
	$sql = "SELECT l.cod as cod, l.nome as nome, l.descricao as descricao, (SELECT count(*) FROM lista_questao WHERE ce_lista = l.cod) as questoes, $sql_count FROM listas l WHERE l.disciplina = $disciplina ORDER BY l.ordem, l.cod LIMIT $limit OFFSET $offset";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	while($row = $result->fetch()){
		$cod = $row['cod'];
		$descricao = $row['descricao'];
		$nome = $row['nome'];
		$questoes = $row['questoes'];
		$nrows = $row['qlistas'];
		
		$public_key = md5( $private_key . md5($cod) );
		$msg .= "
		<div class='row' id='list$cod' data-key='$public_key'>
			<div class='cell m-show'>$nome</div>
			<div class='cell t-hide'>$questoes</div>
			<div class='cell'>$descricao</div>
		</div>
		";
	}
	
	if ($result->rowCount() > 0 && $nrows > $limit){
		$offsetlim = $offset+$limit;
		$offset_show = $offset+1;
		$msg .= "
		|<div id='container-pages' data-nrows='$nrows' data-offset='$offset'>
			<img id='prev' src='icon/anterior.png'>
			<div>$offset_show - $offsetlim de $nrows</div>
			<img id='next' src='icon/proximo.png'>
		</div>
		";
	}
	
	echo "$msg";
	
?>						