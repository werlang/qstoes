function fade_parallax(obj){
	if (obj.hasClass('fade')){
		var scroll = $(window).scrollTop();
		var wh = $(window).height();
		var target = obj.offset().top;
		var dif = (scroll - target) / wh;

		var min = parseFloat(obj.attr('data-fade0'));
		var max = parseFloat(obj.attr('data-fade1'));
		var opa = (dif+min)/(min-max);
		if (opa < 0) opa=0;
		if (opa > 1) opa=1;
		obj.css({'opacity':opa});
	}
}

function move_parallax(obj){
	if (obj.hasClass('move')){
		var scroll = $(window).scrollTop();
		var wh = $(window).height();
		var target = obj.offset().top;
		var dif = (scroll - target) / wh;
		
		if (dif <= 0 && dif >= -1){
			var xini = parseFloat(obj.attr('data-move0x'));
			var xfim = parseFloat(obj.attr('data-move1x'));
			var xdif = xfim-xini;
			var xatual = parseFloat(obj.css('background-position-x'));
			
			var yini = parseFloat(obj.attr('data-move0y'));
			var yfim = parseFloat(obj.attr('data-move1y'));
			var ydif = yfim-yini;
			var yatual = parseFloat(obj.css('background-position-y'));
			var posn="";
			if (isNaN(xdif))
				posn += xatual+"% ";
			else
				posn += (xini+xdif*(1+dif))+"% ";
			if (isNaN(ydif))
				posn += yatual+"%";
			else
				posn += (yini+ydif*(1+dif))+"%";
			$('#test').html(posn);
			obj.css({'background-position':posn});
		}
	}
}

$(window).scroll(function () {
	var scroll = $(window).scrollTop();
	var wh = $(window).height();
	$('.parallax').each( function() {
		var target = $(this).offset().top;
		var dif = (scroll - target) / wh;
		if (dif >= -1){
			fade_parallax($(this));
			move_parallax($(this));
		}
	});
});

