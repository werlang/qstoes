$(document).ready(function () {
	$('.red-input').focusout( function() { summon_tooltip(); });
	$('#formsubmit .red-input').focus( function() {
		if ( !($(this).attr("readonly")) )
			summon_tooltip( $(this), message_pos(), $(this).attr("data-tooltip") );
	});
	
	//clica no botao de alterar email
	$('#alt-email').click(function() {
		var box = "<form><h2>Informe a sua senha</h2><div class='container'><input type='password' class='red-input'><button type='submit' class='button-red can-disable'>Enviar</button></div></form>";
		create_popup(box,"dialog",400,null);
		$('.dialog .red-input').focus();
		$('.dialog .button-red').click(function(e){
			var senha = $('.dialog .red-input').val();
			var email = $('#email').val();
			summon_tooltip();
			var posting = $.post( "check_login.php", { email: email, senha: senha, campo: "email" });
			posting.done(function( data ) {
				//alert(data);
				if (data == 'not'){
					$('.popup').click();
					show_message("Senha incorreta!");
				}
				else{
					$('.popup').click();
					$('#email').attr('readonly',false);
					$('#email').focus();
				}
				enable_button($('.dialog button'));
			});
			e.preventDefault();
		});
	});
	
	//se abriu a pagina e o new-pass ta visivel
	$('#resetpass #new-pass').focus();
	
	//clica em alterar senha
	$('#alt-senha').click(function() {
		var box = "<form><h2>Informe a sua senha</h2><div class='container'><input type='password' class='red-input'><button type='submit' class='button-red can-disable'>Enviar</button></div></form>";
		create_popup(box,"dialog",400,null);
		$('.dialog .red-input').focus();
		$('.dialog .button-red').click(function(e){
			var senha = $('.dialog .red-input').val();
			var email = $('#email').val();
			summon_tooltip();
			var posting = $.post( "check_login.php", { email: email, senha: senha, campo: "senha" });
			posting.done(function( data ) {
				//alert(data);
				if (data == 'not'){
					$('.popup').click();
					show_message("Senha incorreta!");
				}
				else{
					$('.popup').click();
					$('#changepass').show();
					$('#new-pass').focus();
				}
				enable_button($('.dialog button'));
			});
			e.preventDefault();
		});
	});
	
	//clica no botao de salvar alteracoes
	$('#bsalvar').click( function(){
		$('#formsubmit').submit();
	});
	$('#formsubmit').submit( function(e) {
		var fd = new FormData(document.getElementById("formsubmit"));
		$.ajax({
			url: "update_account.php",
			type: "POST",
			data: fd,
			enctype: 'multipart/form-data',
			processData: false,  // tell jQuery not to process the data
			contentType: false   // tell jQuery not to set contentType
		}).done(function( data ) {
			//alert(data);
			var datasplit = data.split("|");
			if (datasplit[1]){
				var obj = $("input[name='"+ datasplit[0] +"']");
				data = datasplit[1];
				obj.focus();
				summon_tooltip(obj,message_pos(),data);
			}
			else{
				if (data != "")
					show_message(data);
				else{
					show_message("Dados atualizados com sucesso");
					$('.popup').click( function(){
						$('#changepass').removeAttr('style');
						$('#email').attr('readonly',true);
					});
				}
			}
			enable_button($('#bsalvar'));
		});
		e.preventDefault();
	});
	
});

function message_pos(){
	return 'up';
}