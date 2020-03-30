<?php
	include_once "connection.php";
	session_start();
	if((!isset ($_SESSION['user']) == true)) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$user = $_SESSION['user'];
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$sql = "SELECT * FROM professores WHERE email = '$user';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch_assoc();

	$titulo = $row['titulo'];
	$nome = $row['nome'];
	$email = $row['email'];
	
	$sql = "SELECT d.cod as cod, d.nome as nome FROM disciplinas d INNER JOIN professor_disciplina pd ON d.cod = pd.disciplina WHERE pd.professor = '$email';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	while($row = $result->fetch_assoc()){
		$cod = md5( $private_key . md5($row['cod']) );
		$disciplinas[$cod] = $row['nome'];
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8' />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
	<title>Qstoes - Inserir</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/selects.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/checkboxes.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inserir.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/inputs.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/selects.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/checkboxes.js"></script>
	<script type="text/javascript" src="script/inserir.js"></script>
</head>

<body>
	<?php include "side_menu.php"; ?>
	<div id='frame-wrapper'>
		<div id='frame'>
			<form id="formsubmit">
				
				<h1>Inserção de questões</h1>

				<div class='linha'>
					<p><?php echo "$titulo $nome"; ?>, escolha uma de suas disciplinas</p>

					<select class='select search' id='select-disciplinas' name='disciplina'>
						<?php foreach($disciplinas as $cod=>$nome) echo "<option value='$cod'>$nome</option>"; ?>
					</select>
				</div>
				
				<h2>Enunciado da questão</h2>
				<p>Elabore o texto que compõe a questão</p>
				<textarea class='red-input expand' name="texto"></textarea>

				<h3>Imagem</h3>
				<div class='linha'>
					<p>Caso tenha interesse, envie junto uma imagem que complemente a descrição da questão</p>
					<div id='image-button' class='button-opa'>
						<img class='icon upload' src='icon/upload.png'>
						<img class='icon delete' src='icon/thrash.png'>
						<span class='texto'>Nenhum arquivo selecionado</span>
					</div>
				</div>
				<input type="file" name="imageToUpload" id="imageToUpload" accept=".gif,.jpg,.png,.bmp" hidden>

				<h3>Resolução</h3>
				<div class='linha'>
					<p>Caso possua, você pode enviar a resolução da questão</p>
					<div id='file-button' class='button-opa'>
						<img class='icon upload' src='icon/upload.png'>
						<img class='icon delete' src='icon/thrash.png'>
						<span class='texto'>Nenhum arquivo selecionado</span>
					</div>
				</div>
				<input type="file" name="fileToUpload" id="fileToUpload" hidden>
				
				<h2>Assuntos</h2>
				<p>Selecione os assuntos que melhor identificam a questão</p>
				<div id='divassuntos'></div>
				
				<div id='div-botao'>
					<button id='inserir-assunto' class="button-red">Inserir novo assunto</button>
					<button id='inserir-questao' class="button-red can-disable">Inserir questão</button>
				</div>
			</form>
		</div>
		<div class='credits'>
			<span>© 2020 qstoes.ga</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
		</div>
	</div>
</body>
</html>
