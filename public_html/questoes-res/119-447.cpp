#include <stdio.h>
/*Escreva um programa que pe�a para o usu�rio informar um valor num�rico. Ent�o mostre na tela se este valor � par ou �mpar.*/

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
