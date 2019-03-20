#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int i, n, a, j , cont = 0;
	
	printf("Digite um número: ");
	scanf("%d", &n);
	
	printf("\nVocê digitou o número (%d), agora digite %d números \n", n, n);
	
	for(i = 1; i <= n; i++){
		printf("Digite o %d° número: ", i);
		scanf("%d", &a);
		cont=0;
		for (j=1 ; j<=a ; j++){
			if (a%j==0)
				cont++;
		}
		if (cont == 2)
			printf("%d é primo.\n", a);
			
	}
	
	
	system("pause");
	return 0;
}
