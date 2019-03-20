#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que peça para o usuário informar uma temperatura em Celsius, e então uma tecla indicando para qual escala 
deseja converter (K ou F). Então realize a conversão e mostre o resultado na tela. Mostre uma mensagem de erro caso a escala desejada 
seja inválida.*/

main(){
	float c,k,f;
	char op;
	
	printf("\nConversor de temperatura:");
	printf("\n\nEntre com o valor em Celsius:");
	scanf("%f",&c);
	
	printf("\nEscolha a opcao desejada: K to Kelvin ou F to Fahrenheit.");
	scanf(" %c",&op);
	switch(op) {
	
		case 'K':
			printf("\nVoce escolheu converter C to K");
			k=(c+273);
			printf("\nResultado da conversao: %.2f",k);
			break;
		case 'F':
			printf("\nVoce escolheu converter C to F");
			f=((9.0/5.0)*c+(32));//evita de fazer cast
			printf("\nResultado da conversao: %.2f",f);
			break;	
		default:
			printf("Letra errada!");	
}}
