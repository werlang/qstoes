<?php
	if ($_POST['action'] == "GET"){
		$ck = 700;
		if(isset($_COOKIE['remember-time'])) {
			$ck = $_COOKIE['remember-time'];
			setcookie('remember-time', $ck, time() + (86400 * 30), "/"); // 86400 = 1 day
		}
		echo $ck;
	}
	elseif ($_POST['action'] == "SET"){
		$time = $_POST['time'];
		setcookie('remember-time', $time, time() + (86400 * 30), "/"); // 86400 = 1 day
	}
?>
