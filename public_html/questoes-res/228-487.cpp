#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int a, b, i, j, cont = 0;
	
	printf("                Números primos entre A e B.\n\n\n");
	
	printf("Digite o valor de A(Inicio do intervalo): ");
	scanf("%d", &a);
	
	printf("\nDigite o valor de B(Final do intervalo): ");
	scanf("%d", &b);
	
	for(i = a; i <= b; i++){
		cont = 0;
		for(j = 1; j <= i; j++){
			if(i%j == 0)
			cont++;
		}
		if(cont == 2)
			printf("%d É primo.\n", i);
	}
	
	system("pause");
	return 0;
}
