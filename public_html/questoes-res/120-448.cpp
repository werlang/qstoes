#include<stdio.h>
main (){
	
float notaum,notadois,media;
	
	printf ("informe a primeira nota:");
	scanf ("%f", & notaum);
	
	printf ("informe a segunda nota:");
	scanf ("%f", & notadois);
	
	media=(notaum+notadois)/2;
	
	if (media>=6){
		printf ("aprovado");
	}
	else {
		printf ("reprovado");
	}
	
}

	
