<?php
/*
INPUT:
	$_FILES;
	$cod = 190;
	$foldername = "questoes-img";
	include "file_script.php";
OUTPUT:
	$targetfile = "questoes-img/190.c"; //$foldername/.$cod.$ext
	$uploadMsg = "OK";  //"no file"|"OK"|"FAIL"
*/

	$type = explode("-", $foldername)[1];
	if ($type == "res")
		$objname = "fileToUpload";
	elseif ($type == "img")
		$objname = "imageToUpload";
			
	$filepath = pathinfo($_FILES[$objname]["name"]);
	$basename = $filepath['basename'];
	if ($basename == ""){
		$uploadMsg = "no file";
	}
	else{
		$name = $filepath['filename'];
		$ext = $filepath['extension'];
		$targetfile = "$foldername/$cod.$ext";
		
		if (move_uploaded_file($_FILES[$objname]["tmp_name"], $targetfile))
			$uploadMsg = "OK";
		else
			$uploadMsg = "FAIL";
	}

?>