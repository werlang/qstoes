<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	
	if ($_POST['action'] == 'insert') {
		$novoassunto = $_POST['assunto'];

		$public_key = $_POST['disciplina'];
		$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch();
		$disciplina = $row['cod'];

		if ($novoassunto == "")
			echo "vazio";
		else{
			$sql = "SELECT * FROM assuntos WHERE nome = '$novoassunto' AND disciplina ='$disciplina'";
			if(!$result = $conn->query($sql)){
				die('There was an error running the query [' . $conn->error . ']'); 
			}
			if ($result->rowCount() == 0){			
				$sql = "INSERT INTO assuntos (nome, disciplina) VALUES ('$novoassunto','$disciplina')";
				if(!$result = $conn->query($sql))
					die('There was an error running the query [' . $conn->error . ']'); 
				else
					echo "Assunto inserido com sucesso";
			}
			else
				echo "existe";
		}
	}
	elseif ($_POST['action'] == 'delete'){
		$cod = $_POST['cod'];
		
		$sql = "DELETE FROM assuntos WHERE cod = $cod;";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$sql = "DELETE FROM assunto_questao WHERE ce_assunto = $cod;";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$sql = "DELETE FROM assunto_submissao WHERE ce_assunto = $cod;";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		echo "Assunto apagado";
	}
	elseif ($_POST['action'] == 'rename') {
		$cod = $_POST['cod'];
		$novoassunto = $_POST['assunto'];
		$disciplina = $_POST['disciplina'];

		$sql = "SELECT * FROM assuntos WHERE nome = '$novoassunto' AND disciplina ='$disciplina'";
		
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']'); 
		}
		if ($result->rowCount() == 0){
			if ($novoassunto == ""){
				echo "vazio";
			}
			else{
				$sql = "UPDATE assuntos SET nome = '$novoassunto' WHERE cod = $cod;";
				if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
				echo "Assunto renomeado";
			}
		}
		else
			echo "existe";
	}
		
?>