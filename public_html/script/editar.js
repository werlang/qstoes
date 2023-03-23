var scroll_state = 0;
var old_src = "";
var texto_original;
var old_res;

$(document).ready ( function(){
	create_select($('#select-disciplinas'));
	create_select($('#select-texto'));
	create_select($('#select-ordem'));
	create_checkbox($('#check-resolucao'));
	
	var reset=false;
	//muda a disciplina
	$('#select-disciplinas').change( function(){
		reset=true;
		$('.e-card-container .item .remove').click();
		$('#campo-busca').val("");
		$('#check-resolucao').prop("checked",false);
		select_index($('#select-texto'), 0);
		select_index($('#select-ordem'), 0);
		$('#div-questoes').html("");
	});
	//muda o tipo de busca de texto
	$('#select-texto').change( function(){
		if ( $(this).val() == 'palavras' )
			$('#campo-busca').attr("placeholder","EX: menu idade pessoas banco");
		if ( $(this).val() == 'exatamente' )
			$('#campo-busca').attr("placeholder","EX: escreva um programa que");
		if ( $(this).val() == 'id' )
			$('#campo-busca').attr("placeholder","EX: 135, 156, 224, 91");
		if (!reset)
			$('#campo-busca').focus();
		reset=false;
	});
	
	//clica nos button-opa
	$('#add-assunto-e').click( function(){
		janela_assuntos($('#div-assuntos-e'), "e")
	});
	$('#add-assunto-ou').click( function(){
		janela_assuntos($('#div-assuntos-ou'), "ou")
	});
	$('#add-assunto-not').click( function(){
		janela_assuntos($('#div-assuntos-not'), "not")
	});
	
	//submit na pesquisa
	$('#bpesquisa').click( function(e) {
		e.preventDefault();
		$('#offset-limit').val("0|10");
		cancela_alteracoes(texto_original, old_src, old_res);

		var fd = new FormData(document.getElementById("formsubmit"));
		$.ajax({
			url: "retrieve_questions.php",
			type: "POST",
			data: fd,
			enctype: 'multipart/form-data',
			processData: false,  // tell jQuery not to process the data
			contentType: false   // tell jQuery not to set contentType
		}).done(function( data ) {
			enable_button( $('#bpesquisa') );
			//alert(data);
			if (data == 'NADA'){
				$('#div-questoes').html("");
				show_message("Nenhuma questão com estes critérios foi encontrada");
			}
			else{
				$('#div-questoes').html(data);

				show_message("Clique em uma das questões para visualizar as opções");
				$('html,body').animate({scrollTop: $('#div-questoes').offset().top - 15 },'slow');

				bind_questoes();
			}
		});
	});
	
	$(window).scroll( function(){
		var obj = $('.rounded-list li.active');
		if (obj.html()){
			if( (obj.offset().top - $(window).scrollTop() > $(window).height()) ||
			(obj.offset().top - $(window).scrollTop() + obj.height() < 0) ){
				cancela_alteracoes(texto_original, old_src, old_res);
			}
		}
		if ($('.rounded-list').length > 0){
			var bottom_list = $('.rounded-list').offset().top + $('.rounded-list').height();
			var bottom_window = $(window).scrollTop() + $(window).height();
			if (bottom_window >= bottom_list && scroll_state == 0){
				append_questoes();
				scroll_state = 1;
			}
		}
		
	});
	
	//clicou no botao de alterar texto
	$('#texto.e-button').click( function(){
		var li = $('.rounded-list li.active');
		texto_original = li.children('.texto').html();
		li.children('.texto').html( "<textarea class='red-input expand' >"+ texto_original +"</textarea>" );
		runtime_expand($('textarea.expand'));
		$("#opcoes").removeClass('visible')
		$("#alteracoes").addClass('visible')
		$("#alteracoes #texto").html("Alterar enunciado");
		$('.red-input.expand').focus();
	});
	//clicou no botao de alterar assuntos
	$('#assuntos.e-button').click( function(){
		janela_assuntos($('.rounded-list li.active .assuntos'), "change")
	});
	//clicou no botao de alterar imagem
	$('#imagem.e-button').click( function(){
		$('.rounded-list li.active .imagem').addClass('selected');
		old_src = $('.rounded-list li.active .imagem .grafico').attr('src');
		if ( $('.rounded-list li.active .imagem').hasClass('hidden') ){
			$('.rounded-list li.active .imagem .icon.delete').hide();
			$('#imageToUpload').click();
		}
		else{
			$("#opcoes").removeClass('visible')
			$("#alteracoes").addClass('visible')
			$("#alteracoes #texto").html("Alterar imagem");
		}
	});
	//clicou no botao de alterar resolucao
	$('#resolucao.e-button').click( function(){
		$('.rounded-list li.active .resolucao').addClass('selected');
		$("#opcoes").removeClass('visible')
		$("#alteracoes").addClass('visible')
		$("#alteracoes #texto").html("Alterar resolução");
	});
	//clicou no botao de apagar questão
	$('#apagar.e-button').click( function(){
		var li = $('.rounded-list li.active');
		$("#opcoes").removeClass('visible')
		$("#alteracoes").addClass('visible')
		$("#alteracoes #texto").html("Apagar questão");
	});
	//clicou no botao de confirmar alteracoes
	$('#sim.e-button').click( function(){
		confirma_alteracoes();
	});
	//clicou no botao de cancelar alteracoes
	$('#nao.e-button').click( function(){
		cancela_alteracoes(texto_original, old_src, old_res);
	});
	
	//escolhe um arquivo de imagem
	$('#imageToUpload').change( function(){
		$('.rounded-list li.active .imagem').removeClass('hidden');
		var reader = new FileReader();
		reader.onload = function (e) {
			$('.rounded-list li.active .imagem .grafico').attr('src', e.target.result);
			$('.rounded-list li.active .imagem').addClass('changed');
			$('.rounded-list li.active .imagem').removeClass('removed');
		}
		reader.readAsDataURL( this.files[0]);
		$("#opcoes").removeClass('visible')
		$("#alteracoes").addClass('visible')
		$("#alteracoes #texto").html("Alterar imagem");
		if (old_src == "")
			$('.rounded-list li.active .imagem .icon.delete').hide();
		else
			$('.rounded-list li.active .imagem .icon.delete').removeAttr('style');
	});
	
	//escolhe um arquivo para resolucao
	$('#fileToUpload').change( function(){
		$('.rounded-list li.active .resolucao').addClass('selected');
		var name = $(this).val().split('\\');
		name = name[name.length-1];
		$('.rounded-list li.active .resolucao.upload').addClass('changed');
		$('.rounded-list li.active .resolucao.upload .texto').html(name);
		$("#opcoes").removeClass('visible');
		$("#alteracoes").addClass('visible');
		$("#alteracoes #texto").html("Enviar resolução");
		if (old_res == "")
			$('.rounded-list li.active .resolucao .icon.delete').hide();
		else
			$('.rounded-list li.active .resolucao .icon.delete').removeAttr('style');
	});
	
});

