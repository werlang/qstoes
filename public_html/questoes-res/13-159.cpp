#include<stdio.h>
#include<math.h>

/*Escreva um algoritmo que pe�a para o usu�rio informar dois n�meros.
 Ent�o mostre na tela o resultado da adi��o, subtra��o, multiplica��o,
  divis�o e potencia��o do primeiro pelo segundo n�mero.*/


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
