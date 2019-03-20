$(document).ready ( function(){
	create_select($('#select-disciplinas'));
	load_assuntos();
	
	$('.select').change( function() {
		load_assuntos();
	});
	
	//clica no botao de carregar imagem
	$('#image-button').click( function() {
		$('#imageToUpload').click();
	});
	//escolhe um arquivo de imagem
	$('#imageToUpload').change( function(){
		var name = $(this).val().split('\\');
		name = name[name.length-1];
		$('#image-button .texto').html( name );
		$('#image-button .texto').css({'color':"red"});
		$('#image-button .icon.upload').hide();
		$('#image-button .icon.delete').show();
	});

	//clica no icone para deletar imagem
	$('#image-button .icon.delete').click( function(e) {
		e.stopPropagation();
		$('#imageToUpload').val("");
		$('#image-button .texto').html("Nenhum arquivo selecionado");
		$('#image-button .texto').removeAttr('style');
		$('#image-button .icon.upload').removeAttr('style');
		$('#image-button .icon.delete').removeAttr('style');
	});

	//clica no botao de carregar resolucao
	$('#file-button').click( function() {
		$('#fileToUpload').click();
	});
	
	//escolhe um arquivo de resolucao
	$('#fileToUpload').change( function(){
		var name = $(this).val().split('\\');
		name = name[name.length-1];
		$('#file-button .texto').html( name );
		$('#file-button .texto').css({'color':"red"});
		$('#file-button .icon.upload').hide();
		$('#file-button .icon.delete').show();
	});
	
	//clica no icone para deletar resolucao
	$('#file-button .icon.delete').click( function(e) {
		e.stopPropagation();
		$('#fileToUpload').val("");
		$('#file-button .texto').html("Nenhum arquivo selecionado");
		$('#file-button .texto').removeAttr('style');
		$('#file-button .icon.upload').removeAttr('style');
		$('#file-button .icon.delete').removeAttr('style');
	});

	//seleciona arquivo de resolucao
	$('#fileToUpload').change ( function() {
		var size = this.files[0].size;
		if (size > 1048576){
			show_message("Tamanho do arquivo não pode exceder 1MB");
			$('#file-button .icon.delete').click();
		}
	});
	//seleciona arquivo de imagem
	$('#imageToUpload').change ( function() {
		var size = this.files[0].size;
		if (size > 2097152){
			show_message("Tamanho da imagem não pode exceder 2MB");
			$('#image-button .icon.delete').click();
		}
		else{
			var acceptedTypes = ["image/gif", "image/jpeg", "image/png", "image/bmp"];
			if ($.inArray(this.files[0].type, acceptedTypes) == -1) {
				show_message("Arquivo selecionado não é uma imagem");
				$('#image-button .icon.delete').click();
			}			
		}
		
	});

	//clica no botao de inserir novo assunto
	$('#inserir-assunto').click( function(e){
		e.preventDefault();
		var id_disc = $('#select-disciplinas').val();
		var box = "<form><h2>Inserir assunto</h2><p>Informe o nome do novo assunto</p><div class='container'><input type='text' class='red-input'><button type='submit' class='button-red can-disable'>Enviar</button></div></form>";
		create_popup(box,"dialog",400,null);
		$('.dialog .red-input').focus();
		$('.dialog .button-red').click(function(e){
			var nome = $('.dialog .red-input').val();
			var posting = $.post( "insert_tag.php", { disciplina: id_disc, assunto: nome, action:'insert'});
			posting.done(function( data ) {
				if (data == 'vazio' || data == 'existe'){
					if (data == 'vazio')
						summon_tooltip($('.popup input'), 'up', "O nome do assunto precisa ser informado" );
					else
						summon_tooltip($('.popup input'), 'up', "Esta disciplina já possui um assunto com este nome" );
					enable_button($('.popup button'));
					$('.popup input').focus();
				}
				else{
					$('.popup').click();
					show_message(data);
					load_assuntos();
				}
			});
			e.preventDefault();
		});
	});
		
	//clica no botao de inserir questoes
	$('#inserir-questao').click( function(e){
		if ($('textarea.red-input').val() == ""){
			summon_tooltip($('textarea.red-input'), 'down', "O enunciado não foi informado");
			$('textarea.red-input').focus();
			$('textarea.red-input').change( function() {
				summon_tooltip();
			});
			enable_button($('#inserir-questao'));
		}
		else if ( $('#divassuntos .checkslider:checked').length == 0 ){
			if ($('#divassuntos .checkslider').length == 0)
				show_message('Você precisa criar pelo menos um assunto antes.');
			else{
				summon_tooltip($('#divassuntos'), 'up', "Nenhum assunto foi selecionado");
				$('#divassuntos .checkslider').click( function() {
					summon_tooltip();
				});
			}
			enable_button($('#inserir-questao'));
		}
		else{
			$('#formsubmit').submit();
		}
		
		e.preventDefault();
	});
	$('#formsubmit').submit( function(e) {
		var fd = new FormData(document.getElementById("formsubmit"));
		$.ajax({
			url: "insert_question.php",
			type: "POST",
			data: fd,
			enctype: 'multipart/form-data',
			processData: false,  // tell jQuery not to process the data
			contentType: false   // tell jQuery not to set contentType
		}).done(function( data ) {
			//alert(data);
			$('.popup').click();
			enable_button($('#inserir-questao'));
			$('textarea.red-input').val("");
			$('#file-button .icon.delete').click();
			$('#image-button .icon.delete').click();
			$('input.checkslider').prop("checked",false);
			show_message("Questão inserida com sucesso<a href='questao.php?q="+data+"' target='_blank'>Visualizar questão</a>");
			$('#side-menu-list .desativado').removeClass('desativado');
			enable_button($('#inserir-questao'));
		});
		e.preventDefault();
	});
	
	
});

