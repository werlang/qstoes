<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}

	$private_key = "a33905b8e53fe71f51962f58de76cbcd";
	if (isset($_GET['a']) && isset($_GET['e'])){
		$a = $_GET['a'];
		$e = $_GET['e'];
		$sql = "SELECT * FROM professores WHERE resetpass = '". md5($private_key.$a) ."';";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch();
		$nrows = $result->rowCount();
		if ($e == $row['email'] && $nrows!=0){
			session_start();
			$_SESSION['user'] = $e;
			$_SESSION['resetpass'] = true;
			header('location:profile.php');
			$sql = "UPDATE professores SET resetpass = NULL WHERE email = '$e';";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		}
		else{
			session_start();
			unset($_SESSION['user']);
			header('location:index.php');
		}
	}
	$email = $_POST['email'];
		
	$sql = "SELECT * FROM professores WHERE email = '". $email ."';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch();
	$nrows = $result->rowCount();
	if ($nrows == 0)
		echo "not";
	else{
		if ($row['ativo'] == 0)
			echo "inativo";
		else{
			$titulo = $row['titulo'];
			$nome = $row['nome'];
			$sobrenome = $row['sobrenome'];
			$strkey = md5(mt_rand());
			
			$sql = "UPDATE professores SET resetpass = '". md5($private_key.$strkey) ."' WHERE email = '". $email ."';";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			
			$tipo_email = "resetpass";
			include "send_mail.php";
			echo "ok";
		}
	}
?>