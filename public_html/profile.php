<?php
	include_once "connection.php";
	session_start();
	if(!isset ($_SESSION['user'])) {
		unset($_SESSION['user']);
		header('location:index.php');
	}
	$resetpass = false;
	unset($_SESSION['changeemail']);
	unset($_SESSION['changepass']);
	if (isset($_SESSION['resetpass'])){
		unset($_SESSION['resetpass']);
		$resetpass = true;
	}

	$sql = "SELECT * FROM professores WHERE email = '". $_SESSION['user'] ."';";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch_assoc();

	$titulo = $row['titulo'];
	$nome = $row['nome'];
	$sobrenome = $row['sobrenome'];
	$email = $row['email'];
	$lattes = $row['lattes'];
	$facebook = $row['facebook'];
	$twitter = $row['twitter'];
	$linkedin = $row['linkedin'];
	$instituicao = $row['instituicao'];
	
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8' />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="icon" type="image/gif" href="icon/qstoes_icon.png" />
	<title>Qstoes - Perfil do professor</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/profile.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/profile.js"></script>
</head>
<body>
	<?php include "side_menu.php"; ?>
	<div id='frame-wrapper'>
		<div id='frame'>
			<form id='formsubmit'>
				<h1>Alterar perfil</h1>

				<div class='linha'>
					<label for='titulo'>Título de tratamento:</label>
					<input type='text' id='titulo' name='titulo' class='red-input' placeholder='Prof.' value='<?php echo $titulo; ?>'  data-tooltip='Caso deseje, informe por qual título deseja ser chamado. EX: Dr., Prof., Me., etc.'>
				</div>
						
				<div class='linha'>
					<label for='nome'>Nome:</label>
					<input type='text' id='nome' name='nome' class='red-input' placeholder='João' value='<?php echo $nome; ?>' readonly>
				</div>
				
				<div class='linha'>
					<label for='sobrenome'>Sobrenome:</label>
					<input type='text' id='sobrenome' name='sobrenome' class='red-input' placeholder='Silva' value='<?php echo $sobrenome; ?>' readonly>
				</div>

				<div class='linha'>
					<label for='email'>Email:</label>
					<input type='email' id='email' name='email' class='red-input' placeholder='joao.silva@email.com' value='<?php echo $email; ?>' data-tooltip='Seu email será usado para realizar o login' readonly>
				</div>

				<div class='linha'>
					<label for='lattes'>Lattes:</label>
					<input type='text' id='lattes' name='lattes' class='red-input' placeholder='AB1C2DE34F' value='<?php echo $lattes; ?>' readonly>
				</div>

				<div class='linha'>
					<label for='instituicao'>Instituição:</label>
					<input type='text' id='instituicao' name='instituicao' class='red-input' placeholder='Universidade Hipotética' value='<?php echo $instituicao; ?>' data-tooltip='A instituição de ensino você faz parte'>
				</div>
				
				<div class='linha'>
					<label for='facebook'>Facebook:</label>
					<input type='text' id='facebook' name='facebook' class='red-input' placeholder='face_user' value='<?php echo $facebook; ?>' data-tooltip='Seu usuário no facebook. EX: https://www.facebook.com/face_user'>
				</div>

				<div class='linha'>
					<label for='twitter'>Twitter:</label>
					<input type='text' id='twitter' name='twitter' class='red-input' placeholder='twitter_user' value='<?php echo $twitter; ?>' data-tooltip='Seu usuário no twitter. EX: https://twitter.com/twitter_user'>
				</div>

				<div class='linha'>
					<label for='linkedin'>LinkedIn:</label>
					<input type='text' id='linkedin' name='linkedin' class='red-input' placeholder='linkedin_user' value='<?php echo $linkedin; ?>' data-tooltip='Seu usuário no linkedin. EX: https://br.linkedin.com/in/linkedin_user'>
				</div>
				
				<div id='changepass' <?php if (!$resetpass) echo "hidden"; ?> >
					<div class='linha'>
						<label for='new-pass'>Nova senha:</label>
						<input type='password' class='red-input' id='new-pass' name='new-pass' data-tooltip='Informe a senha que deseja usar. Ela precisa ser composta de pelo menos 6 caracteres, todos alfanuméricos'>
					</div>
					
					<div class='linha'>
						<label for='confirm-pass'>Confirmação de senha:</label>
						<input type='password' class='red-input' id='confirm-pass' name='confirm-pass' data-tooltip='Digite novamente a senha'>
					</div>			
				</div>

				<h2>Outras ações</h2>
				<div id='opcoes' class='linha'>
					<div id='alt-senha' class='button-opa'>
						<img class='icon' src='icon/key.png'>
						<span class='texto'>Alterar Senha</span>
					</div>
					<div id='alt-email' class='button-opa'>
						<img class='icon' src='icon/message.png'>
						<span class='texto'>Alterar Email</span>
					</div>
				</div>
							
				<div id='div-botao' class='linha'>
					<button type='submit' class="button-red can-disable" id='bsalvar' name='bsalvar'>Salvar alterações</button>
				</div>
			</form>
		</div>
		<div class='credits'>
			<span>© 2016 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
		</div>
	</div>
</body>
</html>