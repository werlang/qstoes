<?php
	include_once "connection.php";
	$questao = $_POST['questao'];
	if (isset($_POST['dificuldade']))
		$dificuldade = $_POST['dificuldade'];
	if (isset($_POST['elaboracao']))
		$elaboracao = $_POST['elaboracao'];
	
	//consultando
	if (!isset($dificuldade) && !isset($elaboracao)){
		if (isset($_COOKIE['qstoes_aval'.$questao])){
			$dificuldade = explode("|",$_COOKIE['qstoes_aval'.$questao])[0];
			$elaboracao = explode("|",$_COOKIE['qstoes_aval'.$questao])[1];
			echo "$dificuldade|$elaboracao";
		}
		else
			echo "0|0";
	}
	//enviando
	else{
		if (isset($_COOKIE['qstoes_aval'.$questao])){
			$cod = explode("|",$_COOKIE['qstoes_aval'.$questao])[2];
			
			if ($elaboracao != 0 || $dificuldade != 0){
				if ($elaboracao == 0)
					$sql = "UPDATE avaliacoes SET dificuldade = '$dificuldade', elaboracao = NULL WHERE cod = '$cod'";
				elseif ($dificuldade == 0)
					$sql = "UPDATE avaliacoes SET dificuldade = NULL, elaboracao = '$elaboracao' WHERE cod = '$cod'";
				else
					$sql = "UPDATE avaliacoes SET dificuldade = '$dificuldade', elaboracao = '$elaboracao' WHERE cod = '$cod'";

				if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
			
				$cookie_name = 'qstoes_aval'.$questao;
				$cookie_value = "$dificuldade|$elaboracao|$cod";
				setcookie($cookie_name, $cookie_value, time() + (86400), "/"); // 86400 = 1 day

			}			
			echo "alterado";
		}
		else{
			if ($elaboracao != 0 || $dificuldade != 0){
				if ($elaboracao == 0)
					$sql = "INSERT INTO avaliacoes (questao,dificuldade,elaboracao) VALUES ('$questao','$dificuldade',NULL)";
				elseif ($dificuldade == 0)
					$sql = "INSERT INTO avaliacoes (questao,dificuldade,elaboracao) VALUES ('$questao',NULL,'$elaboracao')";
				else
					$sql = "INSERT INTO avaliacoes (questao,dificuldade,elaboracao) VALUES ('$questao','$dificuldade','$elaboracao')";
				if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
				
				$cookie_cod = $conn->insert_id;
				$cookie_name = 'qstoes_aval'.$questao;
				$cookie_value = "$dificuldade|$elaboracao|$cookie_cod";
				setcookie($cookie_name, $cookie_value, time() + (86400), "/"); // 86400 = 1 day
				
				echo "inserido";
			}
		}
	}
?>