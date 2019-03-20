<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$user = $_SESSION['user'];
	if (!isset($_POST['mensagem'])){
		$row = search_resolution();
		$email = $row['email'];
		$action = explode("|",$_POST['action']);
		if (isset($action[1]) || !isset($email)){
			resolve_file_and_db($row);
		}
		else{
			echo "feedback";
		}
	}
	else{
		$mensagem = mysqli_real_escape_string($conn, $_POST['mensagem']);
		$row = search_resolution();
		$email = $row['email'];
		$nome = $row['nome'];
		$envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
		$questao = $row['questao'];
		$action = explode("|",$_POST['action'])[0];
			
		resolve_file_and_db($row);

		$sql = "SELECT nome, titulo FROM professores WHERE email = '$user'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch_assoc();
		$nome_prof = $row['nome'];
		$titulo = $row['titulo'];
		
		$tipo_email = "feedback_resolution";
		include "send_mail.php";
		
	}
	
function resolve_file_and_db($row){
	$cod = $_POST['cod'];
	$action = explode("|",$_POST['action'])[0];
	global $conn;
	$arquivo = $row['arquivo'];
	$questao = $row['questao'];
	$email = $row['email'];
	$nome = $row['nome'];	
	
	$sql = "DELETE FROM resolucoes WHERE cod = $cod";
	//echo $sql;
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

	if ($action == "aceita"){
		$array_name = explode(".",$arquivo);
		$array_name = $array_name[count($array_name)-1];
		$target_file = "questoes-res/$questao.$array_name";
		rename($arquivo, $target_file);
		
		$sql = "UPDATE questoes SET resolucao = '$target_file' WHERE cod = $questao";
		//echo $sql;
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		echo "aceito";
	}
	elseif ($action == "recusa"){
		unlink($arquivo);
		echo "recusado";
	}
}

function search_resolution(){
	$cod = $_POST['cod'];
	global $conn;
	$sql = "SELECT * FROM resolucoes WHERE cod = $cod";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	return $result->fetch_assoc();
}
?>