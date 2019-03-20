$(document).ready(function () {
	$('#img-prof').click( function() {
		$('#click-aluno').hide();
		$('#click-prof').show(function(){
			$('html,body').animate({scrollTop: $('#click-prof').offset().top},'slow');
		});
	});
	$('#img-aluno').click( function() {
		$('#click-prof').hide();
		$('#click-aluno').show(function(){
			$('html,body').animate({scrollTop: $('#click-aluno').offset().top},'slow');
		});
	});
	
	$('video').click( function() {
		if (this.currentTime > 0 && !this.paused && !this.ended)
			var playing = true;
		else
			var playing = false;
		
		if (!playing){
			this.play();
			$(this).parent().css({"background-image":"url('icon/stop.png')"});
		}
		else{
			this.pause();
			$(this).parent().css({"background-image":"url('icon/play.png')"});
		}
	});
	
	//troca imagens caso tela seja maior
	if ( $(window).width() >= 900 ){
		$('.screenshot img').each( function() {
			var nome = $(this).attr('src');
			$(this).attr('src', nome.replace("_m",""));
		});
	}
	
	//clica no botao de convite
	$('#bconvida').click(function(){		
		var nome_aluno = $('.slide-5 #nome_aluno').val();
		var nome_prof = $('.slide-5 #nome_prof').val();
		var mensagem = $('.slide-5 #mensagem').val();
		var email = $('.slide-5 #email').val();

		var posting = $.post( "invite_teacher.php", { nome_aluno: nome_aluno, nome_prof: nome_prof, email: email, mensagem: mensagem });
		posting.done(function( data ) {
			show_message(data);
			enable_button($('#bconvida'));
		});
		
	});
	
	var posting = $.post( "index_disciplines_table.php", {} );
	posting.done(function( data ) {
		$('#table-public-disc .tbody').html(data);

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
			});
			
			//adiciona selected no clicado
			if (selected){
				var hi = $(this).outerHeight();
				$(this).addClass('selected');
				var hf = $(this).outerHeight();
				$(this).height(hi);
				$(this).animate({ height: hf, }, tempo, function(){
					$(this).removeAttr('style');
				});
			}
			$('.table .tbody .row .cell').removeAttr("data-head");
			var i=1;
			$('.table .thead .cell').each( function(){
				$('.table .tbody .row.selected .cell:not(.m-show):nth-child('+i+')').attr("data-head",$(this).html());
				i++;
			});
		});
	});	
});
