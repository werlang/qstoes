<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$user = $_SESSION['user'];
	$mensagem = mysqli_real_escape_string($conn, $_POST['mensagem']);
	$row = search_submission();
	$email = $row['email'];
	$nome = $row['nome'];
	$texto = $row['texto'];
	$envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
	$action = $_POST['action'];
	
	$questao = resolve_file_and_db($row);

	$sql = "SELECT nome, titulo FROM professores WHERE email = '$user'";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch_assoc();
	$nome_prof = $row['nome'];
	$titulo = $row['titulo'];
	
	$tipo_email = "feedback_submission";
	include "send_mail.php";
	
function resolve_file_and_db($row){
	$cod = $_POST['cod'];
	$action = $_POST['action'];
	global $conn;
	if (isset($row['resolucao']))
		$resolucao = $row['resolucao'];
	if (isset($row['imagem']))
		$imagem = $row['imagem'];
	$email = $row['email'];
	$nome = $row['nome'];	
	$texto = $row['texto'];
	$disciplina = $row['disciplina'];
	$assuntos = search_tags();
	
	$sql = "DELETE FROM submissoes WHERE cod = $cod";
	//echo $sql;
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$sql = "DELETE FROM assunto_submissao WHERE ce_submissao = $cod";
	//echo $sql;
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

	if ($action == "aceita"){
		$sql = "INSERT INTO questoes (texto,disciplina) VALUES ('$texto','$disciplina')";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$questao = $conn->insert_id;

		$sql = "INSERT INTO assunto_questao (ce_assunto, ce_questao) VALUES ";
		$first = true;
		foreach ($assuntos as $assunto){
			if ($first)
				$first = false;
			else
				$sql .= ",";
			$sql .= "('$assunto','$questao')";
		}
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		
		if (isset($resolucao)){
			$array_name = explode(".",$resolucao);
			$extensao = $array_name[count($array_name)-1];
			
			$target_file = "questoes-res/$questao.$extensao";
			rename($resolucao, $target_file);

			$sql = "UPDATE questoes SET resolucao = '$target_file' WHERE cod = $questao";
			//echo $sql;
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		}
		
		if (isset($imagem)){
			$array_name = explode(".",$imagem);
			$extensao = $array_name[count($array_name)-1];
			
			$target_file = "questoes-img/$questao.$extensao";
			rename($imagem, $target_file);

			$sql = "UPDATE questoes SET imagem = '$target_file' WHERE cod = $questao";
			//echo $sql;
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		}

		echo "aceito";
		return $questao;
	}
	elseif ($action == "recusa"){
		if (isset($resolucao))
			unlink($resolucao);
		if (isset($imagem))
			unlink($imagem);
		echo "recusado";
	}
}

function search_submission(){
	$cod = $_POST['cod'];
	global $conn;
	$sql = "SELECT * FROM submissoes WHERE cod = $cod";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	return $result->fetch_assoc();
}

function search_tags(){
	$cod = $_POST['cod'];
	global $conn;
	$sql = "SELECT ce_assunto FROM assunto_submissao WHERE ce_submissao = $cod";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$assuntos = array();
	while($row = $result->fetch_assoc()){
		array_push($assuntos,$row['ce_assunto']);
	}
	return $assuntos;
}
?>