<?php
	include_once "connection.php";
	session_start();
	$user = $_SESSION['user'];

	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$public_key = $_POST['disciplina'];
	$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch_assoc();
	$disciplina = $row['cod'];	
	
	$msg = "";
	$sql = "SELECT cod FROM questoes WHERE disciplina = $disciplina";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	while($row = $result->fetch_assoc()){
		$msg .= $row['cod'] . ",";
	}
	echo $msg;
	
?>