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
	
	$sql = "SELECT * FROM disciplinas WHERE professor = '$email';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	while($row = $result->fetch()){
		$cod = md5( $private_key . md5($row['cod']) );
		$disciplinas[ $cod ] = $row['nome'];
	}
?>
<!DOCTYPE html>
<html>
<head>
<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-92603732-1"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-92603732-1');
</script>

	<meta charset='utf-8' />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
	<title>Qstoes - Resoluções</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/selects.css'/> 
	<link type='text/css' rel='stylesheet' href='css/tables.css'/> 
	<link type='text/css' rel='stylesheet' href='css/resolucoes.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/inputs.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/selects.js"></script>
	<script type="text/javascript" src="script/resolucoes.js"></script>
</head>
<body>
	<?php include "side_menu.php"; ?>
	<div id='frame-wrapper'>
		<div id='frame'>
			<h1>Resoluções submetidas</h1>

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
						<div class='cell m-show'>Questão</div>
						<div class='cell t-hide'>Nome</div>
						<div class='cell'>Mensagem</div>
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
				<div id='download' class='e-card disabled'>
					<a target='_blank' download><img src='icon/download.png'></a>
				</div>
			</div>
		</div>
		<div class='credits'>
			<span>© 2020 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
		</div>
	</div>
</body>
</html>