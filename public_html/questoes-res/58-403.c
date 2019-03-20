//Escreva um programa que peça para o usuário cadastrar em uma struct o nome idade e gênero de 5 pessoas. Então mostre na tela os dados de todas elas.

#include<stdio.h>
#include<strings.h>
struct Usuario{

	char nome[50];
	int idade;
	char genero;

};

int main() {
	struct Usuario users[5];
    int i;
	for(i = 0; i < 5; i ++) {
		fflush(stdin);
		printf("Nome: ");
		gets(users[i].nome);
		printf("Idade: ");
		scanf("%d", &users[i].idade);
		printf("Sexo(M/F): ");
		fflush(stdin);
		scanf("%c",&users[i].genero);
		//users[i].genero = getch();
//		printf("\n%c\n",users[i].genero);
	}

	for(i = 0; i < 5; i ++) {
		printf("Nome: %s\n",users[i].nome);
		printf("Idade: %d\n",users[i].idade);
		printf("Genero: %c\n\n",users[i].genero);
	}

}
