<!DOCTYPE html>

<?php
	$cargo = "";
	$salario = "";
	if (isset($_GET['c']) && isset($_GET['s'])){
		//$cargo = mysql_real_escape_string(htmlentities($_GET['c']));
		//$salario = mysql_real_escape_string(htmlentities($_GET['s']));
		$cargo = htmlentities($_GET['c']);
		$salario = htmlentities($_GET['s']);
	}
?>

<html>
<head>
	<meta charset='utf-8' />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Lupa</title>
	<link rel="icon" type="image/gif" href="logo.png" />
	<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700" type="text/css">
	<link type='text/css' rel='stylesheet' href='index.css'/> 
	<script type="text/javascript" src="jquery.min.js"></script>
	<script src="index.js"></script>
</head>

<body>
	<div class='background'></div>
	<div id='main-wrap'> 
		<div id='main-frame' class='frame'>
			<div id='info'>
				<img src='mglass.png'>
				<p>Informe sua profissáo e salário, e vamos procurar carreiras de servidores federais que possuem características parecidas com a sua.</p>
			</div>
			<input id='t-profissao' type='text' class='input' placeholder='Sua profissão' value='<?php echo $cargo ?>'>
			<input id='t-salario' type='text' class='input' placeholder='Seu salário' value='<?php echo $salario ?>'>
			<button id='b-pesquisa' class='button'>Pesquisar</button>
		</div>
	</div>
</body>
</html>
