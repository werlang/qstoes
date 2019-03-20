/*Escreva um programa que peça para o usuário informar valores até que o zero seja digitado (máximo 10 números digitados). 
Então mostre na tela qual a diferença positiva entre cada valor digitado pela média dos valores informados.*/
#include <stdio.h>
main(){
	int vet[10], x, y;
	float media=0, dif;	
	for(x=0;x<10;x++){
		printf("Informe um valor:");
		scanf("%i", &vet[x]);
		if(vet[x]==0){
		break;
		}
		media=media+vet[x];
	}
	media=media/x;
	for(y=0;y<x;y++){
		dif=vet[y]-media;
		if(dif>=0){
			printf("%.2f\n", dif);
		}
		else
			printf("%.2f\n", -dif);
	}
}
