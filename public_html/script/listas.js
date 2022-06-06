$(document).ready( function() {
	create_select($('#select-disciplinas'));
	load_table();

	$('#select-disciplinas').change( function(){
		load_table();
		$('.table .tbody .row.selected').click();
	});
	
	//clicou em adicionar lista
	$('#opcoes #adicionar').click( function(){
		var link = $('#select-disciplinas').val();
		$('.table .row').removeClass('selected');
		$('#editar, #remover, #visualizar').addClass('disabled');
		var box = "<form><h2>Adicionar lista</h2><p>Nome</p><input type='text' class='red-input'><p>Descrição</p><input type='text' class='red-input'><p>Questões</p><div class='container'><input type='text' id='campo-questoes' class='red-input' placeholder='EX: 24,35,128,57'><button id='botao-questoes' class='button-red'>Adicionar questões</button></div><div id='div-questoes'></div><div id='container-pages' class='container'><img id='prev' src='icon/anterior.png'/><img id='remove' src='icon/x_plain.png'/><img id='next' src='icon/proximo.png'/></div><div class='container'><button id='botao-salvar' class='button-red can-disable'>Enviar</button><a href='gerar.php?d="+link+"' id='botao-pesquisa' target='_blank' class='button-red'>Pesquisar questões</a></div></form>";
		create_popup(box,"window",400,null);
		$('.popup input').on('input', function(){
			if ($(this).val() != "")
				summon_tooltip();
		});
		$('.window .red-input').eq(0).focus();
		bind_salvar_lista('insert');
		bind_adicionar_questoes();
		bind_navega_questoes();
	});
	
	//clicou em remover lista
	$('#opcoes #remover').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.table .row.selected').attr('id').match(/\d+/)[0];
			var nome = $($('.table .row.selected .cell').get(0)).html();
			var box = "<h2>Remover lista</h2><p>Deseja realmente excluir a lista <b>"+nome+"</b>?</p><div class='container'><button class='button-red can-disable'>SIM</button><button class='button-red'>NÃO</button></div>";
			create_popup(box,"dialog",400,null);
			$('.dialog .button-red').click(function(e){
				if ($(this).hasClass('can-disable'))
					submit_list('delete',id);
				else
					$('.popup').click();
			});
		}
	});
	//clicou em editar lista
	$('#opcoes #editar').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.table .row.selected').attr('id').match(/\d+/)[0];
			var box = "<form><h2>Editar lista</h2><p>Nome</p><input type='text' class='red-input'><p>Descrição</p><input type='text' class='red-input'><div id='div-pesquisa'><p>Questões</p><div class='container' ><input type='text' id='campo-questoes' class='red-input' placeholder='EX: 24,35,128,57'><button id='botao-questoes' class='button-red'>Adicionar questões</button></div></div><div id='div-questoes'></div><div class='container'><button type='submit' id='edit-salvar' class='button-red can-disable'>Salvar</button><button type='submit' id='edit-questoes' class='button-red can-disable'>Editar questões da lista</button></div></form>";
			create_popup(box,"window",400,null);
			$('#div-pesquisa').hide();
			var nome = $($('.table .row.selected .cell').get(0)).html();
			var descricao = $($('.table .row.selected .cell').get(2)).html();
			$('.popup input').eq(0).val(nome);
			$('.popup input').eq(1).val(descricao);
			$('.popup input').on('input', function(){
				if ($(this).val() != "")
					summon_tooltip();
			});
			$('.window .red-input').eq(0).focus();
			bind_salvar_lista('rename');
			//clica no botao de editar questoes da lista
			$('.window .button-red#edit-questoes').click(function(e){
				var posting = $.post( "check_lists.php", {lista: id} );
				posting.done(function( data ) {
					data = data.split(",");
					$('#div-pesquisa').show();
					bind_adicionar_questoes();
					$('#div-questoes').html("");
					$.each( data, function(i,v){
						$('#div-questoes').append("<div class='item old'><div class='texto'>"+ v +"</div></div>");
					});
					$('#div-questoes').after("<div id='container-pages' class='container'><img id='prev' src='icon/anterior.png'/><img id='remove' src='icon/x_plain.png'/><img id='next' src='icon/proximo.png'/></div>");
					bind_seleciona_questao();
					bind_navega_questoes();
					enable_button($('#edit-questoes'));
				});
				var link = $('#select-disciplinas').val();
				$(this).before("<a href='gerar.php?d="+ link +"' id='botao-pesquisa' target='_blank' class='button-red'>Pesquisar questões</a>");
				$(this).remove();
				e.preventDefault();
			});
		}
	});
	//clicou em organizar lista
	$('#opcoes #organizar').click( function(){
		if (!$(this).hasClass('disabled')){
		}
	});
	//clicou em visualizar lista
	$('#opcoes #visualizar').click( function(){
		if (!$(this).hasClass('disabled')){
			var id = $('.table .row.selected').attr('id').match(/\d+/)[0];
			var url = "lista.php?l=";
			var link = $('.table .row.selected').attr('data-key');
			var box = "<h2>Link da lista</h2>www.qstoes.tk/lista.php?l=<a id='link' href='"+url+link+"' target='_blank'>"+link+"</a>";
			create_popup(box,"dialog",450,null);
			/*
			$('.popup .dialog img').click( function(){
				var $temp = $("<input>");
				$("body").append($temp);
				$temp.val($('.popup .window #link').html()).select();
				document.execCommand("copy");
				$temp.remove();
			});
			*/
		}
	});
});

