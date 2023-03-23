<?php
	include_once "connection.php";
	session_start();
	if(isset($_SESSION['user'])) {
		$user = $_SESSION['user'];
	}
	
	$codq = $_POST['cod'];

	$sql = "SELECT escolhida FROM questoes WHERE cod = '$codq'";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch();
	$ccod = $row['escolhida'];
	
	$sql = "SELECT * FROM resolucoes WHERE questao = '$codq' ORDER BY FIELD(cod,'$ccod') DESC, votos DESC, envio DESC";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	
	if ($result->rowCount() > 0){
		$msg = "";
		while($row = $result->fetch()){
			$cod = $row['cod'];
			if ($ccod == $cod)
				$chosen = "class='chosen'";
			else
				$chosen = "";
		
			$votos = $row['votos'];
			$arquivo = $row['arquivo'];
			$envio = date_format(date_create($row['envio']), 'd/m/Y  H:i');
			
			$nome = "";
			if ($row['nome'] != "")
				$nome = " por ". $row['nome'];
			
					
			if (file_exists($arquivo)){
				$finfo = finfo_open(FILEINFO_MIME_TYPE);
				$mime = finfo_file($finfo, $arquivo);
				finfo_close($finfo);
				
				if (strstr($mime, "text")){
					$texto = file_get_contents($arquivo);
				}
				elseif (strstr($mime, "image")){
					$texto = "<div class='img-container'><div class='img-resol'><img src='$arquivo'></div></div>";
				}
				else{
					$texto = "<div>Uma prévia deste arquivo não pode ser obtida. Faça o download para visualizá-lo.</div><a class='button-opa' href='$arquivo' download><img class='icon upload' src='icon/download_black.png'><span class='texto'>Baixar resolução</span></a>";
				}
									
				$activeup = "";
				$activedown = "";
				if (isset($_COOKIE["qstoes_resrate$cod"])){
					if ($_COOKIE["qstoes_resrate$cod"] == "up")
						$activeup = " active";
					elseif ($_COOKIE["qstoes_resrate$cod"] == "down")
						$activedown = " active";
				}

				$buttons_professor = "";
				if (isset($user)){
					$buttons_professor = "<div class='button remove-res'><img src='icon/thrash.png' title='Apagar resolução'></div><div class='button choose-res'><img src='icon/check.png' title='Recomendar esta resolução'></div>";
				}
				
				$msg .= "
					<li id='resolution-$cod' $chosen>
						<div class='rate-container'>
							<img class='rate-up$activeup' src='icon/arrow_up.png' title='Esta é uma boa resolução'>
							<div class='rate'>$votos</div>
							<img class='rate-down$activedown' src='icon/arrow_down.png' title='Esta resolução não é boa'>
						</div>
						<div class='buttons-container'>
							<div class='button download-res'>
								<a href='$arquivo' download><img src='icon/download_black.png' title='Download da resolução'></a>
							</div>
							$buttons_professor
						</div>	
						<div class='texto'>$texto</div>
					</li>
					<div class='res-info'>Enviado em $envio $nome</div>
				";
			}
			else
				echo "<h3>O arquivo \"$arquivo\" não foi encontrado.</h3>";
		}
		echo $msg;
	}
	else
		echo "<h3>Ainda não há resoluções submetidas para essa questão.</h3>";
		
	
			
			
?>