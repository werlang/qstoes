<?php
	//coloca aqui cada variável recebida do index
	$valor1 = $_POST['valor1'];
	$valor2 = $_POST['valor2'];

		$adicao=$valor1+$valor2;
		$sub=$valor1-$valor2;
		$mult=$valor1*$valor2;
		$div=$valor1/$valor2;	
		echo "Valor 1: $valor1<br/>Valor 2: $valor2<br/>Adicao = $adicao <br>Subtracao = $sub <br> Multiplicacao = $mult<br>Divisao = $div ";
?>