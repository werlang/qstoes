<?php
	include_once "connection.php";
	$texto = mysqli_real_escape_string($conn, $_POST['campo-busca']);
	
	$private_key = "a3f05c8283e5350106829f855c93c07d";
	$public_key = $_POST['disciplina'];
	$sql = "SELECT cod FROM disciplinas WHERE md5( concat('$private_key',md5(cod)) ) = '$public_key'";
	if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
	$row = $result->fetch_assoc();
	$disc = $row['cod'];	
	
	if (isset($_POST['assunto-e']))
		$assunto_e = $_POST['assunto-e'];
	if (isset($_POST['assunto-ou']))
		$assunto_ou = $_POST['assunto-ou'];
	if (isset($_POST['assunto-not']))
		$assunto_not = $_POST['assunto-not'];
	$opt = $_POST['opt-texto'];
	$ordem = $_POST['select-ordem'];
	$limit = explode("|",$_POST['limit'])[1];
	$offset = explode("|",$_POST['limit'])[0];
	
	$sql_text="";
	if ($texto != ""){
		if ($opt == "palavras"){
			$texto = iconv('UTF-8', 'ASCII//TRANSLIT', $texto);
			$texto = preg_replace('/[^a-zA-Z0-9 ]/', '', $texto);
			$sql_text = " AND MATCH(q.texto) AGAINST('$texto' WITH QUERY EXPANSION)";
		}
		elseif ($opt == "exatamente"){
			$sql_text = " AND MATCH(q.texto) AGAINST('\"$texto\"' IN BOOLEAN MODE)";
		}
		elseif ($opt == "id"){
			$ids = preg_split("/(, ?#?)|( #?)|(; ?#?)|(#)/", $texto);
			//$ids = explode(" ",$texto);
			$sql_text = " AND q.cod IN (";
			$first = true;
			foreach ($ids as $id){
				if ($first)
					$first = false;
				else
					$sql_text .= ",";
				$sql_text .= "'$id'";
			}
			$sql_text .= ")";
		}
	}
	$sql_resol = "(SELECT arquivo FROM resolucoes WHERE questao = q.cod ORDER BY votos DESC, envio LIMIT 1)";
	$sql_escolhida = "(SELECT arquivo FROM resolucoes WHERE cod = q.escolhida)";
	$sql_show = "SELECT q.cod as cod, q.texto as texto, $sql_resol as resolucao, q.imagem as imagem, $sql_escolhida as escolhida, avg(av.dificuldade) as avg_dif, avg(av.elaboracao) as avg_elab, group_concat(DISTINCT a.nome) as nome, group_concat(aq.ce_assunto) as assunto";
	$sql_from = "FROM questoes q LEFT JOIN avaliacoes av ON av.questao = q.cod INNER JOIN assunto_questao aq ON q.cod = aq.ce_questao INNER JOIN assuntos a ON a.cod = aq.ce_assunto";
	$sql_where = "WHERE q.disciplina = $disc $sql_text";
	$sql_order = "GROUP BY cod";
	if (isset($assunto_e)){
		$cont=0;
		foreach ($assunto_e as $assunto){
			$cont++;
			$sql_from .= " INNER JOIN assunto_questao aq$cont ON q.cod = aq$cont.ce_questao";
			$sql_where .= " AND aq$cont.ce_assunto = $assunto";
		}
	}
	if (isset($assunto_ou)){
		$sql_where .= " AND q.cod IN (SELECT ce_questao FROM assunto_questao WHERE ce_assunto IN (";
		$first = true;
		foreach ($assunto_ou as $assunto){
			if ($first)
				$first = false;
			else
				$sql_where .= ",";
			$sql_where .= "$assunto";
		}
		$sql_where .= "))";
	}
	if (isset($assunto_not)){
		$sql_where .= " AND q.cod NOT IN (SELECT ce_questao FROM assunto_questao WHERE ce_assunto IN (";
		$first = true;
		foreach ($assunto_not as $assunto){
			if ($first)
				$first = false;
			else
				$sql_where .= ",";
			$sql_where .= "$assunto";
		}
		$sql_where .= "))";
	}
	if (isset($_POST['check-resolucao'])){
		$sql_where .= " AND q.resolucao IS NOT NULL";
	}
	if ($ordem == "id"){
		$sql_order .= " ORDER BY q.cod";
	}
	elseif ($ordem == "dif-up"){
		$sql_order .= " ORDER BY avg_dif DESC";
	}
	elseif ($ordem == "dif-down"){
		$sql_order .= " ORDER BY ISNULL(avg(av.dificuldade)), avg_dif";
	}
	elseif ($ordem == "elaboracao"){
		$sql_order .= " ORDER BY avg_elab DESC";
	}
	$sql_order .= " LIMIT $limit OFFSET $offset";
	
	$sql = "$sql_show $sql_from $sql_where $sql_order";
	//echo $sql;
	if(!$result = $conn->query($sql)){
		die('There was an error running the query [' . $conn->error . ']');
	}
	$affected = $conn->affected_rows;
	if ($affected == 0){
		echo 'NADA';
	}
	else {
		if ($offset == 0)
			echo "<ol class='rounded-list'>";
		while($row = $result->fetch_assoc()){
			echo item_lista($row);
		}
		if ($offset == 0)
			echo "</ol>";
	}

