var reload = false;
var scroll_state = 0;
$(document).ready ( function(){


	create_select($('#select-texto'));
	create_select($('#select-ordem'));
	create_checkbox($('#check-resolucao'));
	
	//muda o tipo de busca de texto
	$('#select-texto').change( function(){
		if ( $(this).val() == 'palavras' )
			$('#campo-busca').attr("placeholder","EX: menu idade pessoas banco");
		if ( $(this).val() == 'exatamente' )
			$('#campo-busca').attr("placeholder","EX: escreva um programa que");
		if ( $(this).val() == 'id' )
			$('#campo-busca').attr("placeholder","EX: 135, 156, 224, 91");
		$('#campo-busca').focus();
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
	$('#bpesquisa').click( function() {
		cancela_alteracoes();
		reload = false;
		scroll_state = 0;
		$('#offset-limit').val("0|10");
		$('#formsubmit').submit();
	});
	$('#formsubmit').submit( function(e) {
		e.preventDefault();
		if (scroll_state == 1){
			var offset = $('#offset-limit').val().split("|")[0];
			var limit = $('#offset-limit').val().split("|")[1];
			$('#offset-limit').val(parseInt(offset)+parseInt(limit) + "|" + limit);
			scroll_state = 2;
		}
		var fd = new FormData(document.getElementById("formsubmit"));
		$.ajax({
			url: "retrieve_questions.php",
			type: "POST",
			data: fd,
			enctype: 'multipart/form-data',
			processData: false,  // tell jQuery not to process the data
			contentType: false   // tell jQuery not to set contentType
		}).done(function( data ) {
			//alert(data);
			enable_button( $('#bpesquisa') );
			if (data == 'NADA' && scroll_state == 0){
				$('#div-questoes').html("");
				show_message("Nenhuma questão com estes critérios foi encontrada");
			}
			else{
				if (scroll_state == 2){
					if (data != "NADA")
						$('#div-questoes .rounded-list').append(data);
					reload = true;
					scroll_state = 1;
				}
				else if (scroll_state == 0) {
					$('#div-questoes').html(data);
				}
				//muda cor das ratings
				$('.container-rating .rating').each( function(){
					if ($(this).html() != '-'){
						if ( $(this).parent().is(':first-child') ){
							var cor = gera_cor((parseInt($(this).html())-1)/4);
						}
						else{
							var cor = gera_cor((5-parseInt($(this).html()))/4);
						}
						$(this).css("background-color", "rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
					}
				});
				if (!reload){
					show_message("Clique em uma das questões para visualizar as opções");
					$('html,body').animate({scrollTop: $('#div-questoes').offset().top - 15 },'slow');
				}

				//clicou em uma questao
				$('.rounded-list li').click( function(){
					if (!$(this).hasClass('active')){
						cancela_alteracoes();
						$('.rounded-list li').removeClass('active');
						$(this).addClass('active');
						$('.e-button').removeClass('disabled');
						$("#opcoes").addClass('visible');
						$('#resolucao img').removeClass('visible');
						if ($(this).find('.code').html() != "")
							$('#opcoes #resolucao .download').addClass('visible');
						else
							$('#opcoes #resolucao .upload').addClass('visible');
					}
				});
			}
		});
	});
	
	$(window).scroll( function(){
		var obj = $('.rounded-list li.active');
		if (obj.html()){
			if( (obj.offset().top - $(window).scrollTop() > $(window).height()) ||
			(obj.offset().top - $(window).scrollTop() + obj.height() < 0) ){
				cancela_alteracoes();
			}
		}
		
		if ($('.rounded-list').length > 0){
			var bottom_list = $('.rounded-list').offset().top + $('.rounded-list').height();
			var bottom_window = $(window).scrollTop() + $(window).height();
			if (bottom_window >= bottom_list && scroll_state < 2){
				scroll_state = 1;
				$('#formsubmit').submit();
			}
		}
	});

	//clica em denuncia
	$('#opcoes #denuncia').click( function(){
		var motivos = "<option value='0'>Conteúdo impróprio ou ofensivo</option><option value='1'>Questão mal formulada ou com erros</option><option value='2'>Questão repetida ou muito semelhante</option><option value='3'>Assuntos incompatíveis aos cadastrados</option><option value='4'>Resolução incorreta ou link quebrado</option><option value='5'>Outros motivos";
		var box = "<h2>Reportar questão</h2><p>Escolha o motivo da denúncia</p><select id='select-motivo' class='select'>"+motivos+"</select><p>Descreva sua denúncia, e caso deseje, identifique-se</p><textarea id='mensagem' name='mensagem' class='red-input' placeholder='Mensagem'></textarea><div class='container'><input type='text' id='nome' name='nome' class='red-input' placeholder='Nome'><input type='text' id='email' name='email' class='red-input' placeholder='Email'></div><div class='container'><button class='button-red can-disable'>Enviar denúncia</button></div>";
		create_popup(box,"dialog",450,null);
		create_select( $('.popup .dialog .select') );
		runtime_expand( $('.popup .dialog textarea') );
		
		$('.popup .dialog .select').change( function(){
			$('.popup .dialog textarea').focus();
		});
		$('.popup .dialog .red-input').change( function(){
			summon_tooltip();
		});
		$('.popup .dialog .button-red').click( function(){
			if ( $('.popup .dialog #mensagem').val() == ""){
				summon_tooltip($('.popup .dialog #mensagem'),'up',"Descreva sua denúncia");
				$('.popup .dialog #mensagem').focus();
				enable_button($('.popup .dialog .button-red'));
			}		
			else if ( $('.popup .dialog #email').val() != "" && !isEmail($('.popup .dialog #email').val()) ){
				summon_tooltip($('.popup .dialog #email'),'up',"Email inválido");
				$('.popup .dialog #email').focus();
				enable_button($('.popup .dialog .button-red'));
			}
			else if ( $('.popup .dialog #email').val() != "" && $('.popup .dialog #nome').val() == "" ){
				summon_tooltip($('.popup .dialog #nome'),'up',"Informe seu nome");
				$('.popup .dialog #nome').focus();
				enable_button($('.popup .dialog .button-red'));
			}
			else{
				var posting = $.post( "send_report.php", {
					mensagem: $('.popup .dialog #mensagem').val(),
					nome: $('.popup .dialog #nome').val(),
					email: $('.popup .dialog #email').val(),
					questao: $('.rounded-list li.active .linha').text().match(/\d+/)[0],
					motivo: $('.popup .dialog #select-motivo').val()
				} );
				posting.done(function( data ) {
					//alert(data);
					$('.popup').click();
					show_message("Denúncia enviada");
				});
			}
		});
		
	});
	
	//clica em resolucao
	$('#opcoes #resolucao').click( function(){
		if (!$(this).hasClass('disabled')){
			
			if ( $('#opcoes #resolucao .upload').hasClass('visible') ){
				send_resolution_box();
			}
			else if ( $('#opcoes #resolucao .download').hasClass('visible') ){
				var hbest = $('.rounded-list li.active .code').html();
				var besttag = "<a id='download' href='"+hbest+"' class='button-red' download>Download da resolução melhor avaliada</a>";
				var hprof = $('.rounded-list li.active .prof').html();
				var proftag = "";
				if (hprof != "")
					proftag = "<a id='dprof' href='"+hprof+"' class='button-red' download>Download da resolução escolhida pelo professor</a>";
				var id = $('.rounded-list li.active strong').html().split('#')[1];
				var box = "<h2>Resolução da questão</h2>"+ besttag + proftag +"<a id='page' href='questao.php?q="+ id +"' class='button-red' target='_blank'>Analisar todas resoluções</a><button id='enviar' class='button-red'>Enviar a sua resolução</button>";
				create_popup(box,"dialog",380,null);
				
				$('.popup .dialog #enviar').click( function() {
					$('.popup').click();
					send_resolution_box();
				});
			}
		}
	});

	//clica em avaliacao
	$('#opcoes #avaliacao').click( function(){
		var dificuldade;
		var elaboracao;
		var posting = $.post( "send_rating.php", {
			questao: $('.rounded-list li.active .linha').text().match(/\d+/)[0]
		} );
		posting.done(function( data ) {
			//alert(data);
			dificuldade = data.split("|")[0]-1;
			elaboracao = data.split("|")[1]-1;
			if (elaboracao != -1)
				seleciona_icone_star($('.popup .dialog .star').eq(0),elaboracao);
			if (elaboracao != -1)
				seleciona_icone_cog($('.popup .dialog .cog').eq(0),dificuldade);
		});
		
		var box = "<h2>Avaliar questão</h2><p>Avalie a questão quanto aos seguintes quesitos</p><div class='box'><h3>Dificuldade</h3><div class='container-rating'><div class='cog'></div><div class='cog'></div><div class='cog'></div><div class='cog'></div><div class='cog'></div><span> Não avaliado</span></div></div><div class='box'><h3>Elaboração</h3><div class='container-rating'><div class='star'></div><div class='star'></div><div class='star'></div><div class='star'></div><div class='star'></div><span>Não avaliado</span></div></div><button id='enviar' class='button-red can-disable'>Avaliar</button>";
		create_popup(box,"dialog",320,null);
		
		//passa o mouse na elaboracao
		$('.popup .dialog .star').hover( function(){
			var n =  $('.popup .dialog .star').index( $(this) );
			seleciona_icone_star($(this),n);
		});
		$('.popup .dialog .star').mouseout( function(){
			$('.popup .dialog .star').removeAttr('style');
			$(this).parent().find('span').html("Não avaliado").removeAttr('style');
			if (elaboracao != -1){
				seleciona_icone_star($(this),elaboracao);
			}
		});
		
		//passa o mouse na dificuldade
		$('.popup .dialog .cog').hover( function(){
			var n =  $('.popup .dialog .cog').index( $(this) );
			seleciona_icone_cog($(this),n);
		});
		$('.popup .dialog .cog').mouseout( function(){
			$('.popup .dialog .cog').removeAttr('style');
			$(this).parent().find('span').html("Não avaliado").removeAttr('style');
			if (dificuldade != -1){
				seleciona_icone_cog($(this),dificuldade);
			}
		});
		
		$('.popup .dialog .star').click( function(){
			elaboracao =  $('.popup .dialog .star').index( $(this) );
		});
		$('.popup .dialog .cog').click( function(){
			dificuldade =  $('.popup .dialog .cog').index( $(this) );
		});
		
		$('.popup .dialog .button-red').click( function(){
			var posting = $.post( "send_rating.php", {
				elaboracao: elaboracao+1,
				dificuldade: dificuldade+1,
				questao: $('.rounded-list li.active .linha').text().match(/\d+/)[0]
			} );
			posting.done(function( data ) {
				$('.popup').click();
				if (data == 'alterado' || data == 'inserido'){
					show_message("A avaliação da questão foi enviada");
					$('#bpesquisa').click();
					reload = true;
				}
			});
		});
	});

	//clica em visualizar link
	$('#opcoes #link').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.rounded-list li.active .linha').text().match(/\d+/)[0];
			var url = "questao.php?q=";
			var box = "<h2>Link da questão</h2><a id='link' href='"+url+id+"' target='_blank'>www.qstoes.tk/questao.php?q="+id+"</a>";
			create_popup(box,"dialog",450,null);
		}
	});

	
});


