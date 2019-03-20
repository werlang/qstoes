#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

/*Escreva um programa que peça para o usuário inserir uma palavra de até 10 letras. Então mostre na tela o resultado da concatenação desta palavra com a palavra invertida.
 Ex. Palavra: programacao. Resultado: programacao oacamargorp
*/

main(){
	char palavra[10],l;
	int i,j;
	
	printf("Digite uma palavra de 10 letras:");
	for(i=0;i<10;i++){
		printf("\nLetra %i:",i+1);
		l = getche();
		palavra[i]=l;
		if(i==9){
			printf("\n");
		}
	}
	for(i=0;i<10;i++){
		printf("%c",palavra[i]);
		if(i==9){
			for(j=0;j<10;j++){
				printf("%c",palavra[9-j]);
			}
		}
	}
	
	
}