function bind_questoes(){
	//muda cor das ratings
	$('.container-rating .rating').each( function(){
		if ($(this).html() != '-'){
			if ( $(this).parent().is(':first-child') ){
				var cor = gera_cor((parseInt($(this).html())-1)/4);
			}
			else{
				var cor = gera_cor((5-parseInt($(this).html()))/4);
			}
			$(this).closest('.item').css("background-color", "rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
		}
	});

	//clicou em uma questao
	$('.rounded-list li').click( function(){
		if (!$(this).hasClass('active')){
			cancela_alteracoes(texto_original, old_src, old_res);
			$('.rounded-list li').removeClass('active');
			$(this).addClass('active');
			$('.e-button').removeClass('disabled');
			$("#opcoes").addClass('visible')
		}
	});
	//upload de resolucao
	$('.rounded-list li .resolucao.upload').click( function(){
		if ( $(this).parents('li').hasClass('active') ){
			$('#fileToUpload').click();
		}
	});
	//botao de deletar imagem
	$('.rounded-list li .imagem .icon.delete').click( function() {
		if ( $(this).parents('li').hasClass('active') ){
			if (old_src == "" && !$(this).parents('.imagem').hasClass('changed'))
				old_src = $('.rounded-list li.active .resolucao .grafico').attr('src');
			$('.rounded-list li.active .imagem .grafico').attr('src',old_src);
			$(this).parents('.imagem').removeClass('changed');
			$(this).parents('.imagem').addClass('removed');
			$('#alteracoes #texto').html("Excluir imagem");
			$(this).hide();
		}
	});
	//botao de upload de resolucao
	$('.rounded-list li .imagem .icon.upload').click( function(){
		if ( $(this).parents('li').hasClass('active') ){
			$('#imageToUpload').click();
		}
	});
	
}

function append_questoes(){
	var offset = $('#offset-limit').val().split("|")[0];
	var limit = $('#offset-limit').val().split("|")[1];
	$('#offset-limit').val(parseInt(offset)+parseInt(limit) + "|" + limit);

	var fd = new FormData(document.getElementById("formsubmit"));
	$.ajax({
		url: "retrieve_questions.php",
		type: "POST",
		data: fd,
		enctype: 'multipart/form-data',
		processData: false,  // tell jQuery not to process the data
		contentType: false   // tell jQuery not to set contentType
	}).done(function( data ) {
		if (data != "NADA"){
			$('#div-questoes .rounded-list').append(data);
			scroll_state = 0;
			
			$('.rounded-list li').off();
			bind_questoes();
		}
	});
}

function confirma_alteracoes(){
	var erro=false;
	//confirma alteracoes no texto
	if ( $('.rounded-list li.active textarea').length > 0 ){
		var obj = $('.rounded-list li.active textarea');
		if (obj.val() == ''){
			erro=true;
			summon_tooltip(obj, 'down', "O texto do enunciado precisa ser informado" );
		}
		$('#formupdate #info').val( obj.val() );
		$('#formupdate #field').val("texto");
	}
	//confirma alteracoes nos assuntos
	else if ( $('.rounded-list li.active .assuntos span.added').length + $('.rounded-list li.active .assuntos span.removed').length > 0){
		$('#formupdate #field').val("assuntos");
		var texto = "";
		var first = true;
		$('.rounded-list li.active .assuntos .added').each( function(){
			if (first)
				first = false;
			else
				texto += ',';
			texto += $(this).attr('data-value');
		});
		texto += "|";
		first = true;
		$('.rounded-list li.active .assuntos .removed').each( function(){
			if (first)
				first = false;
			else
				texto += ',';
			texto += $(this).attr('data-value');
		});
		$('#formupdate #info').val(texto);
	}
	//confirma alteracoes na imagem
	else if ( $('.rounded-list li.active .imagem.selected').length > 0 ){
		if ( $('.rounded-list li.active .imagem.removed').length > 0 ){
			$('#formupdate #field').val("remove-imagem");
			$('#formupdate #info').val( $('.rounded-list li.active .imagem .grafico').attr('src') );
		}
		else{
			$('#formupdate #field').val("update-imagem");
		}
	}
	//confirma alteracoes na resolucao
	else if ( $('.rounded-list li.active .resolucao.selected').length > 0 ){
		$('#formupdate #field').val("update-resolucao");
	}
	//confirma apagar questão
	else if ( $("#alteracoes #texto").html() == "Apagar questão" ){
		$('#formupdate #field').val("apagar");
	}
	
	if (!erro){
		$('#formupdate #id').val( $('.rounded-list li.active strong').html().split('#')[1] );
		var fd = new FormData(document.getElementById("formupdate"));
		$.ajax({
			url: "save.php",
			type: "POST",
			data: fd,
			enctype: 'multipart/form-data',
			processData: false,  // tell jQuery not to process the data
			contentType: false   // tell jQuery not to set contentType
		}).done(function( data ) {
			//alert(data);
			var texto = '';
			var src = '';
			var res = '';
			if ( $('#formupdate #field').val() == "apagar" ){
				$('.rounded-list li.active').remove();
				show_message('Questão removida');
				if ($('.rounded-list li').length == 0){
					//$('#editar, #listas, #resolucoes, #denuncias').addClass('desativado');
				}
			}
			else if ($('#formupdate #field').val() == "texto"){
				texto = $('#formupdate #info').val();
			}
			else if ($('#formupdate #field').val() == "assuntos"){
				var obj = $('.rounded-list li.active .assuntos');
				obj.find('.added').removeClass('added');
				obj.find('.removed').remove();
				obj.html( obj.html().replace(", ","") );
				//alert(obj.html());
				obj.html( obj.html().replace("</span><span","</span>, <span") );
			}
			else if ($('#formupdate #field').val() == "remove-resolucao"){
				show_message('Resolução removida');
			}
			else if ($('#formupdate #field').val() == "update-resolucao"){
				show_message('Resolução atualizada');
				res = data.split('/')[1];
			}
			else if ($('#formupdate #field').val() == "remove-imagem"){
				show_message('Imagem removida');
			}
			else if ($('#formupdate #field').val() == "update-imagem"){
				src = data.split('|')[1];
			}
			
			cancela_alteracoes(texto,src,res);
			//$('#formsubmit').submit();
		});
	}	
}

function cancela_alteracoes(texto, src, res){
	//cancela alteracoes no texto
	if ( $('.rounded-list li.active textarea').length > 0 ){
		//var conteudo = $('.rounded-list li.active textarea').val();
		$('.rounded-list li.active > .texto').html( texto );
	}
	//cancela alteracoes nos assuntos
	if ( $('.rounded-list li.active .assuntos span.added').length + $('.rounded-list li.active .assuntos span.removed').length > 0 ){
		var conteudo = $('.rounded-list li.active .assuntos');
		conteudo.find('span.added').remove();
		conteudo.find('span.removed').removeClass('removed');
		conteudo.html(conteudo.html().replace(/, /g, ""));
		conteudo.html(conteudo.html().replace(/<\/span><span/g, "</span>, <span"));
	}
	//cancela alteracoes na imagem
	if ( $('.rounded-list li.active .imagem.selected').length > 0 ){
		$('.rounded-list li.active .imagem .grafico').attr('src',src);
		if (src == "")
			$('.rounded-list li.active .imagem').addClass('hidden');
		$('.rounded-list li.active .imagem').removeClass('changed');
		$('.rounded-list li.active .imagem').removeClass('removed');
		$('.rounded-list li.active .imagem').removeClass('selected');
		$('.rounded-list li.active .imagem .icon.delete').removeAttr('style');
		$('#imageToUpload').val("");
	}
	//cancela alteracoes na resolucao
	if ( $('.rounded-list li.active .resolucao.selected').length > 0 ){
		$('.rounded-list li.active .resolucao.upload .texto').html('Enviar resolução');
		$('.rounded-list li.active .resolucao').removeClass('selected');
		$('.rounded-list li.active .resolucao').removeClass('changed');
		$('#fileToUpload').val("");
	}
	$('.rounded-list li').removeClass('active');
	$(".e-button-container").removeClass('visible')
}

function gera_cor(pos){
	var high = [239,77,77];
	var mid = [234,207,96];
	var low = [129,184,85];
	if (pos < 0.5){
		pos *= 2;
		var dif = [mid[0]-low[0], mid[1]-low[1], mid[2]-low[2]];
		var cor = [Math.round(dif[0]*pos)+low[0], Math.round(dif[1]*pos)+low[1], Math.round(dif[2]*pos)+low[2]];
	}
	else{
		pos = (pos-0.5)*2;
		var dif = [high[0]-mid[0], high[1]-mid[1], high[2]-mid[2]];
		var cor = [Math.round(dif[0]*pos)+mid[0], Math.round(dif[1]*pos)+mid[1], Math.round(dif[2]*pos)+mid[2]];
	}
	return cor;
}

function janela_assuntos(obj, info){
	var box = "<h2>Selecione os assuntos</h2><div id='window-assuntos'></div><button class='button-red can-disable'>Confirmar seleção</button>";
	create_popup(box,"window",400,null);
	//apos conteudo da janela carregado
	var criou = load_assuntos($('#window-assuntos'));
	criou.done( function(){
		$('#window-assuntos').find('input.checkslider').each( function() {
			if (info == 'change'){
				if ( obj.find("span[data-value='"+ $(this).val() +"']").length > 0 )
					$(this).prop("checked",true);
			}
			else{
				if ( obj.find(":input.valor[value='"+ $(this).val() +"']").length > 0 )
					$(this).prop("checked",true);
			}
		});
	});
	//clica no botao de confirmar selecao, dentro da janela
	$('.window .button-red').click(function(e){
		if ( $('.window input.checkslider:checked').length >= 1){
			if (info == 'change'){
				var lista = obj;
				var janela = $('#window-assuntos');
				var conteudo = "<p>Assuntos:</p>";
				janela.find('input.checkslider').each( function(){
					var texto = $(this).parent().text();
					var valor = $(this).val();
					if ( lista.find("span[data-value='"+ valor +"']").length > 0){
						if ($(this).is(':checked'))
							conteudo += "<span data-value='"+ valor +"'>"+ texto +"</span>";
						else
							conteudo += "<span class='removed' data-value='"+ valor +"'>"+ texto +"</span>";
					}
					else if ($(this).is(':checked')){
						conteudo += "<span class='added' data-value='"+ valor +"'>"+ texto +"</span>";
					}
				});
				conteudo = conteudo.replace(/<\/span><span/g, "</span>, <span");
				obj.html(conteudo);
				if ( obj.find("span.added").length + obj.find("span.removed").length > 0 ){
					$("#opcoes").removeClass('visible')
					$("#alteracoes").addClass('visible')
					$("#alteracoes #texto").html("Alterar assuntos");
				}
			}
			else{
				obj.html("");
				$('.window input.checkslider:checked').each( function(){
					var texto = $(this).parent().text();
					var valor = $(this).val();
					obj.html( obj.html() + "<div class='item'><input type='hidden' name='assunto-"+ info +"[]' class='valor' value='"+ valor +"'><div class='texto'>"+ texto +"</div><div class='remove'><img src='icon/x_plain.png'></div></div>");
				});
				//clica no botao de remover e-card do assunto
				$('.e-card-container .item .remove').click( function(){
					if ( obj.find('.item').length == 1 ){
						if (info == 'ou')
							obj.html("<span class='nao-achou'>Todos assuntos selecionados</span>");
						else
							obj.html("<span class='nao-achou'>Nenhum assunto selecionado</span>");
					}
					$(this).parent().remove();
				});
			}
		}
		$('.popup').click();
	});
}

function load_assuntos(result){
	var id = $('#select-disciplinas').val();
	var posting = $.post( "change_assuntos.php", { disciplina: id } );
	posting.done(function( data ) {
		result.html(data);
		result.find('.checkslider').each( function() {
			create_checkbox( $(this) );
		});
	});
	return posting;
}