function item_lista($row){
	$cod = $row['cod'];
	$dificuldade = $row['avg_dif'];
	$elaboracao = $row['avg_elab'];
	$texto = $row['texto'];
	$imagem = $row['imagem'];
	$a_cod = $row['assunto'];
	$a_nome = $row['nome'];
	
	if (isset($row['resolucao']))
		$resolucao = $row['resolucao'];
	else
		$resolucao = "";

	if (isset($row['escolhida']))
		$escolhida = $row['escolhida'];
	else
		$escolhida = "";

	if (!isset($dificuldade))
		$dificuldade = "-";
	else
		$dificuldade = number_format($dificuldade,1);
	if (!isset($elaboracao))
		$elaboracao = "-";
	else
		$elaboracao = number_format($elaboracao,1);

	$str = "
	<li>
		<div class='linha'>
			<div>Questão <strong>#$cod</strong></div>
			<div class='container-rating'>
				<div class='item'>
					<img src='icon/think_brain.png'>
					<div class='rating'>$dificuldade</div>
				</div>
				<div class='item'>
					<img src='icon/like.png'>
					<div class='rating'>$elaboracao</div>
				</div>
			</div>
		</div>
		<div class='assuntos'>
			<p>Assuntos:</p>
	";
	$assuntos_nome = explode(",",$a_nome);
	$assuntos_cod = explode(",",$a_cod);
	$first = true;
	foreach($assuntos_nome as $i => $assunto){
		$cod_assunto = $assuntos_cod[$i];
		if ($first)
			$first = false;
		else
			$str .= ", ";
		$str .= "<span data-value='$cod_assunto'>$assunto</span>";
	}
	$str .= "
		</div>
		<div class='texto'>$texto</div>
	";
	if (isset($imagem)){
		$r = rand();
		$str .= "
		<div class='imagem'>
			<div class='img-container'>
				<img class='grafico' src='$imagem?d=$r'>
				<img class='icon upload' src='icon/upload.png'>
				<img class='icon delete' src='icon/thrash.png'>
			</div>
		</div>
		";
	}
	else
		$str .= "
		<div class='imagem hidden'>
			<div class='img-container'>
				<img class='grafico' src=''>
				<img class='icon upload' src='icon/upload.png'>
				<img class='icon delete' src='icon/thrash.png'>
			</div>
		</div>
		";
	
	$str .= "
	<div class='resolucao button-opa upload'>
		<span class='texto'>Enviar resolução</span>
	</div>
	<a class='resolucao button-opa' href='questao.php?q=$cod' target='_blank'>
		<span class='texto'>Analisar resoluções</span>
	</a>
	
	<div class='code' hidden>$resolucao</div>
	<div class='prof' hidden>$escolhida</div>
	";
	
	$str .= "
	</li>
	";
	return $str;
}	
?>