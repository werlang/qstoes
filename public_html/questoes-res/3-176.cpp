#include<stdio.h>

/*Escreva um algoritmo que pe�a para o usu�rio informar um n�mero, 
e mostre na tela se este n�mero � positivo, negativo ou zero*/

main(){
	int n=0;
	
	printf("digite um numero: ");
		scanf("%i",&n);
	
	if(n > 0){
		printf("o numero %i e positivo",n);
		
	}
	
	if(n == 0){
		printf("o numero %i e zero",n);
	}
	
	if(n < 0){
		printf("o numero %i e negativo",n);
	}
	
	
}

