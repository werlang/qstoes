$(document).ready( function(){
	$.post("cookie.php",{
		action: "GET"
	}).done( function(data){
		$('#target input').data('time',data);
		formatTime($('#target input'));
		//console.log(data);
	});
	
	$('#target input').focus();
	
	calcTime();
	$('input').on('keydown', function(){
		moveCursorToEnd(this);
	});
	$('input').on('input', function(){
		inputTime($(this));
	});
	
	setInterval( function() {
		calcTime();
	}, 1000);
	
	$('.switch input').change( function () {
		$('#option-show input').data('time', 0);
		$('#option-show input').val("00:00");
		if ($(this).prop('checked')){
			$('#option-show').show('slow');
			$('#option-show input').focus();
		}
		else{
			$('#option-show').hide('slow');
		}
	});
});

function calcTime(){
	var t = $('#target input').data('time');
	var tm = parseInt(t/100)*60 + t%100;
	//console.log("target: "+tm);
	
	var a = $('#option-show input').data('time');
	var am = Math.floor(a/100)*60 + a%100;
	//console.log("now: "+am);
		
	var d = new Date();
	var m = d.getHours()*60 + d.getMinutes();
	//console.log("time: "+m);

	var dm = tm - m;
	if (dm < 0)
		dm = dm + 60*24;

	//console.log("diff: "+dm);


	var corr = parseInt(dm * 1.2) + parseInt(am);
	//console.log("corr: "+corr);
	
	var ch = parseInt(corr/60);
	var cm = corr%60;
	
	if (ch >= 24){
		if (ch - parseInt(am) >= 24){
			ch = "--";
			cm = "--";
		}
		else
			ch -= 24;
	}
	
	if (ch < 10)
		ch = "0"+ ch;
	if (cm < 10)
		cm = "0"+ cm;
	$('#time').html(ch+':'+cm);
}

function moveCursorToEnd(el) {
	if (typeof el.selectionStart == "number") {
		el.selectionStart = el.selectionEnd = el.value.length;
	} else if (typeof el.createTextRange != "undefined") {
		el.focus();
		var range = el.createTextRange();
		range.collapse(false);
		range.select();
	}
}

function inputTime(elem) {
	elem.focus();

	var t = elem.data('time');
	var e = parseInt(elem.val()[elem.val().length - 1]);
	if (elem.val().length < 5){ //apertou backspace 00:00 = tamanho 5
		t = parseInt(t/10);
		elem.data('time', t);
	}
	else if (e >= 0 && e <= 9 && t < 1000){
		t = t*10 + e;
		elem.data('time', t);
	}
	//console.log(t);
		
	formatTime(elem);
	
	calcTime();
	
	$.post("cookie.php",{
		action: "SET",
		time: $('#target input').data('time'),
	});
}

function formatTime(elem){
	var data = elem.data('time');
	var h = parseInt(data/100);
	if (h < 10)
		h = '0'+ h;
	var m = data%100;
	if (m < 10)
		m = '0'+ m;
	
	elem.val(h +':'+ m);
}