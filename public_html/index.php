<?php
	session_start();
	if(isset($_GET['logout']) && $_GET['logout']==1) {
		unset($_SESSION['user']);
		header('location:index.php');
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
	<title>Qstoes</title>
	
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/tables.css'/> 
	<link type='text/css' rel='stylesheet' href='css/index.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/parallax.js"></script>
	<script type="text/javascript" src="script/index.js"></script>
</head>

<body>
	<?php include "header.php"; ?>
	<div class='slide-1'>
		<div class='linha'>
			<div id='intro-msg' class='parallax fade' data-fade0='0' data-fade1='0.2'>
				<h1>Bem-vindo ao Qstoes</h1>
				<p>Uma ferramenta prática, que tem por objetivo auxiliar alunos em seus estudos, e professores no gerenciamento de suas listas de exercícios.</p>
				<p>Como isso é feito? Vamos descobrir...</p>
			</div>
		</div>
	</div>
	<div class='slide-2'>
		<div class='parallax fade' data-fade0='0.9' data-fade1='0.4'>
			<h1>Você é aluno ou professor?</h1>
		</div>
		<div class='linha parallax fade' data-fade0='0.9' data-fade1='0.4'>
			<div id='img-prof' class='parallax move' data-move0x='50' data-move1x='50' data-move0y='100' data-move1y='30'>
				<a class='btn-transp'>Professor</a>
			</div>
			<div id='img-aluno'  class='parallax move' data-move0x='59' data-move1x='59' data-move0y='70' data-move1y='0'>
				<a class='btn-transp'>Aluno</a>
			</div>
		</div>
	</div>

	<div hidden id='click-prof'>
		<div class='slide-3'>
			<div class='linha parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Gerencie seus conteúdos</h2>
					<p>Separe-os por disciplinas, e forneça um link único para seus alunos.</p>
				</div>
				<div class='screenshot'>
					<img src='img/disciplinas_m.png'>
				</div>
			</div>
			<div class='separador left parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Seus alunos sempre terão acesso aos exercícios. Chega de xerox das listas. Quem tiver o link acessa quando e onde quiser.</p>
			</div>
			<div class='linha inv-order parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Classifique exercícios</h2>
					<p>Crie assuntos para compor suas disciplinas, então elabore exercícios, classificando-os de acordo com um ou mais assuntos.</p>	
				</div>
				<div class='screenshot'>
					<img src='img/exercicios_m.png'>
				</div>
			</div>
			<div class='separador right parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Os alunos poderão acessar suas listas e filtrar os exercícios de acordo com os assuntos de maior interesse e/ou necessidade.</p>
			</div>
			<div class='linha parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Respostas à disposição</h2>
					<p>Receba resoluções elaboradas pelos seus alunos, e caso você aprove ela ficará disponível para consulta por todos.</p>	
				</div>
				<div class='screenshot'>
					<img src='img/resolucoes_m.png'>
				</div>
			</div>
			<div class='separador left parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Chega de mercado negro de provas, monopólio das resoluções corretas ou disseminação de respostas erradas. Agora todos tem acesso a tudo.</p>
			</div>
			<div class='linha inv-order parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Organize suas listas</h2>
					<p>Crie e organize listas de exercícios com as questões cadastradas nas suas disciplinas, e forneça o link para seus alunos.</p>	
				</div>
				<div class='screenshot'>
					<img src='img/listas_m.png'>
				</div>
			</div>
			<div class='separador right parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Com as listas, você pode reunir questões específicas para cada uma de suas aulas, listas com exercícios específicos para revisões, ou até mesmo simulados.</p>
			</div>
			
		</div>
		
		<div class='slide-4'>
			<h2>Outras formas de seus alunos colaborar</h2>
			<div class='linha'>
				<div class='e-card'>
					<div class='titulo'>
						<img src='icon/plus.png'>
						<h3>Enviando resoluções</h3>
					</div>
					<p>Seus alunos podem enviar as resoluções deles para o Qstoes, e elas ficarão disponíveis para todos. Eles mesmo votam nas melhores, desta forma fortalecendo seu repertório.</p>
				</div>
				<div class='e-card'>
					<div class='titulo'>
						<img src='icon/exclam.png'>
						<h3>Reportando problemas</h3>
					</div>
					<p>Ninguém melhor que os alunos para encontrar problemas nas suas questões, afinal eles são vários e possuem uma perspectiva única dos problemas.</p>
				</div>
				<div class='e-card'>
					<div class='titulo'>
						<img src='icon/star.png'>
						<h3>Avaliando as questões</h3>
					</div>
					<p>A qualidade e dificuldade das questões pode ajudar outros alunos a encontrar a questão certa para seu nível de conhecimento.</p>
				</div>
			</div>
		</div>
		
		<div class='slide-5'>
			<h1>Junte-se ao Qstoes</h1>
			<p>E descubra uma ferramenta prática de gerenciar seus exercícios e ajudar seus alunos </p>
			<button onclick="location.href='novaconta.php'">Experimente agora, é grátis!</button>
		</div>
	</div>
	<div hidden id='click-aluno'>
		<div class='slide-3'>
			<div class='linha parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Busque exercícios</h2>
					<p>Filtre questões por assuntos, e resolva aquelas que forem do seu interesse ou nível de dificuldade específico.</p>
				</div>
				<div class='screenshot'>
					<img src='img/busca_m.png'>
				</div>
			</div>
			<div class='separador left parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Utilizando o link da disciplina fornecido pelo seu professor, você terá sempre o banco de dados de questões da disciplina à mão. Chega de juntar folhas de papel e gastar com xerox.</p>
			</div>
			<div class='linha inv-order parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Compartilhe resoluções</h2>
					<p>Você pode baixar a resolução dos exercícios. Caso a questão ainda não possua uma disponível, ou a sua resolução for melhor, compartilhe!</p>	
				</div>
				<div class='screenshot'>
					<img src='img/envio_res_m.png'>
				</div>
			</div>
			<div class='separador right parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Não precisa mais pedir para o colega sabe-tudo te dar uma mão. É só baixar pelo link da questão. Todos tem acesso. Quanto mais pessoas compartilharem suas resoluções mais completo ficará o banco de dados da disciplina.</p>
			</div>
			<div class='linha parallax fade' data-fade0='0.8' data-fade1='0.5'>
				<div class='texto'>
					<h2>Avalie questões</h2>
					<p>Você pode classificar cada questão, informando o quão interessante ou bem elaborada achou ela, e também quão difícil ela é em sua opinião.</p>
				</div>
				<div class='screenshot'>
					<img src='img/avaliacao_m.png'>
				</div>
			</div>
			<div class='separador left parallax fade' data-fade0='0' data-fade1='0.5'>
				<p>Achou a questão interessante ou chata? Fácil ou difícil? Opine e ajude o site a clissificá-la melhor. Isto ajudará todos os alunos que estão buscando questões com critérios específicos.</p>
			</div>
		</div>
		
		<div class='slide-4'>
			<h2>Outras características do Qstoes</h2>
			<div class='linha'>
				<div class='e-card'>
					<div class='titulo'>
						<img src='icon/exclam.png'>
						<h3>Denunciar</h3>
					</div>
					<p>Caso a questão possua um problema, for imprópria, repetida ou qualquer outro problema, você pode denunciar ela para chamar a atenção do professor para o problema.</p>
				</div>
				<div class='e-card'>
					<div class='titulo'>
						<img src='icon/link.png'>
						<h3>Compartilhar</h3>
					</div>
					<p>Encontrou uma questão que gostaria de mostrar a algum amigo? Você pode compartilhar a questão utilizando o link direto dela.</p>
				</div>
				<div class='e-card'>
					<div class='titulo'>
						<img src='icon/upload_round.png'>
						<h3>Submeter</h3>
					</div>
					<p>Elabore questões sobre a disciplina, e envie-as para o professor. Caso ele aprove, elas ficarão disponíveis.</p>
				</div>
			</div>
		</div>
		<div class='separador'></div>
		<div class='slide-5'>
			<h1>Seu professor ainda não está no Qstoes?</h1>
			<p>Convide-o para participar, certamente facilitará o trabalho dele, e ajudará os alunos nos estudos.</p>
			<input type='text'  id='nome_aluno' class='red-input' placeholder='Seu nome' />
			<input type='text'  id='nome_prof' class='red-input' placeholder='Nome do professor' />
			<input type='text'  id='email' class='red-input' placeholder='Email do professor' />
			<textarea class='red-input' cols="" rows="5" id="mensagem" placeholder='Mensagem'></textarea>
			<button id='bconvida' class='can-disable'>Convidar</button>
		</div>
		<div class='separador'></div>
		<div class='slide-6'>
			<h1>Está estudando por conta?</h1>
			<p>Então seja bem-vindo e acesse as questões de uma das disciplinas públicas cadastradas.</p>
			<div class='table' id='table-public-disc'>
				<div class='thead'>
					<div class='row'>
						<div class='cell'>Professor</div>
						<div class='cell m-show'>Disciplina</div>
					</div>
				</div>
				<div class='tbody'></div>
			</div>
		</div>

	</div>
	<div class='credits'>
		<span>© 2016 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
	</div>
</body>
</html>