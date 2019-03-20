/*Escreva um programa que peça para o usuário informar uma frase em um vetor alocado dinamicamente, 
de um tamanho grande. Ao fim da execução do programa, a única memória alocada para o vetor deve ser 
do tamanho exato da frase digitada pelo usuário. Realize esta função sem usar a função realloc.*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	char *frase = (char*)malloc(sizeof(char)*200);
	int tam;
	printf("Informe uma frase: ");
	gets(frase);
	tam=strlen(frase);
	
	char *aux = (char*)malloc(sizeof(char)*tam);
	strcpy(aux, frase);
	
	free(frase);
	
	frase = (char*)malloc(sizeof(char)*tam);
	strcpy(frase, aux);
	
	free(aux);
	
	printf("%s", frase);
	printf("\n%i", tam);	
}