function send_resolution_box(){
	var id = $('.rounded-list li.active .linha').text().match(/\d+/)[0];
	var box = "<form id='formsubmit'><h2>Enviar resolução</h2><p>Selecione o arquivo que deseja enviar como resolução</p><div class='button-opa'><img class='icon upload' src='icon/upload.png'><span class='texto'>Nenhum arquivo selecionado</span></div><p>Envie junto uma mensagem e seus dados para aparecer na página de resoluções</p><textarea id='mensagem' name='mensagem' class='red-input' placeholder='Mensagem'></textarea><div class='container' ><input type='text' id='nome' name='nome' class='red-input' placeholder='Nome'><input type='text' id='email' name='email' class='red-input' placeholder='Email'></div><div class='container'><button class='button-red can-disable'>Enviar resolução</button></div><input type='file' id='fileToUpload' name='fileToUpload' hidden><input type='hidden' name='cod' value='"+id+"'></form>";
	create_popup(box,"dialog",450,null);
	runtime_expand($('.popup .dialog textarea'));
	
	//clicou no botao de upload de arquivo
	$('.popup .dialog .button-opa').click( function(e){
		$('#fileToUpload').click();
	});
	$('#fileToUpload').change( function(){
		var name = $(this).val().split('\\');
		name = name[name.length-1];
		$('.popup .dialog .button-opa .texto').html( name );
		$('.popup .dialog .button-opa .texto').css({'color':"red"});
		summon_tooltip();
		$('.popup .dialog textarea').focus();
	});
	
	$('.popup .dialog .red-input').change( function(){
		summon_tooltip();
	});

	//clicou no botao de enviar resolucao
	$('.popup .dialog .button-red').click( function(e){
		e.preventDefault();
		$('.popup .dialog #formsubmit').submit();
	});
	$('.popup .dialog #formsubmit').submit( function(e){
		e.preventDefault();
		
		if ( $('#fileToUpload').val() == "" ){
			summon_tooltip($('.popup .dialog .button-opa'),'up',"Selecione um arquivo");
			enable_button($('.popup .dialog .button-red'));
		}
		else if ( $(this).find('#email').val() != "" && !isEmail($(this).find('#email').val()) ){
			summon_tooltip($(this).find('#email'),'up',"Email inválido");
			$(this).find('#email').focus();
			enable_button($('.popup .dialog .button-red'));
		}
		else if ( $(this).find('#email').val() != "" && $(this).find('#nome').val() == "" ){
			summon_tooltip($(this).find('#nome'),'up',"Informe seu nome");
			$(this).find('#nome').focus();
			enable_button($('.popup .dialog .button-red'));
		}
		else{
			var fd = new FormData($(".popup .dialog #formsubmit")[0]);
			$.ajax({
				url: "send_resolution.php",
				type: "POST",
				data: fd,
				enctype: 'multipart/form-data',
				processData: false,  // tell jQuery not to process the data
				contentType: false   // tell jQuery not to set contentType
			}).done(function( data ) {
				//alert(data);
				if (data == "enviado"){
					$('.popup').click();
					show_message("A resolução foi enviada e está aguardando avaliação");
				}
				enable_button($('.popup .dialog .button-red'));
			});
		}
	});
	
}


