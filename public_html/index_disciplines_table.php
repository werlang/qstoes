<?php
	include_once "connection.php";

	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$msg = "";
	
	$sql = "SELECT d.cod AS cod, d.nome AS disciplina, p.nome AS nprof, p.sobrenome AS sprof FROM disciplinas d INNER JOIN professores p ON d.professor = p.email WHERE d.publica = '1'";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	while($row = $result->fetch()){
		$cod = $row['cod'];
		$professor = $row['nprof'] ." ". $row['sprof'];
		$disciplina = $row['disciplina'];

		$public_key = md5( $private_key . md5($cod) );
		$msg .= "
		<a href='gerar.php?d=$public_key' target='_blank' class='row'>
			<div class='cell'>$professor</div>
			<div class='cell m-show'>$disciplina</div>
		</a>
		";
	}
	echo $msg;
	
?>						