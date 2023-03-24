<?php
    include_once "connection.php";

    session_start();
    if((!isset ($_SESSION['user']) == true)) {
        unset($_SESSION['user']);
        header('location:index.php');
    }
    $user = $_SESSION['user'];

    $titulo = $_POST['titulo'];
    $email = $_POST['email'];
    $instituicao = $_POST['instituicao'];
    // $facebook = $_POST['facebook'] || "";
    // $twitter = $_POST['twitter'] || "";
    // $linkedin = $_POST['linkedin'] || "";
    $newpass = $_POST['new-pass'];
    $confirmpass = $_POST['confirm-pass'];
    
    $msg = "";
    
    if ( isset($_SESSION['changeemail']) ){
        if (!filter_var($email, FILTER_VALIDATE_EMAIL))
            $msg = "email|O email informado não é válido";
        else{
            $sql = "SELECT * FROM professores WHERE email = '$email';";
            if(!$result = $conn->query($sql)){
                $msg = $conn->error;
                die('There was an error running the query [' . $conn->error . ']');
            }
            $nrows = $result->rowCount();
            if ($nrows != 0 && $email != $user)
                $msg = "email|Este email já possui cadastro";
        }
    }
    if ( isset($_SESSION['changepass']) || isset($_SESSION['resetpass'])){
        if (strlen($newpass) < 6)
            $msg = "new-pass|A nova senha deve conter pelo menos 6 caracteres";
        elseif (!ctype_alnum($newpass))
            $msg = "new-pass|A senha precisa conter somente letras e/ou números sem acentos";
        elseif ($confirmpass != $newpass)
            $msg = "new-pass|A nova senha e a confirmação são diferentes";
    }
    
    if ($msg == ""){
        $sql = "UPDATE professores SET ";
        
        if ( isset($_SESSION['changeemail']) ){
            $sql .= "email = '$email', ";
            unset($_SESSION['changeemail']);
            
            $sql2 = "UPDATE disciplinas SET professor = '$email' WHERE professor = '$user';";
            if(!$result = $conn->query($sql2)){
                $msg = $conn->error;
                die('There was an error running the query [' . $conn->error . ']');
            }
            $_SESSION['user'] = $email;
        }
        
        if ( isset($_SESSION['changepass']) || isset($_SESSION['resetpass']) ){
            $sql .= "senha = '". md5($newpass) ."', ";
            unset($_SESSION['changepass']);
            unset($_SESSION['resetpass']);
        }
        
        $sql .= "titulo = '$titulo', instituicao = '$instituicao' WHERE email = '$user';";
        // $sql .= "titulo = '$titulo', facebook = '$facebook', twitter = '$twitter', linkedin = '$linkedin', instituicao = '$instituicao' WHERE email = '$user';";
        if(!$result = $conn->query($sql)){ 
            $msg = $conn->error;
            die('There was an error running the query [' . $conn->error . ']'); 
        }
    }
    echo $msg;
?>