<?php
	include_once "connection.php";
	session_start();
	$user = $_SESSION['user'];
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	if ($_POST['action'] == 'insert'){
		$newdisc = explode("|",$_POST['info'])[1];
		if ($newdisc == "")
			echo "vazio";
		else{
			$public_disc = explode("|",$_POST['info'])[0];
			if ($public_disc == "true")
				$public_disc = 1;
			else
				$public_disc = 0;
			$sql = "SELECT * FROM disciplinas WHERE professor = '$user' AND nome = '$newdisc'";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			if ($result->rowCount() != 0){
				echo "vazio";
			}
			else{
				$sql = "INSERT INTO disciplinas (nome, professor, publica) VALUES ('$newdisc','$user','$public_disc');";
				if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
				$cod = $conn->lastInsertId();
				$sql = "INSERT INTO professor_disciplina (professor, disciplina) VALUES ('$user','$cod');";
				if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
				echo "inserido";
			}
		}
	}
	if ($_POST['action'] == 'delete'){
		$public_key = $_POST['info'];
		$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch();
		$cod = $row['cod'];
		
		$sql = "DELETE FROM assunto_questao WHERE ce_questao IN (SELECT cod FROM questoes WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "DELETE FROM assunto_submissao WHERE ce_assunto IN (SELECT cod FROM assuntos WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "DELETE FROM avaliacoes WHERE questao IN (SELECT cod FROM questoes WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "DELETE FROM denuncias WHERE questao IN (SELECT cod FROM questoes WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "SELECT arquivo FROM resolucoes WHERE questao IN (SELECT cod FROM questoes WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		while($row = $result->fetch()){
			if ($row['arquivo'] != "")
				unlink($row['arquivo']);
		}
		$sql = "DELETE FROM resolucoes WHERE questao IN (SELECT cod FROM questoes WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "DELETE FROM questoes WHERE disciplina = '$cod';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "SELECT resolucao FROM submissoes WHERE disciplina = '$cod';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		while($row = $result->fetch()){
			if ($row['resolucao'] != "")
				unlink($row['resolucao']);
		}
		$sql = "DELETE FROM submissoes WHERE disciplina = '$cod';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "DELETE FROM assuntos WHERE disciplina = '$cod';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "DELETE FROM disciplinas WHERE cod = '$cod';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		
		$sql = "DELETE FROM professor_disciplina WHERE disciplina = '$cod';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		echo "deletado";
	}
	if ($_POST['action'] == 'clear'){
		$cod = $_POST['info'];
		$sql = "DELETE FROM avaliacoes WHERE questao IN (SELECT cod FROM questoes WHERE disciplina = '$cod');";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		echo "limpo";
	}
	if ($_POST['action'] == 'rename'){
		$public_key = explode("|",$_POST['info'])[0];
		$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch();
		$cod = $row['cod'];

		$public_disc = explode("|",$_POST['info'])[1];
		if ($public_disc == "true")
			$public_disc = 1;
		else
			$public_disc = 0;
		$name = explode("|",$_POST['info'])[2];
		$name = $name;

		if ($name == "")
			echo "vazio";
		else{
			$name = $name;

			$sql = "UPDATE disciplinas SET nome = '$name', publica = '$public_disc' WHERE cod = '$cod';";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

			echo "renomeado";
		}
	}
?>