#include<stdio.h>
#include<conio.h>
/*Questão #7:
Assuntos: Estruturas de seleção (IF/SWITCH).
Peça para o usuário informar sua idade. Então mostre na tela se ele é criança (menor de 13 anos), adolescente (entre 13 e 19 anos), adulto (entre 20 e 60 anos)
 ou idoso (mais de 60 anos).*/
main(){
    int idade;
	printf("informe sua idade : ");
	scanf("%d",&idade);
	if(idade < 13)
		printf("\ntu e crianca");
	if(idade >= 13 && idade <=19)
		printf("\ntu e adolescente");
	if(idade >= 20 && idade <= 60)
		printf("\ntu e adulto");
	if(idade>60)
		printf("\ntu e idoso");
}