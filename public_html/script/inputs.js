$(document).ready( function() {
	$('textarea.red-input.expand').on('input', function() {
		$(this).scrollTop( $(this).height() );
	});
	$('textarea.red-input.expand').scroll(function() {
		var h = $(this).scrollTop();
		if (h>0)
		$(this).height( $(this).height() +h );
	});
});

function runtime_expand(obj){
	obj.on('input', function() {
		$(this).scrollTop( $(this).height() );
	});
	obj.scroll(function() {
		$(this).scrollTop( 99999 );
		var h = $(this).scrollTop();
		$(this).height( $(this).height() + h );
	});
	obj.scrollTop( $(window).height() );
}