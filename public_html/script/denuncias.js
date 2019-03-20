$(document).ready( function(){
	load_table();
		
	//clicou em aceitar e recusar resolucao
	$('#opcoes #excluir').click( function() {
		if (!$(this).hasClass('disabled')){
			var posting = $.post( "resolve_report.php", {
				cod: $('.table .row.selected').attr('id').match(/\d+/)[0]
			});
			posting.done(function( data ) {
				//alert(data);
				if (data != "feedback"){
					show_message("Denúncia excluída");
					remove_selected(0);
					load_table();
				}
				else{
					var box = "<h2>Enviar mensagem</h2><p>Caso deseje, envie uma mensagem para o autor da denúncia</p><textarea class='red-input'></textarea><div class='container'><button id='envia' class='button-red can-disable'>Enviar</button><button id='nao' class='button-red can-disable'>Não</button></div>";
					create_popup(box,"dialog",400,null);
					runtime_expand($('.dialog textarea'));
					$('.dialog textarea').focus();
					$('.dialog #envia').click(function(e){
						var posting = $.post( "resolve_report.php", {
							cod: $('.table .row.selected').attr('id').match(/\d+/)[0],
							mensagem: $('.dialog .red-input').val()
						});
						posting.done(function( data ) {
							//alert(data);
							$('.popup').click();
							show_message("Denúncia excluída");
							remove_selected(0);
							load_table();
						});
					});
					$('.dialog #nao').click(function(e){
						var posting = $.post( "resolve_report.php", {
							action: "naoenvia",
							cod: $('.table .row.selected').attr('id').match(/\d+/)[0]
						});
						posting.done(function( data ) {
							//alert(data);
							$('.popup').click();
							show_message("Denúncia excluída");
							remove_selected(0);
							load_table();
						});
					});
				}
			});
		}
	});
});

function load_table(){
	//carrega tabela no inicio
	if ($(window).width() < 600)
		var limit = 5;
	else
		var limit = 10;
	var offset = $('#container-pages').attr('data-offset');
	var posting = $.post( "report_table.php", {limit: limit, offset: offset} );
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

			remove_selected(tempo);
			
			//adiciona selected no clicado
			if (selected){
				var hi = $(this).outerHeight();
				$(this).addClass('selected');
				var hf = $(this).outerHeight();
				$(this).height(hi);
				$(this).animate({ height: hf, }, tempo, function(){
					$(this).removeAttr('style');
					$('#opcoes div').removeClass('disabled');
					var url = "questao.php?q=" + $(this).find('.cell:nth-child(2)').html();
					$('#opcoes #questao a').attr('href',url);
				});
			}
			//atribui ao data-head o nome do título da coluna
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
			remove_selected(0);
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
			remove_selected(0);
		});
		
	});
}

function remove_selected(tempo){
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
		$('#opcoes div').addClass('disabled');
		$('#opcoes a').removeAttr('href');
	});	
}
