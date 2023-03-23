$(document).ready( function(){
	
	load_lista();

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
				var id = $('.rounded-list li.active .linha strong').html().split("#")[1];
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
				//alert(data);
				$('.popup').click();
				if (data == 'inserido'){
					show_message("A avaliação da questão foi enviada");
				}
				else if (data == 'alterado'){
					show_message("A avaliação da questão foi alterada");
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

$(window).scroll( function(){
	var obj = $('.rounded-list li.active');
	if (obj.html()){
		if( (obj.offset().top - $(window).scrollTop() > $(window).height()) ||
		(obj.offset().top - $(window).scrollTop() + obj.height() < 0) ){
			cancela_alteracoes();
		}
	}
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
			var fd = new FormData(document.getElementById("formsubmit"));
			$.ajax({
				url: "send_resolution.php",
				type: "POST",
				data: fd,
				enctype: 'multipart/form-data',
				processData: false,  // tell jQuery not to process the data
				contentType: false   // tell jQuery not to set contentType
			}).done(function( data ) {
				// console.log(data);
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

function load_lista(){
	var url = window.location.href.split("lista.php?")[1];	
	var posting = $.post( "retrieve_list.php", {
		tipo: url.split("=")[0],
		info: url.split("=")[1]
	});
	posting.done(function( data ) {
		$('#frame').prepend(data);
		
		$(".imagem .grafico[src='']").parents('.imagem').hide();

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
	});

}

function cancela_alteracoes(){
	$('.rounded-list li').removeClass('active');
	$(".e-button-container").removeClass('visible')
}

function gera_cor(pos){
	//pos vai de 0...1
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
