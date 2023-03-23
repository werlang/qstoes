<?php
	include_once "connection.php";
	session_start();
	$user = $_POST['user'];
	$pass = md5($_POST['pass']);

	$sql = "SELECT count(*) AS total, ativo FROM professores WHERE email = ? and senha = ?;";
	$stmt = $conn->prepare($sql);
	$stmt->execute([$user, $pass]);

	$row = $stmt->fetch();
	$nrows = $row['total'];
	
	if ($nrows == 0){
		//echo 'Usu�rio e senha incorretos.';
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
			//echo 'Conta n�o ativada.';
			unset($_SESSION['user']);
			echo "inativo";	
		}
	}
	
	
?>