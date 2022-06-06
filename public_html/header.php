<link type='text/css' rel='stylesheet' href='css/header.css'/> 
<script type="text/javascript" src="script/header.js"></script>
<div id='header-toggle'></div>
<div id='header'>
	<div id='logo'>
		<a href='index.php'>
			<img src='icon/qstoes_logo.png' />
		</a>
	</div>
	<div id='contato'>
		<a target='_blank' href='mailto:contato@qstoes.tk'><img src='icon/gmail.png'/></a>
		<a target='_blank' href='https://www.facebook.com/qstoes/'><img src='icon/facebook2.png'/></a>
		<a target='_blank' href='https://twitter.com/qstoes'><img src='icon/twitter.png'/></a>
	</div>
	<div id='login-div'>
		<a id='login-button' >
			<img src='icon/professor.png'/>
			<p><span>LOGIN</span> como professor</p>
		</a>
	</div>
</div>
<div id='fog'></div>
<div id='login-frame'>
	<form>
		<h2>Login</h2>
		
		<label>Email:</label>
		<input type='email' class='red-input' id='user'>
		
		<label>Senha:</label>
		<input type='password' class='red-input' id='password'>
		
		<p id='pwrong'>Usuário ou senha não encontrados</p>
		<div class='container'>
			<button class="button-red can-disable" id='blogin'>Entrar</button>
			<div id='links'>
				<a id='esqueceu-senha'>Esqueci minha senha</a>
				<a href='novaconta.php'>Criar nova conta</a>
			</div>
		</div>
	</form>
</div>
