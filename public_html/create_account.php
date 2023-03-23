<?php
	include_once "connection.php";

	$private_key = "7bb483729b5a8e26f73e1831cde5b842";
	$msg = "";
	if (isset($_GET['a']) && isset($_GET['e'])){
		$auth_key = md5($private_key.$_GET['e']);
		if ($auth_key != $_GET['a'])
			header('location:index.php');
		else{
			$e = $_GET['e'];
			$sql = "UPDATE professores SET ativo = 1 WHERE email = '". $e ."';";
			if(!$result = $conn->query($sql)){
				$msg = $conn->error;
				die('There was an error running the query [' . $conn->error . ']');
			}
			session_start();
			$_SESSION['user'] = $e;
			header('location:profile.php');
		}
			
	}
	if ($_POST['email'] == "" || !filter_var($_POST['email'], FILTER_VALIDATE_EMAIL))
		$msg = "email|O email informado não é válido";
	else{
		$email = $_POST['email'];
		$sql = "SELECT * FROM professores WHERE email = '". $email ."';";
		if(!$result = $conn->query($sql)){
			$msg = $conn->error;
			die('There was an error running the query [' . $conn->error . ']');
		}
		$nrows = $result->rowCount();
		$row = $result->fetch();
		if ($nrows != 0 && $row['ativo'] == 1)
			$msg = "email|Este email já possui cadastro";
		else{
			if ($_POST['nome'] == "")
				$msg = "nome|Informe o seu nome";
			else{
				$nome = $_POST['nome'];
				if ($_POST['sobrenome'] == "")
					$msg = "sobrenome|Informe o seu nome";
				else{
					$sobrenome = $_POST['sobrenome'];
					if (strlen(($_POST['lattes'] != 10 && $_POST['lattes']) != 16) || !ctype_alnum($_POST['lattes']))
						$msg = "lattes|O código da plataforma Lattes inserido é inválido";
					else{
						$lattes = $_POST['lattes'];
						if (strlen($_POST['new-pass']) < 6 || !ctype_alnum($_POST['new-pass']))
							$msg = "new-pass|A senha deve ser composta por pelo menos 6 caracteres alfanuméricos";
						else{
							$newpass = $_POST['new-pass'];
							$confirmpass = $_POST['confirm-pass'];
							if ($confirmpass != $newpass)
								$msg = "confirm-pass|A senha e a confirmação são diferentes";
							else{
								$instituicao = $_POST['instituicao'];
								$facebook = $_POST['facebook'];
								$twitter = $_POST['twitter'];
								$linkedin = $_POST['linkedin'];
								$titulo = $_POST['titulo'];
								if ($nrows == 0){
									$sql = "INSERT INTO professores (email,nome,sobrenome,senha,lattes,titulo,instituicao,facebook,twitter,linkedin) VALUES ('$email','$nome','$sobrenome','". md5($newpass) ."','$lattes','$titulo','$instituicao','$facebook','$twitter','$linkedin')";
									if(!$result = $conn->query($sql)){ $msg = $conn->error;  die('There was an error running the query [' . $conn->error . ']'.$nrows); }
								}
								else{
									$sql = "UPDATE professores SET nome = '$nome', sobrenome = '$sobrenome', senha = '". md5($newpass) ."', lattes = '$lattes', titulo = '$titulo', instituicao = '$instituicao', facebook = '$facebook', twitter = '$twitter', linkedin = '$linkedin' WHERE email = '$email';";
									if(!$result = $conn->query($sql)){ $msg = $conn->error;  die('There was an error running the query [' . $conn->error . ']'.$nrows); }
								}
								$msg = "Perfil criado com sucesso. Verifique o email informado para instruções de ativação da conta.";
								$strkey = md5($private_key.$email);
								$tipo_email = "cadastro";
								include "send_mail.php";
							}
						}
					}
				}	
			}
		}
	}
	echo $msg;
?>