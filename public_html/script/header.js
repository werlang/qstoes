var lastScrollTop = 0;
var upscroll = 0;

//recua a header quando for tamanho médio
$(window).scroll(function(event){
    if ($(window).width() >= 600 && $(window).width() < 1200){
        var st = $(this).scrollTop();
        var margin = parseInt($('#header').css('margin-top'));
        //$('#teste').html(st);
        if (st == 0){
            $('#header').css({'margin-top':"0px"});
        }
        else if (st > lastScrollTop && margin > -70){
            $('#header').css({'margin-top':margin - (st - lastScrollTop)/4 + "px"});
            upscroll=0;
        }
        else if (st <= lastScrollTop && margin < 0){
            upscroll += (lastScrollTop - st)/4;
           if (upscroll > 200 || margin > -70)
            if (margin + (lastScrollTop - st)/4 > 0)
                $('#header').css({'margin-top':"0px"});
            else
                $('#header').css({'margin-top':margin + (lastScrollTop - st)/4 + "px"});
        }
        lastScrollTop = st;
    }
});
/*
//redimensiona a tela
$( window ).resize(function() {
    $('#header').removeAttr('style');
    $('#header-toggle').removeAttr('style');
    $('#fog').removeAttr('style');
    $('#login-frame').removeAttr('style');
    $('#pwrong').removeAttr('style');
    $('body').removeAttr('style');
    $('pwrong').removeAttr('style');
});
*/
$(document).ready(function () {
    //manda aparecer login-frame
    $('#login-button').click( function() {
        $('#fog').fadeIn(100);
        //$('body').css({"width":$('body').innerWidth(),"overflow":"hidden"});
        $('#login-frame').fadeIn(300);
        //$('#user').focus();
    });
    
    //some com tudo se clicar em fog
    $('#fog').click( function() {
        $('#fog').removeAttr('style');
        $('#login-frame').removeAttr('style');
        $('body').removeAttr('style');
        $('#pwrong').removeAttr('style');
        $('#header').removeAttr('style');
        $('#header-toggle').removeAttr('style');
    });
    
    //clicou no botao de login
    $('#blogin').click(function(e) {
        //$('#loadfog').show();
        //alert('oi');
        var posting = $.post( "login.php", {user: $('#user').val(), pass: $('#password').val()} );
        posting.done(function( data ) {
            // console.log(data)
            if (data == "errado"){
                $('#pwrong').show();
                $('#pwrong').html("Usuário ou senha não encontrados");
            }
            else{
                if (data == "inativo"){
                    $('#pwrong').show();
                    $('#pwrong').html("A conta ainda não foi ativada");
                }
                else{
                    $('#pwrong').hide();
                    window.location.href = "disciplinas.php";
                }
            }
            enable_button($('#blogin'));
            
        });
        e.preventDefault();
    });
    
    //clicou no botao mobile que mostra o header
    $('#header-toggle').click( function(){
        $(this).css({opacity: '1', backgroundColor: '#d5452f', backgroundImage: 'url(#)'});
        $(this).animate({width: '100%', height: '102px'}, 200, function() {
            $(this).removeAttr('style');
            $(this).hide();
            $('#header').css({"display":"flex"});
            $('#fog').fadeIn(100);
            $('body').css({"overflow":"hidden"});
        });
    } );
    
    //clicou no botao de esqueceu senha
    $('#esqueceu-senha').click( function(){
        var box = "<form><h3>Informe o seu email:</h3><div class='container'><input type='email' class='red-input'><button class='button-red can-disable'>OK</button></div></form>";
        $('#fog').click();
        create_popup(box,"window",400,null);
        $('.window .red-input').focus();
        
        //se clicou no botao de verificar email
        $('.window .button-red').click(function(e){
            var email = $('.window .red-input').val();
            summon_tooltip();
            var posting = $.post( "forgot_pass.php", { email: email });
            posting.done(function( data ) {
                //alert(data);
                if (data == 'not'){
                    summon_tooltip($('.window .red-input'), "down", "Email inválido");
                    $('.window .red-input').val("");
                    $('.window .red-input').focus();
                }
                else if ( data == 'inativo'){
                    $('.popup').click();
                    show_message("O email informado ainda não foi ativado");
                }
                else{
                    $('.popup').click();
                    show_message("Um email com as informações de redefinição de senha foi enviado");
                }
                enable_button($('.window button'));
            });
            e.preventDefault();
        });
    });
});