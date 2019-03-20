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
	<title>Qstoes - Lista</title>
	<link type='text/css' rel='stylesheet' href='css/main_stylesheet.css'/> 
	<link type='text/css' rel='stylesheet' href='css/popups.css'/> 
	<link type='text/css' rel='stylesheet' href='css/lists.css'/> 
	<link type='text/css' rel='stylesheet' href='css/buttons.css'/> 
	<link type='text/css' rel='stylesheet' href='css/selects.css'/> 
	<link type='text/css' rel='stylesheet' href='css/inputs.css'/> 
	<link type='text/css' rel='stylesheet' href='css/lista.css'/> 
	<script type="text/javascript" src="script/jquery.min.js"></script>
	<!--<script src="https://authedmine.com/lib/authedmine.min.js"></script>-->
	<script type="text/javascript" src="script/popups.js"></script>
	<script type="text/javascript" src="script/buttons.js"></script>
	<script type="text/javascript" src="script/selects.js"></script>
	<script type="text/javascript" src="script/inputs.js"></script>
	<script type="text/javascript" src="script/lista.js"></script>
</head>


<body>
	<div id="fb-root"></div>
	<script>(function(d, s, id) {
	  var js, fjs = d.getElementsByTagName(s)[0];
	  if (d.getElementById(id)) return;
	  js = d.createElement(s); js.id = id;
	  js.src = "//connect.facebook.net/pt_BR/sdk.js#xfbml=1&version=v2.8";
	  fjs.parentNode.insertBefore(js, fjs);
	}(document, 'script', 'facebook-jssdk'));</script>
	<?php include "header.php"; ?>
	<div id='frame-wrapper'>
		<div id='frame'>
			
			<div id='opcoes' class='linha e-button-container'>
				<div id='denuncia' class='e-button'>
					<img src='icon/exclam.png'>
				</div>
				<div id='resolucao' class='e-button'>
					<img class='download' src='icon/bulb.png'>
					<img class='upload' src='icon/bulb_off.png'>
				</div>
				<div id='avaliacao' class='e-button'>
					<img src='icon/star.png'>
				</div>
				<div id='link' class='e-button'>
					<img src='icon/link.png'>
				</div>
			</div>
			
		</div>
		<div class='credits'>
			<span>© 2016 qstoes.tk</span>-<span>Pablo Werlang</span>-<span><a href='mailto:pswerlang@gmail.com'>pswerlang@gmail.com</a></span>
		</div>
	</div>
</body>
</html>
