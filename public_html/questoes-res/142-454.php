<html>
<meta charset='utf-8' />
<style>
	div {
		display: inline-block;
		
	}
</style>
<?php
	$q = $_POST['q'];
	$a = $_POST['a'];
	$t1 = $a/$q*100;
	$t2 = 100-$t1;

	echo "<p>Questões acertadas: $a/$q</p>";
	echo "<div style='width:250px; border: 1px solid black; height: 20px'>";

	echo "<div style='width:$t1%; background-color:red; height: 100%'></div>";
	echo "<div style='width:". $t2 ."%; height: 100%'></div>";
	
	echo "</div>";
	$por = round($t1,1);
	echo "<p>Porcentagem de acertos: $por%</p>";
?>

</html>