function load_assuntos(){
	var id = $('#select-disciplinas').val();
	var posting = $.post( "change_assuntos.php", {disciplina: id} );
	posting.done(function( data ) {
		$('#divassuntos').html(data);
		$('#divassuntos .assunto').append("<div class='div-icons'><img class='editar' src='icon/edit.png'><img class='apagar' src='icon/thrash.png'></div>");
		$('.checkslider').each( function() {
			create_checkbox( $(this) );
		});
		
		//clicou num icone de editar/apagar
		$('.assunto img').click( function() {
			var id_disc = $('#select-disciplinas').val();
			var id = $(this).parents('.assunto').find('.checkslider').val();
			if ( $(this).hasClass('editar') ){
				var box = "<form><h2>Editar assunto</h2><p>Informe o novo nome para o assunto</p><div class='container'><input type='text' class='red-input'><button type='submit' class='button-red can-disable'>Enviar</button></div></form>";
				create_popup(box,"dialog",400,null);
				$('.dialog .red-input').focus();
				$('.dialog .button-red').click(function(e){
					var nome = $('.dialog .red-input').val();
					var posting = $.post( "insert_tag.php", { disciplina: id_disc, assunto: nome, cod: id, action:'rename'});
					posting.done(function( data ) {
						if (data == 'vazio' || data == 'existe'){
							if (data == 'vazio')
								summon_tooltip($('.popup input'), 'up', "O nome do assunto precisa ser informado" );
							else
								summon_tooltip($('.popup input'), 'up', "Esta disciplina já possui um assunto com este nome" );
							enable_button($('.popup button'));
							$('.popup input').focus();
						}
						else{
							$('.popup').click();
							show_message(data);
							load_assuntos();
						}
					});
					e.preventDefault();
				});
			}
			else if ( $(this).hasClass('apagar') ){
				var nome = $(this).parents('.assunto').find('label').text();
				var box = "<h2>Excluir assunto</h2><p>Deseja realmente remover o assunto <b>"+nome+"</b>?</p><div class='container'><button class='button-red can-disable'>SIM</button><button class='button-red'>NÃO</button></div>";
				create_popup(box,"dialog",400,null);
				$('.dialog .button-red').click(function(e){
					if ($(this).hasClass('can-disable')){
						var posting = $.post( "insert_tag.php", { cod: id, action:'delete'});
						posting.done(function( data ) {
							$('.popup').click();
							show_message(data);
							load_assuntos();
						});
						e.preventDefault();
					}
					else
						$('.popup').click();
				});
			}
		});
	});
}
