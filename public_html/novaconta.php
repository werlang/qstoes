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
	<title>Qstoes - Crição de conta</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/novaconta.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/novaconta.js"></script>
</head>
<body>
	<?php include "header.php"; ?>
	<div id='frame-wrapper'>
		<div id='frame'>
			<form id='formsubmit'>
				<h1>Crie um novo perfil</h1>
				<p>Informe seus dados pessoais:</p>

				<div class='linha'>
					<label for='titulo'>Título de tratamento:</label>
					<input type='text' id='titulo' name='titulo' class='red-input' value='Prof.' placeholder='Prof.' data-tooltip='Caso deseje, informe por qual título deseja ser chamado. EX: Dr., Prof., Me., etc.'>
				</div>

				<div class='linha'>
					<label for='nome'>Nome:</label>
					<input type='text' id='nome' name='nome' class='red-input' placeholder='João' data-tooltip='Informe seu primeiro nome'>
				</div>

				<div class='linha'>
					<label for='sobrenome'>Sobrenome:</label>
					<input type='text' id='sobrenome' name='sobrenome' class='red-input' placeholder='Silva' data-tooltip='Informe seu último nome'>
				</div>

				<div class='linha'>
					<label for='email'>Email:</label>
					<input type='email' id='email' name='email' class='red-input' placeholder='joao.silva@email.com' data-tooltip='Seu email que será usado para realizar o login'>
				</div>

				<div class='linha'>
					<label for='lattes'>Lattes:</label>
					<input type='text' id='lattes' name='lattes' class='red-input' placeholder='AB1C2DE34F' data-tooltip='Informe o código do fim do URL do seu currículo na plataforma Lattes'>
				</div>

				<div class='linha'>
					<label for='instituicao'>Instituição:</label>
					<input type='text' id='instituicao' name='instituicao' class='red-input' placeholder='Universidade Hipotética' data-tooltip='A instituição de ensino você faz parte'>
				</div>
				
				<p>Suas informações de segurança:</p>

				<div class='linha'>
					<label for='new-pass'>Senha:</label>
					<input type='password' class='red-input' id='new-pass' name='new-pass' data-tooltip='Informe a senha que deseja usar. Ela precisa ser composta de pelo menos 6 caracteres, todos alfanuméricos'>
				</div>
				
				<div class='linha'>
					<label for='confirm-pass'>Confirmação de senha:</label>
					<input type='password' class='red-input' id='confirm-pass' name='confirm-pass' data-tooltip='Digite novamente a senha'>
				</div>

				<p>Agora vamos tratar das suas redes sociais. Estes campos são opcionais.</p>

				<div class='linha'>
					<label for='facebook'>Facebook:</label>
					<input type='text' id='facebook' name='facebook' class='red-input' placeholder='face_user' data-tooltip='Seu usuário no facebook. EX: https://www.facebook.com/face_user'>
				</div>

				<div class='linha'>
					<label for='twitter'>Twitter:</label>
					<input type='text' id='twitter' name='twitter' class='red-input' placeholder='twitter_user' data-tooltip='Seu usuário no twitter. EX: https://twitter.com/twitter_user'>
				</div>

				<div class='linha'>
					<label for='linkedin'>LinkedIn:</label>
					<input type='text' id='linkedin' name='linkedin' class='red-input' placeholder='linkedin_user' data-tooltip='Seu usuário no linkedin. EX: https://br.linkedin.com/in/linkedin_user'>
				</div>
				
				<div class='linha' id='div-botao'>
					<button type='submit' class="button-red can-disable" id='bcriar' name='bcriar'>Criar perfil</button>
				</div>
			</form> 
		</div>
		<div class='credits'>
			<span>© 2016 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
		</div>
	</div>
</body>
</html>