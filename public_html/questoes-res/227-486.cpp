#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int i, n, a, j , cont = 0;
	
	printf("Digite um n�mero: ");
	scanf("%d", &n);
	
	printf("\nVoc� digitou o n�mero (%d), agora digite %d n�meros \n", n, n);
	
	for(i = 1; i <= n; i++){
		printf("Digite o %d� n�mero: ", i);
		scanf("%d", &a);
		cont=0;
		for (j=1 ; j<=a ; j++){
			if (a%j==0)
				cont++;
		}
		if (cont == 2)
			printf("%d � primo.\n", a);
			
	}
	
	
	system("pause");
	return 0;
}
