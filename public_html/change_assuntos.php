<?php
	include_once "connection.php";
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$public_key = $_POST['disciplina'];
	$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
	$result = $conn->query($sql);
	$row = $result->fetch();
	$disciplina = $row['cod'];
	
	$sql = "SELECT * FROM assuntos WHERE disciplina = '$disciplina' ORDER BY nome;";

	if(!$result = $conn->query($sql)){
		die('There was an error running the query [' . $conn->error . ']');
	}
	if ($result->rowCount() == 0){
		echo "<h3>Nenhum assunto cadastrado nesta disciplina.</h3>";
	}
	else{
		while($row = $result->fetch()){
			$cod = $row['cod'];
			$nome = $row['nome'];
			echo "<div class='assunto'><label><input type='checkbox' class='checkslider' id='assunto[]' name='assunto[]' value='$cod'>$nome</label></div>";
		}
	}
?>
