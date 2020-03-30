function load_table(){
	//carrega tabela no inicio
	if ($(window).width() < 600)
		var limit = 5;
	else
		var limit = 10;
	var offset = $('#container-pages').attr('data-offset');
	var posting = $.post( "disciplines_table.php", {limit: limit, offset: offset} );
	posting.done(function( data ) {
		$('.table .tbody').html(data);
		
		//clicou em uma linha da tabela
		$('.table .tbody .row').click(function(){
			var tempo = 300;
			if ($(window).width() >= 600)
				tempo = 0;
			var selected=false;
			if (!$(this).hasClass('selected'))
				selected=true;

			//remove selected de todos
			var obj = $('.table .row.selected');
			var hi = obj.outerHeight();
			obj.removeClass('selected');
			var hf = obj.outerHeight();
			obj.addClass('selected');
			obj.height(hi);
			obj.animate({ height: hf, }, tempo, function(){
				obj.removeAttr('style');
				obj.removeClass('selected');
				$('#editar, #remover, #visualizar').addClass('disabled');
			});
			
			//adiciona selected no clicado
			if (selected){
				var hi = $(this).outerHeight();
				$(this).addClass('selected');
				var hf = $(this).outerHeight();
				$(this).height(hi);
				$(this).animate({ height: hf, }, tempo, function(){
					$(this).removeAttr('style');
					$('#editar, #remover, #visualizar').removeClass('disabled');
				});
			}
			$('.table .tbody .row .cell').removeAttr("data-head");
			var i=1;
			$('.table .thead .cell').each( function(){
				$('.table .tbody .row.selected .cell:not(.m-show):nth-child('+i+')').attr("data-head",$(this).html());
				i++;
			});
		});
		
		//clicou no botao de pagina anterior
		$('#container-pages #prev').click( function() {
			var offset = parseInt($('#container-pages').attr('data-offset'));
			offset -= limit;
			if (offset < 0)
				offset = 0;
			$('#container-pages').attr('data-offset',offset);
			load_table();
		});
		//clicou no botao de proxima pagina
		$('#container-pages #next').click( function() {
			var offset = parseInt($('#container-pages').attr('data-offset'));
			var nrows = $('#container-pages').attr('data-nrows');
			offset += limit;
			//alert(offset);
			if (offset > nrows-limit)
				offset = nrows-limit;
			$('#container-pages').attr('data-offset',offset);
			load_table();
		});
		
	});
}

