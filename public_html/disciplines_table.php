<?php
	include_once "connection.php";
	session_start();
	$user = $_SESSION['user'];
	$limit = $_POST['limit'];
	if (isset($_POST['offset']))
		$offset = $_POST['offset'];
	else
		$offset = 0;
	
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$msg = "";
	
	$sql_votos = "(SELECT count(*) FROM resolucoes r2 INNER JOIN questoes q2 ON q2.cod = r2.questao INNER JOIN disciplinas d3 ON d3.cod = q2.disciplina WHERE r2.votos != 0 AND d3.cod = d.cod)";
	$sql_count = "(SELECT count(*) FROM disciplinas WHERE professor = '$user')";
	$sql_resol = "(SELECT count(*) FROM resolucoes r INNER JOIN questoes q ON q.cod = r.questao INNER JOIN disciplinas d2 ON d2.cod = q.disciplina WHERE d.cod = d2.cod)";
	$sql = "SELECT d.cod as cod, d.nome as nome, (SELECT count(*) FROM questoes WHERE disciplina = d.cod) as questoes, (SELECT count(*) FROM assuntos WHERE disciplina = d.cod) as assuntos, $sql_resol as resolucoes, (SELECT count(*) FROM avaliacoes a INNER JOIN questoes q ON a.questao = q.cod WHERE q.disciplina = d.cod) as avaliacoes, $sql_count AS qdisciplinas, $sql_votos AS votos FROM disciplinas d INNER JOIN professor_disciplina pd ON d.cod = pd.disciplina WHERE pd.professor = '$user' ORDER BY d.nome LIMIT $limit OFFSET $offset";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	while($row = $result->fetch_assoc()){
		$cod = $row['cod'];
		$nome = $row['nome'];
		$questoes = $row['questoes'];
		$assuntos = $row['assuntos'];
		$resolucoes = $row['resolucoes'];
		$avaliacoes = $row['avaliacoes'];
		$votos = $row['votos'];
		$nrows = $row['qdisciplinas'];

		$public_key = md5( $private_key . md5($cod) );
		$msg .= "
		<div class='row' id='$public_key'>
			<div class='cell m-show'>$nome</div>
			<div class='cell'>$questoes</div>
			<div class='cell'>$assuntos</div>
			<div class='cell'>$resolucoes</div>
			<div class='cell t-hide'>$avaliacoes</div>
			<div class='cell t-hide'>$votos</div>
		</div>
		";
	}
	
	if ($result->num_rows > 0 && $nrows > $limit){
		$offsetlim = $offset+$limit;
		$offset_show = $offset+1;
		$msg .= "
		<div id='container-pages' data-nrows='$nrows' data-offset='$offset'>
			<img id='prev' src='icon/anterior.png'>
			<div>$offset_show - $offsetlim de $nrows</div>
			<img id='next' src='icon/proximo.png'>
		</div>
		";
	}
	
	echo $msg;
	
?>						