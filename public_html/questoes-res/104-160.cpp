#include <stdio.h>

int main(){
	float conta,percentual,juros,total;
	char nome[45];
	printf("Digite seu nome:");
	gets(nome);
	printf("\n----------------------------------------");
	printf("\nBem-Vindo, %s ao Simulador Contas",nome);
	printf("\n \nInforme o valor da conta:");
	scanf("%f",&conta);
	printf("Informe o valor do juros:");
	scanf("%f",&percentual);
	
	juros=(conta*(percentual/100));
	printf("\nValor de juros a ser pago: %.2f",juros);
	printf("\nValor final da conta com juros: %.2f",(conta+juros));
	printf("\n-----------------------------");
	
}
