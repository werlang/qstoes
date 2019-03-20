#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Escreva uma função que receba por referência dois valores e troque o conteúdo destes valores um pelo outro.


void troca(int *n1, int *n2){
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
	
}

main(){
	int x, y;
	
	printf("digite 2 numeros\n");
	scanf("%d",&x);
	scanf("%d",&y);
	
	troca(&x,&y);
	
	printf("\n%d e %d\n",x,y);	
}

