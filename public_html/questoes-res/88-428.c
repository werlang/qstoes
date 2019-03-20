#include<stdio.h>
#include<conio.h>
#include<string.h>


main(){
	char *p, frase[100],palavra[20];

	printf("Informe uma frase: ");
	gets(frase);

	printf("Informe uma palavra: ");
	gets(palavra);
	
	p = strstr(frase,palavra);
	
	int i;
	while (p!= NULL){
		for (i=0 ; i<strlen(palavra) ; i++){
			if (*(p+i) >= 'a' && *(p+i) <= 'z')
				*(p+i) -= 32;
		}
		p = strstr(frase,palavra);
	}
	
	printf("\nFrase modificada: %s", frase);
}
