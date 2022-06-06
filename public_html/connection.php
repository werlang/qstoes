<?php


	$servername = "localhost";
	$username = "qstoes";
	$password = "s0r3tmhr";
	$database = "qstoes_";

/*
	//hostinger
	$servername = "mysql.hostinger.com.br";
	$username = "u709824322_admin";
	$password = "s0r3tmhr";
	$database = "u709824322_db";
*/
/*
	//local
	$servername = "127.0.0.1";
	$username = "root";
	$password = "";
	$database = "id1824096_qstoes";
*/
	// Create connection
	$conn = new mysqli($servername, $username, $password, $database);
	mysqli_set_charset($conn,"utf8mb4");

	// Check connection
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	} 
?>