function bind_salvar_lista(action){
	//clica no botao de salvar nova lista
	$('.window #botao-salvar, .window #edit-salvar').click(function(e){
		var botao = $(this);
		e.preventDefault();
		summon_tooltip();
		var info = [$('.window .red-input').eq(0).val(), $('.window .red-input').eq(1).val()];
		if (action == 'rename')
			info[2] = $('.table .row.selected').attr('id').match(/\d+/)[0];
		
		if (info[0] == ''){
			summon_tooltip($('.popup input').eq(0),"up","Informe um nome válido para a lista");
			$('.popup input').eq(0).focus();
			enable_button($('.popup button'));
		}
		/*
		else if (info[1] == ''){
			summon_tooltip($('.popup input').eq(1),"up","Informe uma descrição válida para a lista");
			$('.popup input').eq(1).focus();
			enable_button($('.popup button'));
		}
		*/
		else if ( $('#div-questoes').html()  == '' && action == 'insert'){
			summon_tooltip($('.popup input').eq(2),"up","Insira algumas questões na lista");
			$('.popup input').eq(2).focus();
			enable_button($('.popup button'));
		}
		else{
			var disc = $('#select-disciplinas').val();
			var posting = $.post( "check_questions.php", {disciplina: disc} );
			posting.done(function( data ) {
				data = data.split(",");
				$('#div-questoes .item .texto').each(function() {
					var achou = data.indexOf( $(this).html() );
					if (achou == -1)
						$(this).parent().addClass('marked');
				});
				if ( $('#div-questoes .item.marked').length == 0 ){
					var questoes = new Array();
					$('#div-questoes .item .texto').each(function() {
						if ( $(this).parent().hasClass('removed') )
							questoes[ questoes.length ] = "d|" + $(this).html();
						else if ( $(this).parent().hasClass('new') )
							questoes[ questoes.length ] = "i|" + $(this).html();
						else
							questoes[ questoes.length ] = "u|" + $(this).html();
					});
					submit_list(action,info,questoes);
				}
				else{
					summon_tooltip( $('#div-questoes'), 'up', "Estas questões não pertencem à disciplina. Remova-as para prosseguir" );
				}
				enable_button(botao);
			});
		}
	});
	
}

function bind_adicionar_questoes(){
	//clica em adicionar novas questoes na lista sendo criada
	$('.window .button-red#botao-questoes').click(function(e){
		summon_tooltip();
		if ( $('#campo-questoes').val() != '' ){
			var cod = $('#campo-questoes').val().match(/(\d+)/g);
			$.each(cod, function(i,v) {
				var insere = true;
				$("#div-questoes .item .texto").each( function(){
					if ( $(this).html() == v ){
						insere = false;
						if ( $(this).parent().hasClass('removed') )
							$(this).parent().removeClass('removed');
					}
				});
				if (insere){
					$('#div-questoes').append("<div class='item new'><div class='texto'>"+ v +"</div></div>");
				}
			});
			$('#campo-questoes').val("");
		}
		//bind_deleta_questao();
		bind_seleciona_questao();
		e.preventDefault();
		if ( $('.popup input').eq(0).val() == '' )
			$('.popup input').eq(0).focus();
		else if ( $('.popup input').eq(1).val() == '' )
			$('.popup input').eq(1).focus();
		else
			$('#campo-questoes').focus();
	});	
}

function bind_deleta_questao(){
	//clica no botao de remover e-card da questao
	$('#div-questoes .item .remove').click( function(){
		summon_tooltip();
		if ( $(this).parent().hasClass('old') ){
			$(this).parent().addClass('removed');
		}
		else
			$(this).parent().remove();
	});
}

