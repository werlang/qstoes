<?php
	include_once "connection.php";
	$mensagem = mysqli_real_escape_string($conn, $_POST['mensagem']);
	$nome = mysqli_real_escape_string($conn, $_POST['nome']);
	$email = mysqli_real_escape_string($conn, $_POST['email']);
	$cod_questao = $_POST['cod'];
	//print_r($_POST);
	
	if ($email == "")
		$email = "NULL";
	else
		$email = "'$email'";
	if ($nome == "")
		$nome = "NULL";
	else
		$nome = "'$nome'";

	$sql = "INSERT INTO resolucoes (questao,mensagem,envio,email,nome) VALUES ('$cod_questao','$mensagem',now(),$email,$nome)";
	if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
	
	$cod_resolucao = $conn->insert_id;
	
	$cod = "$cod_questao-$cod_resolucao";
	$foldername = "questoes-res";
	include "file_script.php";
	
	$sql = "UPDATE resolucoes SET arquivo = '$targetfile' WHERE cod = '$cod_resolucao'";
	if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
	
	echo "enviado";
?>