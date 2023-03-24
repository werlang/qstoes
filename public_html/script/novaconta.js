function message_pos(){
    if ( $(window).width() >= 1200 )
        return 'right';
    else
        return 'up';
}

$(document).ready(function () {
    $('.red-input').focusout( function() { summon_tooltip(); });
    $('#formsubmit .red-input').focus( function() { summon_tooltip( $(this), message_pos(), $(this).attr("data-tooltip") ); });

    //clica no botao de criar conta
    $('#bcriar').click( function(){
        $('#formsubmit').submit();
    });
    $('#formsubmit').submit( function(e) {
        var fd = new FormData(document.getElementById("formsubmit"));
        $.ajax({
            url: "create_account.php",
            type: "POST",
            data: fd,
            enctype: 'multipart/form-data',
            processData: false,  // tell jQuery not to process the data
            contentType: false   // tell jQuery not to set contentType
        }).done(function( data ) {
            //alert(data);
            var datasplit = data.split("|");
            if (datasplit[1]){
                var obj = $("input[name='"+ datasplit[0] +"']");
                data = datasplit[1];
                obj.focus();
                summon_tooltip(obj,message_pos(),data);
            }
            else{
                if (data != "")
                    show_message(data);
                    $('.popup').click(function(){
                        location.href = "index.php";
                    });
            }
            enable_button($('#bcriar'));
        });
        e.preventDefault();
    });
});
