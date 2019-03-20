<?php
	include_once "connection.php";
	session_start();
	$user = $_SESSION['user'];
	$lista = $_POST['lista'];
	
	$msg = "";
	$sql = "SELECT ce_questao FROM lista_questao WHERE ce_lista = $lista ORDER BY ordem, cod";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$first = true;
	while($row = $result->fetch_assoc()){
		if ($first)
			$first = false;
		else
			$msg .= ",";
		$msg .= $row['ce_questao'];
	}
	echo $msg;
	
?>