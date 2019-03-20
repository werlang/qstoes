$(document).ready(function () {
	//carrega info do menu
	/*
	var posting = $.post( "load_side_menu.php", { v:value });
	posting.done(function( data ) {
		//alert(data);
	});
	*/
	//disable nos menus
	if ($('#disable-menu').html()=='disciplinas'){
		$('#side-menu-list li').not("#profile, #sair, #disciplinas").css({"pointer-events":"none","opacity":".3"});
	}
	else if ($('#disable-menu').html()=='questoes'){
		$('#side-menu-list li').not("#profile, #sair, #disciplinas, #inserir").css({"pointer-events":"none","opacity":".3"});
	}

	//some com tudo se clicar em fog
	$('#fog').click( function() {
		$('#fog').removeAttr('style');
		$('body').removeAttr('style');
		$('#header-toggle').removeAttr('style');
		$('#side-menu').removeAttr('style');
	});

	//clicou no botao mobile que mostra o header
	$('#header-toggle').click( function(){
		$(this).css({opacity: '1', backgroundColor: '#888', backgroundImage: 'url(#)'});
		$(this).animate({width: '260px', height: '100%'}, 200, function() {
			$(this).removeAttr('style');
			$(this).hide();
			$('#side-menu').css('display','flex');
			$('body').css({'overflow':"hidden"});
			$('#fog').fadeIn(100);
		});
	} );
});
