<?php
	include_once "connection.php";
	session_start();
	$user = mysqli_real_escape_string($conn, $_POST['user']);
	$pass = md5($_POST['pass']);

	$sql = "SELECT count(*), ativo FROM professores WHERE email = \"". $user ."\" and senha = \"". $pass ."\";";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch_assoc();
	$nrows = $row['count(*)'];
	
	if ($nrows == 0){
		//echo 'Usuário e senha incorretos.';
		unset($_SESSION['user']);
		echo "errado";	
	}
	else{
		if ($row['ativo'] == 1){
			//echo 'Feito!';
			$_SESSION['user'] = $user;
			echo "certo";
		}
		else{
			//echo 'Conta não ativada.';
			unset($_SESSION['user']);
			echo "inativo";	
		}
	}
	
	
?>