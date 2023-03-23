<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$user = $_SESSION['user'];
	$sql = "SELECT * FROM professores WHERE email = '$user';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch();

	$titulo = $row['titulo'];
	$nome = $row['nome'];
	$email = $row['email'];
	
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8' />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
	<title>Qstoes - Denúncias enviadas</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/selects.css'/> 
	<link type='text/css' rel='stylesheet' href='css/tables.css'/> 
	<link type='text/css' rel='stylesheet' href='css/denuncias.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/inputs.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/selects.js"></script>
	<script type="text/javascript" src="script/denuncias.js"></script>
</head>
<body>
	<?php include "side_menu.php"; ?>
	<div id='frame-wrapper'>
		<div id='frame'>
			<h1>Denúncias enviadas</h1>

			<div class='table'>
				<div class='thead'>
					<div class='row'>
						<div class='cell m-show'>Envio</div>
						<div class='cell m-show t-hide'>Questão</div>
						<div class='cell'>Motivo</div>
						<div class='cell'>Mensagem</div>
					</div>
				</div>
				<div class='tbody'></div>
			</div>
			<div id='opcoes' class='linha'>
				<div id='questao' class='e-card disabled'>
					<a target='_blank'><img src='icon/show.png'></a>
				</div>
				<div id='excluir' class='e-card disabled'>
					<img src='icon/x.png'>
				</div>
			</div>
		</div>
		<div class='credits'>
			<span>© 2020 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
		</div>
	</div>
</body>
</html>