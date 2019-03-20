<?php
	if (isset($_POST['salario'])) {
		$sal = $_POST['salario'];
		$prof = $_POST['profissao'];
		
		//recebe do python dados contendo a média salarial de cada cargo ordenados do menor para maior
		//index do array:
		//cargo => nome do cargo
		//salario => media de salario para o cargo
		$dados = getAvgFromPython();
		
		$i = 0;
		foreach ($dados as $key => $dado){
			if ($dado['salario'] < $sal){
				$i = $key;
				break;
			}
		}
		$dados = array_slice($dados, $i-3, 6);
		

		//recebe do python dados sobre o cargo dado como entrada
		//index do array:
		//max => maior salario para o cargo de entrada
		//min => menor salario para o cargo de entrada
		//avg => média do salario para o cargo de entrada
		$info = getJobInfoFromPython($prof);
		
		echo json_encode(Array('info' => $info, 'data' => $dados));
	}
	elseif (isset($_POST['profissao'])) {
		$prof = $_POST['profissao'];
		if ($prof != "") {
			$json = Array();
			
			//recebe do python uma lista de todos os cargos cadastrados
			$cargos = getJobListFromPython();
			foreach ($cargos as $key => $value) {
				if (stristr($value, $prof) !== false)
					array_push($json, $value);
			}
			echo json_encode($json);
		}
	}
	
	//funcao de exemplo de geração de dados
	function getJobListFromPython(){
		return Array('Professor','Administrativo','Policial','Assistente','Advogado','Militar','Deputado','Juiz','Senador');
	}
	
	//funcao de exemplo de geração de dados
	function getAvgFromPython(){
		$cargos = getJobListFromPython();
		$dados = Array();

		foreach ($cargos as $key => $cargo){
			$linf = 1000 + 1000 * $key;
			$lsup = 5000 + 3000 * $key;
			$dados[$key] = Array('cargo' => $cargos[$key], 'salario' => rand($linf, $lsup));
		}
		
		usort($dados, "cmp");
		
		return $dados;
	}
	
	//funcao de exemplo de geração de dados
	function getJobInfoFromPython($cargo){
		$cargos = array_map('strtolower', getJobListFromPython());
		$dados = Array();

		if (in_array(strtolower($cargo), $cargos)){
			for ($i=0 ; $i < 5000 ; $i++){
				$linf = 1000;
				$lsup = 20000;
				array_push($dados, rand($linf, $lsup));
			}
		}

		$sum = 0;
		$cont = 0;
		$avg = 0;
		$max = false;
		$min = false;
		
		foreach ($dados as $salario) {
			if ($max === false || $salario > $max)
				$max = $salario;
			if ($min === false || $salario < $min)
				$min = $salario;
			$sum += $salario;
			$cont++;
		}
		if ($cont > 0)
			$avg = $sum / $cont;
		
		return Array('max' => $max, 'min' => $min, 'avg' => $avg);
	}
	
	function cmp($a, $b){
		if ($a['salario'] < $b['salario'])
			return 1;
		elseif ($a['salario'] > $b['salario'])
			return -1;
		else
			return 0;
	}
?>