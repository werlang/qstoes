<?php
	include_once "connection.php";
	$mensagem = mysqli_real_escape_string($conn, $_POST['mensagem']);
	$nome = mysqli_real_escape_string($conn, $_POST['nome']);
	$email = mysqli_real_escape_string($conn, $_POST['email']);
	$cod_questao = $_POST['questao'];
	$motivo = $_POST['motivo'];
	
	if ($email == "")
		$email = "NULL";
	else
		$email = "'$email'";
	if ($nome == "")
		$nome = "NULL";
	else
		$nome = "'$nome'";

	$sql = "INSERT INTO denuncias (questao,texto,envio,email,nome,tipo) VALUES ('$cod_questao','$mensagem',now(),$email,$nome,$motivo)";
	if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
	
	
	echo "enviado";
?>