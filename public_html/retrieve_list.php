<?php
    include_once "connection.php";
    $tipo = $_POST['tipo'];
    $info = $_POST['info'];

    if ($tipo == 'q'){
        $info = str_replace("%2C", ",", $info);
        $array_cod = explode(",",$info);
        $string_cod = "'" . implode("','",$array_cod) . "'";
        $sql = "SELECT q.cod, q.texto, q.imagem, avg(av.dificuldade) as avg_dif, avg(av.elaboracao) as avg_elab, group_concat(a.nome) as assuntos FROM questoes q LEFT JOIN avaliacoes av ON av.questao = q.cod  INNER JOIN assunto_questao aq ON q.cod = aq.ce_questao INNER JOIN assuntos a ON a.cod = aq.ce_assunto WHERE q.cod IN ($string_cod) GROUP BY q.cod";
    }
    elseif ($tipo == 'l'){
        $private_key = "af0d6a3af83fd3f7db47d068b3c7bc5a";
        $sql = "SELECT cod, nome FROM listas WHERE md5(concat('$private_key',md5(cod))) = '$info'";
        if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
        if ($result->rowCount() > 0){
            $row = $result->fetch();
            $cod_lista = $row['cod'];
            $nome_lista = $row['nome'];

            $sql = "SELECT q.cod, q.texto, q.imagem, (SELECT arquivo FROM resolucoes WHERE cod = q.escolhida) as escolhida, avg(av.dificuldade) as avg_dif, avg(av.elaboracao) as avg_elab, group_concat(DISTINCT a.nome) as assuntos FROM questoes q LEFT JOIN avaliacoes av ON av.questao = q.cod  INNER JOIN assunto_questao aq ON q.cod = aq.ce_questao INNER JOIN assuntos a ON a.cod = aq.ce_assunto INNER JOIN lista_questao lq ON lq.ce_questao = q.cod WHERE lq.ce_lista = $cod_lista GROUP BY q.cod ORDER BY lq.ordem, lq.cod";
            //$sql = "SELECT q.cod, q.texto, q.imagem, avg(av.dificuldade) as avg_dif, avg(av.elaboracao) as avg_elab FROM questoes q LEFT JOIN avaliacoes av ON av.questao = q.cod  INNER JOIN assunto_questao aq ON q.cod = aq.ce_questao INNER JOIN assuntos a ON a.cod = aq.ce_assunto INNER JOIN lista_questao lq ON lq.ce_questao = q.cod WHERE lq.ce_lista = $cod_lista GROUP BY q.cod ORDER BY lq.cod";
        }
        //echo $sql;
    }
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
    
    if ($result->rowCount() > 0){
        if (!isset($nome_lista))
            $nome_lista = "";
        $link = "http://qstoes.tk/lista.php?$tipo=$info";
        $msg = "
            <div id='container-titulo'>
                <h1>$nome_lista</h1>
            </div>
            <ol class='rounded-list'>
        ";
        while($row = $result->fetch()){
            $cod = $row['cod'];
        
            $texto = $row['texto'];
            
            $escolhida = $row['escolhida'];
            
            $assuntos = $row['assuntos'];
            $assuntos = str_replace(",",", ",$assuntos);
            
            $sql2 = "SELECT arquivo FROM resolucoes WHERE questao = '$cod' ORDER BY votos DESC, envio LIMIT 1";
            if(!$result2 = $conn->query($sql2)){ die('There was an error running the query [' . $conn->error . ']'); }
            $row2 = $result2->fetch();
            $resolucao = isset($row2['arquivo']) ? $row2['arquivo'] : "";
            
            $imagem = $row['imagem'];
            if (isset($imagem))
                $imagem .= "?d=".rand();
            
            $dificuldade = $row['avg_dif'];
            $elaboracao = $row['avg_elab'];
            if (!isset($dificuldade))
                $dificuldade = "-";
            else
                $dificuldade = number_format($dificuldade,1);

            if (!isset($elaboracao))
                $elaboracao = "-";
            else
                $elaboracao = number_format($elaboracao,1);
            
            $msg .= "
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
                        <div class='bullet'><img src='icon/ellipsis.png'></div>
                    </div>
                </div>
                <div class='assuntos'>
                    <p>Assuntos:</p>
                    <span>$assuntos</span>
                </div>
                <div class='texto'>$texto</div>
                <div class='imagem'>
                    <div class='img-container'>
                        <img class='grafico' src='$imagem'>
                    </div>
                </div>
                <div class='code' hidden>$resolucao</div>
                <div class='prof' hidden>$escolhida</div>
            </li>
            ";
        }
        $msg .= "</ol>";
        echo $msg;
    }
    else
        echo "<h2>Lista não encontrada</h2>"
        
    
            
            
?>