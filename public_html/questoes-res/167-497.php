<?php
	$texto = "oi ola tudo oi bem como oi vai";
	$frase = $_GET['f'];
	$afrase = explode(" ",$frase); //array com cada palavra da frase
	
	//a ideia é substituir todas ocorrencias das palavras da frase dentro do texto, pela mesma palavra, mas com uma tag span
	//que possua uma classe css.
	foreach($afrase as $key=>$pfrase){
		$rep = "<span class='ocorrencia$key'>".$pfrase."</span> "; //$rep recebe a palavra com as tags span.
		$texto = str_replace($pfrase,$rep,$texto);//faz a substituição
	}
	echo $texto; //printa o texto
?>
<style>
<?php
	//dentro do css, para cada palavra que a frase contem, gera um rgb aleatório
	//e cria uma classe css com a cor de fundo gerada.
	for ($x=0 ; $x<=count($afrase) ; $x++){
		$r = rand(0,255);
		$g = rand(0,255);
		$b = rand(0,255);
		echo "
		.ocorrencia$x{
			background-color: rgb($r,$g,$b);
		}
		";
	}
?>
</style>
<body>

</body>