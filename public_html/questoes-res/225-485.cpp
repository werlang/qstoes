#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int a, b, i, acum = 0;
	
	printf("                       Intervalos entre A e B.\n\n");
	printf("Digite o valor de A: ");
	scanf("%d", &a);
	
	printf("\nDigite o valor de B: ");
	scanf("%d", &b);
	
	if(a < b){
		for(i = a; i <= b; i++){
			acum += i;
		}
	}else {
		for(i = b; i <= a; i++){
			acum += i;
		}
	}
	
	printf("\n\nA soma de todos os números entre A(%d) e B(%d) é igual a: %d\n\n", a, b, acum);
	
	system("pause");
	return 0;
}
