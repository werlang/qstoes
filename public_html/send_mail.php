<?php
	$host = 'in-v3.mailjet.com';
	$port = '80';

	$sendername = 'Qstoes';
	$senderuser = '3d3198fe000a26c2dfb9656b71063111';
	$senderemail = 'account@qstoes.tk';
	$senderpassword = '2190e217582a90175cb145e0f97bc03a';

	if ($tipo_email == "feedback_submission"){
		$receivername = $nome;
		$receiveremail = $email;
		$assunto = "Respota de $titulo $nome_prof";
		$nome_prof = "$titulo $nome_prof";
		$link = "http://www.qstoes.tk/questao.php?q=$questao";
		
		$doc = new DOMDocument();
		if ($action == 'aceita'){
			$doc->loadHTMLFile("html/feedback_submission_ok.html");
			$altbody = file_get_contents("html/feedback_submission_ok.txt"); 		
		}
		elseif ($action == 'recusa'){
			$doc->loadHTMLFile("html/feedback_submission_fail.html");
			$altbody = file_get_contents("html/feedback_submission_fail.txt"); 		
		}
		$msgbody = $doc->saveHTML();
		
		$msgbody = str_replace("{{var:nome}}",$receivername,$msgbody);
		$msgbody = str_replace("{{var:prof}}",$nome_prof,$msgbody);
		$msgbody = str_replace("{{var:envio}}",$envio,$msgbody);
		$msgbody = str_replace("{{var:mensagem}}",$mensagem,$msgbody);
		$msgbody = str_replace("{{var:link}}",$link,$msgbody);
		$msgbody = str_replace("%7B%7Bvar:link%7D%7D",$link,$msgbody);
		$msgbody = str_replace("{{var:texto}}",$texto,$msgbody);
		
		$altbody = str_replace("{{var:nome}}",$receivername,$altbody);
		$altbody = str_replace("{{var:prof}}",$nome_prof,$altbody);
		$altbody = str_replace("{{var:envio}}",$envio,$altbody);
		$altbody = str_replace("{{var:mensagem}}",$mensagem,$altbody);
		$altbody = str_replace("{{var:link}}",$link,$altbody);
		$altbody = str_replace("{{var:texto}}",$texto,$altbody);
	}
	if ($tipo_email == "feedback_report"){
		$receivername = $nome;
		$receiveremail = $email;
		$assunto = "Respota de $titulo $nome_prof";
		$nome_prof = "$titulo $nome_prof";

		$doc = new DOMDocument();
		$doc->loadHTMLFile("html/feedback_report.html");
		$msgbody = $doc->saveHTML();
		
		$msgbody = str_replace("{{var:nome}}",$receivername,$msgbody);
		$msgbody = str_replace("{{var:prof}}",$nome_prof,$msgbody);
		$msgbody = str_replace("{{var:envio}}",$envio,$msgbody);
		$msgbody = str_replace("{{var:motivo}}",$motivo,$msgbody);		
		$msgbody = str_replace("{{var:mensagem}}",$texto,$msgbody);
		$msgbody = str_replace("{{var:resposta}}",$mensagem,$msgbody);
		
		$altbody = file_get_contents("html/feedback_report.txt"); 		
		$altbody = str_replace("{{var:nome}}",$receivername,$altbody);
		$altbody = str_replace("{{var:prof}}",$nome_prof,$altbody);
		$altbody = str_replace("{{var:envio}}",$envio,$altbody);
		$altbody = str_replace("{{var:motivo}}",$motivo,$altbody);		
		$altbody = str_replace("{{var:mensagem}}",$texto,$altbody);
		$altbody = str_replace("{{var:resposta}}",$mensagem,$altbody);
		
	}
	if ($tipo_email == "feedback_resolution"){
		$receivername = $nome;
		$receiveremail = $email;
		$assunto = "Resposta de $titulo $nome_prof";
		$nome_prof = "$titulo $nome_prof";

		$doc = new DOMDocument();
		$doc->loadHTMLFile("html/feedback_resolution.html");
		$msgbody = $doc->saveHTML();
		
		if ($action == 'aceita')
			$action = "aceitou";
		elseif ($action == 'recusa')
			$action = "recusou";
		$msgbody = str_replace("{{var:nome}}",$receivername,$msgbody);
		$msgbody = str_replace("{{var:prof}}",$nome_prof,$msgbody);
		$msgbody = str_replace("{{var:envio}}",$envio,$msgbody);
		$msgbody = str_replace("{{var:questao}}",$questao,$msgbody);
		$msgbody = str_replace("%7B%7Bvar:questao%7D%7D",$questao,$msgbody);
		$msgbody = str_replace("{{var:status}}",$action,$msgbody);
		$msgbody = str_replace("{{var:mensagem}}",$mensagem,$msgbody);
		
		$altbody = file_get_contents("html/feedback_resolution.txt"); 		
		$altbody = str_replace("{{var:nome}}",$receivername,$altbody);
		$altbody = str_replace("{{var:prof}}",$nome_prof,$altbody);
		$altbody = str_replace("{{var:envio}}",$envio,$altbody);
		$altbody = str_replace("{{var:questao}}",$questao,$altbody);
		$altbody = str_replace("{{var:status}}",$action,$altbody);
		$altbody = str_replace("{{var:mensagem}}",$mensagem,$altbody);
		
	}
	if ($tipo_email == "resetpass"){
		$receivername = "$titulo $nome $sobrenome";
		$receiveremail = $email;
		$assunto  = "Redefinição de senha";

		$doc = new DOMDocument();
		$doc->loadHTMLFile("html/reset_pass.html");
		$msgbody = $doc->saveHTML();
		
		$msgbody = str_replace("{{var:destinatario}}",$receivername,$msgbody);
		$link = "http://www.qstoes.tk/forgot_pass.php?e=$email&a=$strkey";
		$msgbody = str_replace("%7B%7Bvar:link%7D%7D",$link,$msgbody);
		$msgbody = str_replace("{{var:link}}",$link,$msgbody);
		
		$altbody = file_get_contents("html/reset_pass.txt"); 		
		$altbody = str_replace("{{var:destinatario}}",$receivername,$altbody);
		$altbody = str_replace("{{var:link}}",$link,$altbody);
		
	}
	if ($tipo_email == "cadastro"){
		$receivername = "$titulo $nome $sobrenome";
		$receiveremail = $email;
		$assunto  = "Cadastro de conta";

		$doc = new DOMDocument();
		$doc->loadHTMLFile("html/cadastro_msg.html");
		$msgbody = $doc->saveHTML();
		
		$msgbody = str_replace("{{var:destinatario}}",$receivername,$msgbody);
		
		$link = "www.qstoes.tk/create_account.php?e=". $receiveremail ."&a=".$strkey;
		$msgbody = str_replace("%7B%7Bvar:link%7D%7D",$link,$msgbody);
		$msgbody = str_replace("{{var:link}}",$link,$msgbody);

		$altbody = file_get_contents("html/cadastro_msg.txt"); 		
		$altbody = str_replace("{{var:destinatario}}",$receivername,$altbody);
		$altbody = str_replace("{{var:link}}",$link,$altbody);
		
	}
	if ($tipo_email == "convite"){
		$receivername = $nome_prof;
		$receiveremail = $_POST['email'];
		$assunto  = "Convite de ". $nome_aluno;

		$doc = new DOMDocument();
		$doc->loadHTMLFile("html/invite_msg.html");
		$msgbody = $doc->saveHTML();

		$msgbody = str_replace("{{var:nome_prof}}",$receivername,$msgbody);
		$msgbody = str_replace("{{var:nome_aluno}}",$nome_aluno,$msgbody);
		$msgbody = str_replace("{{var:mensagem}}",$mensagem,$msgbody);

		$altbody = file_get_contents("html/invite_msg_text.txt"); 		
		$altbody = str_replace("{{var:nome_prof}}",$receivername,$altbody);
		$altbody = str_replace("{{var:nome_aluno}}",$nome_aluno,$altbody);
		$altbody = str_replace("{{var:mensagem}}",$mensagem,$altbody);
	}
	if (isset($_GET['teste']) && $_GET['teste'] == 'ok'){
		$receivername = "Prof. Pablo";
		$receiveremail = "pswerlang@gmail.com";
		$msgbody = "testbody";
		$assunto  = "subj test";
	}
	/*********************************** A PARTIR DAQUI NAO ALTERAR ************************************/ 
	 
	require_once('PHPMailer-master/PHPMailerAutoload.php');
	 
	$mail = new PHPMailer();
	 
	$mail->IsSMTP();
	$mail->SMTPAuth = true;
	$mail->CharSet = 'UTF-8';
	$mail->Host = $host;
	$mail->Port = $port;
	$mail->Username = $senderuser;
	$mail->Password = $senderpassword;
	$mail->From = $senderemail;
	$mail->FromName = $sendername;
	$mail->IsHTML(true);
	$mail->Subject = $assunto;
	$mail->Body = $msgbody;
	$mail->AltBody = $altbody;
	 
	$mail->AddAddress($receiveremail,utf8_decode($receivername));
	 
	if(!$mail->Send())
		$mensagemRetorno = 'Erro ao enviar formulário: '. print($mail->ErrorInfo);
	else
		$mensagemRetorno = 'Formulário enviado com sucesso!';
	//echo $mensagemRetorno;
?>