<?php
	include_once "connection.php";
	$nome_prof = $_POST['nome_prof'];
	$nome_aluno = $_POST['nome_aluno'];
	$mensagem = $_POST['mensagem'];
	if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL))
		echo 'O email informado não é válido';
	else{
		$tipo_email = "convite";
		include "send_mail.php";
		echo "Convite enviado. Agora peça o link da disciplina para o professor.";
		//$msg = $mensagemRetorno;
	}
?>