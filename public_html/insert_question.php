<?php
	include_once "connection.php";
	$disciplina = $_POST['disciplina'];
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$sql = "SELECT d.cod AS cod, p.email AS email, p.nome AS nome, p.titulo AS titulo FROM disciplinas d INNER JOIN professores p ON d.professor = p.email WHERE md5(concat('$private_key',md5(d.cod))) = '$disciplina'";
	if(!$result = $conn->query($sql)){
		die('There was an error running the query [' . $conn->error . ']');
	}
	$row = $result->fetch();
	$disciplina = $row['cod'];
	$email = $row['email'];
	$nome = $row['titulo']. " " .$row['nome'];

	$texto = $_POST['texto'];
	$sql = "INSERT INTO questoes (texto,disciplina) VALUES ('$texto','$disciplina');";
	if(!$result = $conn->query($sql)){
		die('There was an error running the query [' . $conn->error . ']');
	}
	$codq = $conn->lastInsertId();
	$sql = "INSERT INTO assunto_questao (ce_assunto, ce_questao) VALUES ";
	$first = true;
	foreach ($_POST['assunto'] as $assunto){
		if ($first)
			$first = false;
		else
			$sql .= ",";
		$sql .= "('$assunto','$codq')";
	}
	if(!$result = $conn->query($sql)){
		die('There was an error running the query [' . $conn->error . ']');
	}
	
	$sql = "INSERT INTO resolucoes (questao,envio,nome,email) VALUES ('$codq',now(),'$nome','$email');";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']');}
	$codr = $conn->lastInsertId();
	
	$foldername = "questoes-res";
	$cod = "$codq-$codr";
	include "file_script.php";
	if ($uploadMsg == "OK"){
		$sql = "UPDATE resolucoes SET arquivo = '$targetfile' WHERE cod = $codr;";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	}
	else {
		$sql = "DELETE FROM resolucoes WHERE cod = $codr;";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	}

	$foldername = "questoes-img";
	include "file_script.php";
	if ($uploadMsg == "OK"){
		$sql = "UPDATE questoes SET imagem = '$targetfile' WHERE cod = $codq;";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
	}

	echo $codq;
?>