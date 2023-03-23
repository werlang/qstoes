<?php
    include_once "connection.php";
    $user = $_SESSION['user'];
    
    $sem_disciplinas = true;
    $sem_questoes = true;
    
    $sql = "SELECT * FROM professores WHERE email = '$user';";
    $result = $conn->query($sql);
    $row = $result->fetch();
    $titulo = $row['titulo'];
    $nome = $row['nome'];
    $sobrenome = $row['sobrenome'];	
    
    $sql = "SELECT * FROM disciplinas d INNER JOIN professor_disciplina pd ON d.cod = pd.disciplina WHERE pd.professor = '$user';";
    if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
    if ($result->rowCount() > 0){
        $sem_disciplinas = false;
        $sql = "SELECT * FROM questoes WHERE disciplina IN (SELECT d.cod as cod FROM disciplinas d INNER JOIN professor_disciplina pd ON d.cod = pd.disciplina WHERE pd.professor = '$user');";
        if(!$result = $conn->query($sql)){ die('There was an error running the query [' . $conn->error . ']'); }
        if ($result->rowCount() > 0)
            $sem_questoes = false;
    }
    
?>
<link type='text/css' rel='stylesheet' href='css/side_menu.css'/>
<script type="text/javascript" src="script/side_menu.js"></script>
<div id='fog'></div>
<div id='header-toggle'></div>
<div id='side-menu-offset'></div>
<div id='side-menu'>
    <div id='side-menu-header'>
        <?php echo "$titulo $nome $sobrenome"; ?>
    </div>
    <div id='side-menu-list'>
        <a href='profile.php' id='profile'>
            <img src='icon/profile.png'/>
            Alterar perfil
        </a>
        <a href='disciplinas.php' id='disciplinas'>
            <img src='icon/books.png'/>
            Gerenciar disciplinas
        </a>
        <a href='inserir.php' id='inserir' <?php if ($sem_disciplinas) echo "class='desativado'"; ?> >
            <img src='icon/insert.png'/>
            Inserir questões/assuntos
        </a>
        <a href='editar.php' id='editar' <?php if ($sem_questoes) echo "class='desativado'"; ?> >
            <img src='icon/edit.png'/>
            Editar Questões
        </a>
        <a href='listas.php' id='listas' <?php if ($sem_questoes) echo "class='desativado'"; ?> >
            <img src='icon/papers.png'/>
            Gerenciar Listas
        </a>
        <a href='submissoes.php' id='questoes' <?php if ($sem_disciplinas) echo "class='desativado'"; ?> >
            <img src='icon/question.png'/>
            Questões Submetidas
        </a>
        <a href='resolucoes.php' id='resolucoes' <?php if ($sem_questoes) echo "class='desativado'"; ?> >
            <img src='icon/answer.png'/>
            Resoluções Submetidas
        </a>
        <a href='denuncias.php' id='denuncias' <?php if ($sem_questoes) echo "class='desativado'"; ?> >
            <img src='icon/report.png'/>
            Denúncias enviadas
        </a>
        <a href='index.php?logout=1' id='sair'>
            <img src='icon/door.png'/>
            Sair
        </a>
    </div>
    <div id='side-menu-footer'>
        <div class='container'>
        </div>
    </div>
</div>