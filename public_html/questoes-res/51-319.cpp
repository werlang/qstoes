/*Escreva um programa que pe�a para o usu�rio informar 10 n�meros. 
Ent�o mostre na tela o somat�rio do primeiro pelo �ltimo, do segundo pelo pen�ltimo, e assim por diante.*/
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
