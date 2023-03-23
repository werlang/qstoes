<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$email = $_POST['email'];
	$senha = md5($_POST['senha']);
	
	$sql = "SELECT * FROM professores WHERE email = '$email' AND senha = '$senha';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch();
	$nrows = $result->rowCount();
	if ($nrows == 0){
		unset($_SESSION['changepass']);
		unset($_SESSION['changeemail']);
		echo "not";
	}
	else{
		if ($_POST['campo'] == "senha")
			$_SESSION['changepass'] = true;
		if ($_POST['campo'] == "email")
			$_SESSION['changeemail'] = true;
		echo "ok";
	}
?>