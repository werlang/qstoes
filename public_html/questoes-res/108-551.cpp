/*Escreva um programa que peça para o usuário cadastrar em uma struct o
nome idade e gênero de 5 pessoas. Então mostre na tela os dados de todas elas.*/

#include <stdio.h>
#include <string.h>

struct cadastro{
	char nome[5];
	int idade;
	char genero;
};

int main(){
	struct cadastro pessoas[5];
	int t=0, i;
	char genero;
	printf("Informe os dados: \n");
	do{
		printf("Nome:\n");
		gets(pessoas[t].nome);
		
		printf("Idade:\n");
		scanf("%i",&pessoas[t].idade);
		printf("Genero: \n");
		scanf(" %c",&pessoas[t].genero);
		fflush(stdin);//para tirar buffer do teclado colocado ou acima ou abaixo de onde esta dando erro"pulando"
		t++;
	} while (t<3);

	for(i=0; i<t; i++){
		printf("\nNome: %s\nIdade: %i\nGenero: %c",pessoas[i].nome, pessoas[i].idade, pessoas[i].genero);
	}
	return 0;
}
