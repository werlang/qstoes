#include<stdio.h>
#include<math.h>

/*Escreva um algoritmo que peça para o usuário informar dois números.
 Então mostre na tela o resultado da adição, subtração, multiplicação,
  divisão e potenciação do primeiro pelo segundo número.*/


main(){
	int a=0, b=0;
	
	printf("digite um numero: ");
		scanf("%i",&a);
	
	printf("digite outro numero: ");
		scanf("%i",&b);
		
		int adicao, sub, multi, div;
		adicao=(a+b);
		sub=(a-b);
		multi=(a*b);
		div=(a/b);
	
	printf("A adicao entre os dois numeros: %i\n",adicao);
	printf("A subtracao entre os dois numeros: %i\n",sub);
	printf("A multiplicacao entre os dois numeros: %i\n",multi);
	printf("A divisao entre os dois numeros: %i\n",div);
	
	
	
}