function isEmail(email) {
	var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
	return regex.test(email);
}

function seleciona_icone_cog(obj,n){
	$('.popup .dialog .cog').removeAttr('style');
	var array_dif = ["Barbada","Fácil","Regular","Difícil","Impossível"];
	var cor = gera_cor(n/4);
	obj.parent().find('span').html(array_dif[n]).css('background-color',"rgba("+cor[0]+","+cor[1]+","+cor[2]+",.3)");
	if (n == -1){
		obj.css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
		obj.prevAll().css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
	}
	else{
		$('.popup .dialog .cog').eq(n).css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
		$('.popup .dialog .cog').eq(n).prevAll().css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
	}
}

function seleciona_icone_star(obj,n){
	$('.popup .dialog .star').removeAttr('style');
	var array_elab = ["Horrível","Ruim","Interessante","Excelente","Genial"];
	var cor = gera_cor((4-n)/4);
	obj.parent().find('span').html(array_elab[n]).css('background-color',"rgba("+cor[0]+","+cor[1]+","+cor[2]+",.3)");
	if (n == -1){
		obj.css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
		obj.prevAll().css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
	}
	else{
		$('.popup .dialog .star').eq(n).css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
		$('.popup .dialog .star').eq(n).prevAll().css('background-color',"rgb("+cor[0]+","+cor[1]+","+cor[2]+")");
	}
}


function cancela_alteracoes(){
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
	var box = "<h2>Selecione os assuntos</h2><div id='window-assuntos'></div><button id='confirma-assuntos' class='button-red can-disable'>Confirmar seleção</button>";
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
	var id = $("input[name='disciplina']").val();
	var posting = $.post( "change_assuntos.php", { disciplina: id } );
	posting.done(function( data ) {
		result.html(data);
		result.find('.checkslider').each( function() {
			create_checkbox( $(this) );
		});
	});
	return posting;
}
