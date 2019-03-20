#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Escreva um programa que peça para o usuário cadastrar
//em uma struct o nome idade e gênero de 5 pessoas. Então mostre na tela os dados de todas elas.

struct pessoa {
    char nome[50];
    int idade;
    char genero[10];
};

main(){
    int x,i;
    struct pessoa p[5];
    for (i=0;i<5;i++){
        printf("Informe o nome:");
        gets(p[i].nome);
        printf("Informe a idade:");
        scanf("%i",&p[i].idade);
        fflush(stdin);
        printf("Informe o genero:");
        gets(p[i].genero);
    }
    for (i=0;i<5;i++){
        printf("\nNome: %s",p[i].nome);
        printf("\nIdade: %i",p[i].idade);
        printf("\nGenero: %s",p[i].genero);
        printf("\n");
    }
}
