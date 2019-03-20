<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$user = $_SESSION['user'];
	
	$limit = $_POST['limit'];
	if (isset($_POST['offset']))
		$offset = $_POST['offset'];
	else
		$offset = 0;

	$msg = "";
	$sql_count = "(SELECT count(*) FROM denuncias de INNER JOIN questoes q ON q.cod = de.questao INNER JOIN disciplinas di ON di.cod = q.disciplina WHERE di.professor = '$user') as qdenuncias";
	$sql = "SELECT de.cod as cod, de.envio as envio, de.questao as questao, de.texto as mensagem, de.tipo as tipo, $sql_count FROM denuncias de INNER JOIN questoes q ON q.cod = de.questao INNER JOIN disciplinas di ON di.cod = q.disciplina WHERE di.professor = '$user' ORDER BY de.envio LIMIT $limit OFFSET $offset";
	//echo $sql;
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

	while($row = $result->fetch_assoc()){
		$envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
		$questao = $row['questao'];
		$mensagem = $row['mensagem'];
		$nrows = $row['qdenuncias'];
		$tipo =  $row['tipo'];
		$motivo_array = array(
						"Conteúdo impróprio ou ofensivo",
						"Questão mal formulada ou com erros",
						"Questão repetida ou muito semelhante",
						"Assuntos incompatíveis aos cadastrados",
						"Resolução incorreta ou link quebrado",
						"Outros motivos");
		$motivo = $motivo_array[$tipo];
		
		$cod =  $row['cod'];
		$msg .= "
		<div class='row' id='resol$cod'>
			<div class='cell m-show'>$envio</div>
			<div class='cell m-show t-hide'>$questao</div>
			<div class='cell'>$motivo</div>
			<div class='cell'>$mensagem</div>
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