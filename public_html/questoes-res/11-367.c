//Escreva um programa que peça para o usuário informar a operação desejada: + Adição, - Subtração, * Multiplicação, / Divisão, ^ Potenciação, V Raiz quadrada. 
//Então peça dois valores (somente um valor para a raiz quadrada). 
//Mostre na tela o resultado da operação, ou uma mensagem de erro em caso de operação inválida (divisão por zero, raiz quadrada de número negativo ou operação escolhida inválida).
#include <stdio.h>
#include <math.h>
main()
{
	char op;
	int a,b,resultado;
		printf(" Favor escolher qual operacao deseja fazer:\n(+)Adicao\n(-)Subtracao\n(*)Multiplicacao\n(/)Divisao\n(^)Potenciacao\n(v)Raiz quadrada:\n ");
		scanf(" %c",&op);
		
		switch (op)
		{
			case '+':
				printf("Digite o primeiro valor: ");
				scanf("%i",&a);
				printf("\nDigite o segundo valor:");
				scanf("%i",&b);
				resultado=a+b;
				printf("\nO resultado de %i + %i eh igual a %i",a,b,resultado);
			break;
			case '-':
				printf("Digite o primeiro valor: ");
				scanf("%i",&a);
				printf("\nDigite o segundo valor:");
				scanf("%i",&b);
				resultado=a-b;
				printf("\nO resultado de %i - %i eh igual a %i",a,b,resultado);
			break;	
			case '*':
				printf("Digite o primeiro valor: ");
				scanf("%i",&a);
				printf("\nDigite o segundo valor:");
				scanf("%i",&b);
				resultado=a*b;
				printf("\nO resultado de %i * %i eh igual a %i",a,b,resultado);
			break;
			case '/':
				printf("Digite o primeiro valor: ");
				scanf("%i",&a);
				printf("\nDigite o segundo valor:");
				scanf("%i",&b);
				if (b==0)
					printf("Erro. Divisao por zero.");
				else{
					resultado=a/b;
					printf("\nO resultado de %i / %i eh igual a %i",a,b,resultado);
				}
			break;
			case '^':
				printf("Digite o primeiro valor: ");
				scanf("%i",&a);
				printf("\nDigite o segundo valor:");
				scanf("%i",&b);
				resultado=pow(a,b);
				printf("\nO resultado de %i sobre %i eh igual a %i",a,b,resultado);
			break;
			case 'v':
				printf("Digite um valor: ");
				scanf("%i",&a);
				if (a<0)
					printf("Erro. Raiz quadrada de numero negativo.");
				else{
					resultado=sqrt(a);
					printf("\nO resultado da raiz quadrada de %i eh igual a %i",a,resultado);
				}
			break;
			default:
				printf("Operacao invalida");
		}
}