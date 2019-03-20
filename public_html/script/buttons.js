$(document).ready(function(){
	$(document).on( 'click', 'button.can-disable', function(){
		if (!$(this).attr('data-waiting')){
			var h = $(this).height();
			$(this).attr("disabled", true);
			$(this).prepend("<img src='icon/loading.svg' class='loadimg'>");
			$(this).css({"font-size":"0px"});
		}
		$(this).removeAttr('data-waiting');
	} );
});

function enable_button(obj){
	obj.prop('disabled', false);
	obj.find('.loadimg').remove();
	obj.removeAttr("style");
	obj.attr('data-waiting',true);
}