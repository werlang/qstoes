<?php
	include_once "connection.php";
	
	if ($_POST['click'] == "choose"){
		$questao = $_POST['questao'];
		$resolucao = $_POST['resolucao'];
		
		$sql = "UPDATE questoes SET escolhida = '$resolucao' WHERE cod = '$questao'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	}
	else{
		$cod = $_POST['cod'];
		$rate = $_POST['rate'];

		$sql = "UPDATE resolucoes SET votos = votos + $rate WHERE cod = '$cod'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		
		$cookie_name = "qstoes_resrate$cod";
		$cookie_value = $_POST['click'];
		setcookie($cookie_name, $cookie_value, time() + (86400), "/"); // 86400 = 1 day
	}
?>