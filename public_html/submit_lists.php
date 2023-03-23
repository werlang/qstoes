<?php
	include_once "connection.php";
	session_start();
	$user = $_SESSION['user'];

	if ($_POST['action'] == 'reorder'){
		/*pra arrumar ordenacao
		SET @v = 0;
		UPDATE listas SET ordem = @v := @v + 1 WHERE disciplina = 53;
		*/		
		
		if (!isset($_POST['drop'])){
			$ids = $_POST['id'];
			$orders = $_POST['order'];
			foreach ($ids as $key=>$id){
				$sql = "UPDATE listas SET ordem = $orders[$key] WHERE cod = $id";
				if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			}
		}
		else{
			$drop = $_POST['drop'];
			$id1 = $_POST['id'];
			$order1 = $_POST['order'];
			if ($drop == -1)
				$order2 = $order1 - 1;
			elseif ($drop == 1)
				$order2 = $order1 + 1;
			$sql = "SELECT cod FROM listas WHERE ordem = $order2";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			$row = $result->fetch();
			$id2 = $row['cod'];	
			
			$sql = "UPDATE listas SET ordem = $order2 WHERE cod = $id1";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			$sql = "UPDATE listas SET ordem = $order1 WHERE cod = $id2";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			
			//echo $id1." ".$order1."\n".$id2." ".$order2."\n";
		}
		
		echo "ordenado";
	}
	else{	
		$private_key = "a3f05c8283e5350106829f855c93c07d";
		$public_key = $_POST['disciplina'];
		$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
		if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
		$row = $result->fetch();
		$disciplina = $row['cod'];	
		$info = $_POST['info'];
		
		if ($_POST['action'] == 'insert'){
			$nome = $info[0];
			$descricao = $info[1];
			$questoes = $_POST['questoes'];
			
			$sql = "SELECT count(*) FROM listas WHERE disciplina = $disciplina";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			$row = $result->fetch();
			$linha = $row['count(*)'] + 1;	

			$sql = "INSERT INTO listas (nome, descricao, disciplina, ordem) VALUES ('$nome','$descricao','$disciplina','$linha');";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			
			$cod = $conn->lastInsertId();
			$sql = "INSERT INTO lista_questao (ce_lista, ordem, ce_questao) VALUES ";
			$first = true;
			$ordem = 1;
			foreach ($questoes as $questao){
				$questao = explode("|",$questao)[1];
				if ($first)
					$first = false;
				else
					$sql .= ",";
				$sql .= "($cod, $ordem, $questao)";
				$ordem++;
			}
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }

			echo "inserido";
		}
		elseif ($_POST['action'] == 'rename'){
			$nome = $info[0];
			$descricao = $info[1];
			$cod = $info[2];

			$sql = "UPDATE listas SET nome = '$nome', descricao = '$descricao' WHERE cod = $cod";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			//echo $sql;

			if (isset($_POST['questoes'])){
				$questoes = $_POST['questoes'];
				$questoes_add = array();
				$questoes_del = array();
				$questoes_upd = array();
				$newi=0;
				foreach ($questoes as $questao){
					$op = explode("|",$questao)[0];
					$num = explode("|",$questao)[1];
					if ($op == "d")
						array_push($questoes_del,$num);
					else{
						$newi++;
						if ($op == "u")
							$questoes_upd[$newi] = $num;
						elseif ($op == "i")
							$questoes_add[$newi] = $num;
					}
				}

				if (count($questoes_add) > 0){
					$sql = "INSERT INTO lista_questao (ce_lista, ordem,  ce_questao) VALUES ";
					$first = true;
					foreach ($questoes_add as $ordem => $questao){
						if ($first)
							$first = false;
						else
							$sql .= ",";
						$sql .= "($cod, $ordem, $questao)";
					}
					if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
					//echo $sql;
				}
				
				if (count($questoes_upd) > 0){
					foreach ($questoes_upd as $ordem => $questao){
						$sql = "UPDATE lista_questao SET ordem = $ordem WHERE ce_lista = $cod AND ce_questao = $questao";
						if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
						//echo $sql;
					}
				}

				if (count($questoes_del) > 0){
					$sql = "DELETE FROM lista_questao WHERE ce_lista = $cod AND ce_questao IN (";
					$first = true;
					foreach ($questoes_del as $questao){
						if ($first)
							$first = false;
						else
							$sql .= ",";
						$sql .= $questao;
					}
					$sql .= ")";
					if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
					//echo $sql;
				}
			}

			echo "renomeado";
		}
		elseif ($_POST['action'] == 'delete'){
			$cod = $info;

			$sql = "DELETE FROM lista_questao WHERE ce_lista = $cod";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			
			$sql = "DELETE FROM listas WHERE cod = $cod";
			if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
			
			echo "deletado";
		}
	}
?>