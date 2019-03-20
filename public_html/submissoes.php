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
	$row = $result->fetch_assoc();

	$titulo = $row['titulo'];
	$nome = $row['nome'];
	$email = $row['email'];
	
	$sql = "SELECT * FROM disciplinas WHERE professor = '$email';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	while($row = $result->fetch_assoc()){
		$disciplinas[ $row['cod'] ] = $row['nome'];
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8' />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
	<title>Qstoes</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/selects.css'/> 
	<link type='text/css' rel='stylesheet' href='css/tables.css'/> 
	<link type='text/css' rel='stylesheet' href='css/submissoes.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/inputs.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/selects.js"></script>
	<script type="text/javascript" src="script/submissoes.js"></script>
</head>
<body>
	<?php include "side_menu.php"; ?>
	<div id='frame'>
		<h1>Questões submetidas</h1>

		<div id='disciplina-container'>
			<p><?php echo "$titulo $nome"; ?>, escolha uma de suas disciplinas</p>

			<select class='select search' id='select-disciplinas' name='disciplina'>
				<?php foreach($disciplinas as $cod=>$nome) echo "<option value='$cod'>$nome</option>"; ?>
			</select>
		</div>

		<div class='table'>
			<div class='thead'>
				<div class='row'>
					<div class='cell m-show'>Envio</div>
					<div class='cell'>Nome</div>
					<div class='cell'>Email</div>
				</div>
			</div>
			<div class='tbody'></div>
		</div>
		<div id='opcoes' class='linha'>
			<div id='questao' class='e-card disabled'>
				<a target='_blank'><img src='icon/show.png'></a>
			</div>
			<div id='aceitar' class='e-card disabled'>
				<img src='icon/check_round.png'>
			</div>
			<div id='recusar' class='e-card disabled'>
				<img src='icon/x.png'>
			</div>
		</div>
	</div>
</body>
</html>