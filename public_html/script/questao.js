$(document).ready( function(){
	if ($('.texto').html() == ""){
		$('#frame').html("<h2>Questão não encontrada</h2>");
	}
	else{
		if ($('.imagem .grafico').attr('src') == "")
			$('.imagem').hide();
		
		load_resolucoes();

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
	}
	
});

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


function load_resolucoes(){
	var id = $('.rounded-list li .linha strong').html().split("#")[1];
	var posting = $.post( "retrieve_resolutions.php", {
		cod: id,
		action: "get"
	});
	posting.done(function( data ) {
		$('#resolucoes').html(data);
		
		//clica nos botoes de votacao
		$('.rate-container img').click( function() {
			var liquestion = $(this).parents('li');
			
			var rate = 0;
			if (liquestion.find('.rate-up.active').length != 0)
				rate--;
			if (liquestion.find('.rate-down.active').length != 0)
				rate++;
						
			var click = "none";
			if (!$(this).hasClass('active')){
				liquestion.find('.rate-container img').removeClass('active');
				$(this).addClass('active');

				if ($(this).hasClass('rate-down')){
					rate--;
					click = "down";
				}
				else{
					rate++;
					click = "up";
				}
			}
			else
				liquestion.find('.rate-container img').removeClass('active');

			var idr = liquestion.attr('id').split("-")[1];
			var posting2 = $.post( "change_rate.php", {
				cod: idr,
				rate: rate,
				click: click
			});
			posting2.done(function( data ) {
				var val = parseInt(liquestion.find('.rate-container .rate').html());
				val = val + rate;
				liquestion.find('.rate-container .rate').html(val);
			});
		});
		//clica em remover resolucao
		$('.buttons-container .remove-res').click( function() {
			var idr = $(this).parents('li').attr('id').split("-")[1];
			var box = "<h2>Excluir resolução</h2><p>Deseja realmente remover esta resolução?</p><div class='container'><button class='button-red can-disable'>SIM</button><button class='button-red'>NÃO</button></div>";
			create_popup(box,"dialog",400,null);
			$('.dialog .button-red').click(function(e){
				if ($(this).hasClass('can-disable')){
					var posting2 = $.post( "save.php", {
						id: idr,
						field: "remove-resolucao"
					});
					posting2.done(function( data ) {
						load_resolucoes();
						$('.popup').click();
					});
				}
				else
					$('.popup').click();
			});
		});
		$('.buttons-container .choose-res').click( function() {
			var obj = $(this);
			var idr = $(this).parents('li').attr('id').split("-")[1];
			var posting2 = $.post( "change_rate.php", {
				resolucao: idr,
				questao: id,
				click: "choose"
			});
			posting2.done(function( data ) {
				$('li').removeClass('chosen');
				obj.parents('li').addClass('chosen');
			});
		});
	});

}