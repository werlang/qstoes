/*Escreva um programa que peça para o usuário informar 10 números. 
Então mostre na tela o somatório do primeiro pelo último, do segundo pelo penúltimo, e assim por diante.*/
#include<stdio.h>
#include<stdlib.h>


main(){
	int vetor[10],i;
	
	for(i=0; i<10; i++){
		printf("Digite o numero %i:",i+1);
		scanf("%i",&vetor[i]);
	}
	for(i=0; i<5 ;i++){
		printf("\nSoma da posicao %i - posicao %i = %i",i+1,10-i,vetor[i]+vetor[9-i]);
	}
}
