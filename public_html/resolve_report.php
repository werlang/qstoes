<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}	
	$user = $_SESSION['user'];
	$cod = $_POST['cod'];
	
	if (!isset($_POST['mensagem'])){
		$row = search_report();
		$email = $row['email'];
		if (!isset($email) || isset($_POST['action']) ){
			$sql = "DELETE FROM denuncias WHERE cod = $cod";
			//echo $sql;
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			
			echo "excluido";
		}
		else{
			echo "feedback";
		}
	}
	else{
		$mensagem = $_POST['mensagem'];
		$row = search_report();
		$texto = $row['texto'];
		$email = $row['email'];
		$nome = $row['nome'];
		$envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
		$questao = $row['questao'];
		$tipo = $row['tipo'];
		$motivo_array = array(
						"Conteúdo impróprio ou ofensivo",
						"Questão mal formulada ou com erros",
						"Questão repetida ou muito semelhante",
						"Assuntos incompatíveis aos cadastrados",
						"Resolução incorreta ou link quebrado",
						"Outros motivos");
		$motivo = $motivo_array[$tipo];

		$sql = "DELETE FROM denuncias WHERE cod = $cod";
		//echo $sql;
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

		$sql = "SELECT nome, titulo FROM professores WHERE email = '$user'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch();
		$nome_prof = $row['nome'];
		$titulo = $row['titulo'];
		
		$tipo_email = "feedback_report";
		include "send_mail.php";

		echo "excluido";
	}
	
function search_report(){
	$cod = $_POST['cod'];
	global $conn;
	$sql = "SELECT * FROM denuncias WHERE cod = $cod";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	return $result->fetch();
}
?>