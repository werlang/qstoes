#include <stdio.h>
/*Escreva um programa que peça para o usuário informar um valor numérico. Então mostre na tela se este valor é par ou ímpar.*/

main(){
	int valor;
	
	printf("Digite o valor");
	scanf("%i",&valor);
	
	if(valor%2==0){
		printf("Numero par");
	}else{
		printf("Numero impar");
	}
}