$(document).ready( function() {
	load_table();
	corta_nome();
		
	//clicou em remover disciplina
	$('#opcoes #remover').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.table .row.selected').attr('id');
			var nome = $($('.table .row.selected .cell').get(0)).html();
			var box = "<h2>Remover disciplina</h2><p>Deseja realmente excluir a disciplina <b>"+nome+"</b>?</p><div class='container'><button class='button-red can-disable'>SIM</button><button class='button-red'>NÃO</button></div>";
			create_popup(box,"dialog",400,null);
			$('.dialog .button-red').click(function(e){
				if ($(this).hasClass('can-disable'))
					submit_discipline('delete',id);
				else
					$('.popup').click();
			});
		}
	});

	//clicou em adicionar disciplina
	$('#opcoes #adicionar').click( function(){
		$('.table .row').removeClass('selected');
		$('#editar, #remover, #visualizar').addClass('disabled');
		var box = "<form><h2>Adicionar disciplina</h2><p>Informe o nome da disciplina</p><input type='text' class='red-input'><div class='container'><label><input type='checkbox' class='checkslider'>Disciplina pública</label><button type='submit' class='button-red can-disable'>Criar</button></div></form>";
		create_popup(box,"dialog",400,null);
		create_checkbox($('.dialog .checkslider'));
		$('.dialog .red-input').focus();
		$('.dialog .button-red').click(function(e){
			if ( $('.dialog .red-input').val() == '' ){
				summon_tooltip($('.popup input'), 'up', "Um nome precisa ser informado" );
				enable_button($('.popup button'));
				$('.popup input').focus();
			}
			else{
				var info = $('.dialog .checkslider').prop('checked') +"|"+ $('.dialog .red-input').val();
				submit_discipline('insert',info);
			}
			e.preventDefault();
		});
	});
	
	//clicou em editar disciplina
	$('#opcoes #editar').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.table .row.selected').attr('id');
			var nomevelho = $($('.table .row#'+id+' .cell').get(0)).html();
			var box = "<form><h2>Renomear disciplina</h2><p>Informe o novo nome da disciplina</p><input type='text' class='red-input' value='"+ nomevelho +"'><div class='container'><label><input type='checkbox' class='checkslider'>Disciplina pública</label><button type='submit' class='button-red can-disable'>Renomear</button></div></form>";
			create_popup(box,"dialog",400,null);
			create_checkbox($('.dialog .checkslider'));
			$('.dialog .red-input').focus();
			$('.dialog .button-red').click(function(e){
				if ( $('.dialog .red-input').val() == '' ){
					summon_tooltip($('.popup input'), 'up', "Um nome precisa ser informado" );
					enable_button($('.popup button'));
					$('.popup input').focus();
				}
				else{
					var info = id +"|"+ $('.dialog .checkslider').prop('checked') +"|"+ $('.dialog .red-input').val();
					submit_discipline('rename',info);
				}
				e.preventDefault();
			});
		}
	});
	
	//clicou em visualizar disciplina
	$('#opcoes #visualizar').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.table .row.selected').attr('id');
			var url = "gerar.php?d=";
			var link = $('.table .row.selected').attr('id');
			var box = "<h2>Link da disciplina</h2>www.qstoes.ga/gerar.php?d=<a id='link' href='"+url+link+"' target='_blank'>"+link+"</a>";
			create_popup(box,"dialog",450,null);
			/*
			$('.popup .dialog img').click( function(){
				var $temp = $("<input>");
				$("body").append($temp);
				$temp.val($('.popup .dialog #link').html()).select();
				document.execCommand("copy");
				$temp.remove();
			});
			*/
		}
	});
	
});

$(window).resize( function() {
	corta_nome();
});

function corta_nome(){
	if ( $(window).width() >= 600 && $(window).width() < 900 ){
		$('.table .thead .cell').eq(1).html("Quest.");
		$('.table .thead .cell').eq(2).html("Assun.");
		$('.table .thead .cell').eq(3).html("Resol.");
	}
	else{
		$('.table .thead .cell').eq(1).html("Questões");
		$('.table .thead .cell').eq(2).html("Assuntos");
		$('.table .thead .cell').eq(3).html("Resoluções");
	}
}

function submit_discipline(action,info){
	var posting = $.post( "submit_disciplines.php", {action: action, info: info} );
	posting.done(function( data ) {
		//alert(data);
		$('.table .row').removeClass('selected');
		$('#editar, #remover, #visualizar').addClass('disabled');
		$('.popup').click();
		if (data == "inserido"){
			show_message("Disciplina inserida com sucesso. Clique no menu ao lado para cadastrar questões na disciplina");
			$('#inserir').removeClass('desativado');
		}
		else if (data == "deletado"){
			var nome = $($('.table .row#'+info+' .cell').get(0)).html();
			show_message("Disciplina '"+nome+"' foi removida com sucesso");
			if ($('.table .tbody .row').length == 1)
				$('#inserir').addClass('desativado');
		}
		else if (data == "renomeado"){
			var id = info.split("|")[0];
			var tipo = info.split("|")[1];
			if (tipo == "true")
				tipo = "pública";
			else
				tipo = "privada";
			var novonome = info.split("|")[2]; 			
			var nomevelho = $($('.table .row#'+id+' .cell').get(0)).html();
			if (nomevelho != novonome)
				show_message("Disciplina '"+ nomevelho +"' renomeada para '"+ novonome +"'");
			else
				show_message("Disciplina alterada");
		}
		load_table();
	});
}