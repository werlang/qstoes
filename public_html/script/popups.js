function summon_tooltip(obj,pos,text){
	$('.tooltip').fadeOut(500);
	$('.tooltip.append').remove();
	if (obj){
		var objname = $(obj).attr("name");
		obj.parent().append("<div class='tooltip append'>"+text+"</div>");
		var tooltipobj = $(".tooltip.append");
		if (pos == 'up' || pos == 'down'){
			var left = obj.position().left + obj.outerWidth() / 2 - tooltipobj.outerWidth() / 2;
			if (tooltipobj.outerWidth() > $(window).width()){
				tooltipobj.width( $(window).width() - 10);
				left=0;
			}
			tooltipobj.css('left',left);
			if (pos == 'up')
				var top = obj.position().top - tooltipobj.outerHeight() -5;
			if (pos == 'down')
				var top = obj.position().top + obj.outerHeight() +5;
			tooltipobj.css('top',top);
		}
		if (pos == 'left'){
			var top = obj.position().top + obj.outerHeight() / 2 - tooltipobj.outerHeight() / 2;
			var left = obj.position().left - tooltipobj.outerWidth() -5;
			tooltipobj.css({'left':left+'px', 'top':top+'px'});
		}
		if (pos == 'right'){
			var top = obj.position().top + obj.outerHeight() / 2 - tooltipobj.outerHeight() / 2;
			var left = obj.position().left + obj.outerWidth() +5;
			tooltipobj.css({'left':left+'px', 'top':top+'px'});
		}
		tooltipobj.fadeIn(200);
	}
}

function create_popup(content,divclass,dimension){
	$('body').append("<div class='popup'><div class='"+divclass+"'></div></div>");
	$('.popup').click(function(e){ 
		if ( e.target == this || divclass == "message" ){
			$('.popup').remove();
			$('body').removeAttr('style');
		}
	});
	$('.popup .'+divclass).html(content);
	$('.popup .'+divclass).css({"width":dimension});
	$('.popup').css({"display":"flex"});
	$('.popup').hide();
	$('.popup').fadeIn(300);
	$('body').css({"overflow":"hidden"});
	$('body').css({"width":$('body').innerWidth(),"overflow":"hidden"});
}

function show_message(text){
	create_popup(text,"message",null);
}
/*
$(document).ready( function() {
	$(window).resize( function() { $('.popup').click(); });
});
*/

/*
//se livra do banner o 000webhost
$(document).ready( function() {
	$('#frame').next('div').hide();
});
*/