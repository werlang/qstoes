<?php
	include_once "connection.php";
	
	$cod = $_POST['id'];
	$field = $_POST['field'];
	
	if ($field == 'texto'){
		$enunciado = mysqli_real_escape_string($conn, $_POST['info']);
		$sql = "UPDATE questoes SET texto = '$enunciado' WHERE cod = '$cod'";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		echo "texto|$enunciado";
	}
	elseif ($field == 'update-imagem'){
		$basename = basename($_FILES["imageToUpload"]["name"]);
		if ($basename != ""){
			$name = explode(".",$basename);
			$extension = $name[count($name)-1];
			$foldername = "questoes-img";
			$imagem = "$foldername/$cod.$extension";
			
			$sql = "UPDATE questoes SET imagem = '$imagem' WHERE cod = '$cod'";
			if(!$result = $conn->query($sql)){
				die('There was an error running the query [' . $conn->error . ']');
			}
			include "file_script.php";
			echo "imagem|$imagem";
		}
	}
	elseif ($field == 'remove-imagem'){
		$imagem = explode("?", $_POST['info'])[0];
		$sql = "UPDATE questoes SET imagem = NULL WHERE cod = '$cod'";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		unlink($imagem);
		echo "imagem|NULL";
	}
	elseif ($field == 'update-resolucao'){
		$basename = basename($_FILES["fileToUpload"]["name"]);
		if ($basename != ""){
			$cod_questao = $cod;
			$name = explode(".",$basename);
			$extension = $name[count($name)-1];
			$foldername = "questoes-res";

			session_start();
			$email = $_SESSION['user'];
			$sql = "SELECT nome, titulo FROM professores WHERE email = '$email'";
			if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
			$row = $result->fetch_assoc();
			$nome = $row['titulo']. " " .$row['nome'];
			
			$sql = "INSERT INTO resolucoes (questao,envio,email,nome) VALUES ('$cod_questao',now(),'$email','$nome')";
			if(!$result = $conn->query($sql)){die('There was an error running the query [' . $conn->error . ']');}
			$cod_resolucao = $conn->insert_id;
			
			$cod = "$cod_questao-$cod_resolucao";
			$resolucao = "$foldername/$cod.$extension";
			$sql = "UPDATE resolucoes SET arquivo = '$resolucao' WHERE cod = '$cod_resolucao'";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			include "file_script.php";
			echo "resolucao|$resolucao";
		}
	}
	elseif ($field == 'remove-resolucao'){
		$sql = "SELECT arquivo FROM resolucoes WHERE cod = '$cod'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		if ($result->num_rows > 0){
			$row = $result->fetch_assoc();
			unlink($row['arquivo']);
			$sql = "DELETE FROM resolucoes WHERE cod = '$cod'";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		}		
		echo "resolucao|NULL";
	}
	elseif ($field == 'apagar'){
		$sql = "DELETE FROM assunto_questao WHERE ce_questao = '$cod'";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		$sql = "DELETE FROM lista_questao WHERE ce_questao = '$cod'";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		$sql = "SELECT arquivo FROM resolucoes WHERE questao = '$cod'";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		if ($result->num_rows > 0){
			while($row = $result->fetch_assoc()){
				if (isset($row['arquivo']))
					unlink($row['arquivo']);
			}
			$sql = "DELETE FROM resolucoes WHERE questao = '$cod'";
			if(!$result = $conn->query($sql)){
				die('There was an error running the query [' . $conn->error . ']');
			}
		}		
		$sql = "SELECT imagem FROM questoes WHERE cod = '$cod'";
		if(!$result = $conn->query($sql)){
			die('There was an error running the query [' . $conn->error . ']');
		}
		if ($result->num_rows > 0){
			$row = $result->fetch_assoc();
			if (isset($row['imagem']))
				unlink($row['imagem']);
			$sql = "DELETE FROM questoes WHERE cod = '$cod'";
			if(!$result = $conn->query($sql)){
				die('There was an error running the query [' . $conn->error . ']');
			}
		}		
		echo "questao|NULL";
	}
	elseif ($field == 'assuntos'){
		$str_add = explode("|", $_POST['info'])[0];
		if (strlen($str_add) > 0)
			$adicionados = explode(",", $str_add);

		$str_rem = explode("|", $_POST['info'])[1];
		if (strlen($str_rem) > 0)
			$removidos = explode(",", $str_rem);
		
		if ( isset($adicionados) ) { 
			$sql = "INSERT INTO assunto_questao (ce_assunto, ce_questao) VALUES ";
			$first = true;
			foreach ($adicionados as $assunto){
				if ($first)
					$first = false;
				else
					$sql .= ",";
				$sql .= "($assunto, $cod)";
			}
			//echo $sql;
			if(!$result = $conn->query($sql)){
				die('There was an error running the query [' . $conn->error . ']');
			}
		}
		
		if ( isset($removidos) ) { 
			$sql = "DELETE FROM assunto_questao WHERE ce_questao = $cod AND ce_assunto IN (";
			$first = true;
			foreach ($removidos as $assunto){
				if ($first)
					$first = false;
				else
					$sql .= ",";
				$sql .= $assunto;
			}
			$sql .= ")";
			//echo $sql;
			if(!$result = $conn->query($sql)){
				die('There was an error running the query [' . $conn->error . ']');
			}
		}
		echo "assuntos";
	}
	
?>