function bind_navega_questoes(){
	//clica em remover questao da lista
	$('.window #container-pages #remove').click( function(){
		summon_tooltip();
		var obj = $('#div-questoes .item.selected');
		if ( obj.hasClass('old') ){
			obj.addClass('removed');
		}
		else
			obj.remove();
	});
	//alterar ordem da questao para esquerda
	$('.window #container-pages #prev').click( function(){
		var obj = $('#div-questoes .item.selected');
		obj.after(obj.prev());
	});
	//alterar ordem da questao para direita
	$('.window #container-pages #next').click( function(){
		var obj = $('#div-questoes .item.selected');
		obj.before(obj.next());
	});
}
function bind_seleciona_questao(){
	//clica na questao pra selecionar

	$('#div-questoes .item .texto').click( function(){
		summon_tooltip();
		$('#div-questoes .item').removeClass('selected');
		$(this).parent().addClass('selected');
	});
}

function submit_list(action,info,questoes){
	var disc = $('#select-disciplinas').val();
	var posting = $.post( "submit_lists.php", {action: action, disciplina: disc, info: info, questoes: questoes} );
	posting.done(function( data ) {
		//alert(data);
		$('.popup').click();
		if (data == "inserido"){
			show_message("Lista inserida com sucesso");
		}
		else if (data == "deletado"){
			show_message("Lista exluída com sucesso");
		}
		else if (data == "renomeado"){
			show_message("Lista alterada com sucesso");
		}
		load_table();
	});
}


function load_table(){
	$('.table .row').removeClass('selected');
	$('#editar, #remover, #visualizar').addClass('disabled');
	//carrega tabela no inicio
	var id = $('#select-disciplinas').val();
	if ($(window).width() < 600)
		var limit = 5;
	else
		var limit = 10;
	var nrows;
	var offset = $('#container-pages').attr('data-offset');
	var posting = $.post( "lists_table.php", {disciplina: id, limit: limit, offset: offset} );
	var drop = 0;
	posting.done(function( data ) {
		data = data.split("|");
		$('.table .tbody').html(data[0]);
		if ($('.table .tbody').next().length > 0)
			$('.table .tbody').next().remove();
		$('.table .tbody').after(data[1]);
		offset = parseInt($('#container-pages').attr('data-offset'));
		nrows = $('#container-pages').attr('data-nrows');
		$('.table .tbody').sortable({
			appendTo: 'body',
			containment: 'body',
			cancel: '.row:not(.selected)',
			start: function( event, ui ) {
				if (offset > 0)
					$('.tbody').before("<div class='row sort-prev'><img src='icon/arrow_up.png'></div>");
				if (parseInt(offset) + limit < nrows) 
					$('.tbody').after("<div class='row sort-next'><img src='icon/arrow_down.png'></div>");
				$( ".sort-next, .sort-prev" ).droppable({
					accept: ".row.selected",
					over: function( event, ui ) {
						$(this).css('background-color','rgba(255,150,150,0.9)');
					},
					out: function( event, ui ) {
						$(this).css('background-color','rgba(200,150,150,0.5)');
					},
				});
				$( ".sort-prev" ).droppable({
					drop: function( event, ui ) {
						drop = -1;
					}
				});
				$( ".sort-next" ).droppable({
					drop: function( event, ui ) {
						drop = 1;
					}
				});
			},
			stop: function( event, ui ) {
				$('.sort-next, .sort-prev').remove();
				var order = new Array();
				var id = new Array();
				var cont = 0;
				$('.tbody .row').each( function(){
					cont++;
					id.push($(this).attr('id').match(/\d+/)[0]);
					order.push(offset + cont);
				});
				//alert(id+"\n"+order);
				var posting = $.post( "submit_lists.php", {action: 'reorder', id: id, order: order} );
				posting.done(function( data ) {
					//alert(data);
					if (drop != 0){
						id = $('.row.selected').attr('id').match(/\d+/)[0];
						order = parseInt($('.tbody .row').index($('.row.selected'))) + parseInt(offset) + 1;
						//alert(id+"\n"+order+"\n"+drop);
						var posting = $.post( "submit_lists.php", {action: 'reorder', drop: drop, id: id, order: order} );
						posting.done(function( data ) {
							//alert(data);
							load_table();
						});
					}
					drop = 0;
				});
			}
		});
		
		//clicou em uma linha da tabela
		$('.table .tbody .row').mouseup(function(){
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
			offset += limit;
			//alert(offset);
			if (offset > nrows-limit)
				offset = nrows-limit;
			$('#container-pages').attr('data-offset',offset);
			load_table();
		});
		
	});
}
