#include <stdio.h>

main () {	
	
	float av1, av2, av3;
	printf ("Nota da avaliacao 1: ") ; scanf ("%f", &av1);
	printf ("Nota da avaliacao 2: ") ; scanf ("%f", &av2);
	printf ("Nota da avaliacao 3: ") ; scanf ("%f", &av3);
	
	float soma=av1+av2+av3, media=soma/3;
	printf ("Sua nota media e': %f", media);
		
}
