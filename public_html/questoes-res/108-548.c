/**Escreva um programa que peça para o usuário cadastrar em uma struct o nome
idade e gênero de 5 pessoas. Então mostre na tela os dados de todas elas.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct usuario{
    char nome[50];
    int idade;
    char genero;
};

int main(){
    struct usuario p[5];
    int i;
    for(i=0;i<5;i++){
        fflush(stdin);
        printf("\nInforme o nome usuario %i:",i+1);
        gets(p[i].nome);
        printf("\nInfome a idade do usuario %i:",i+1);
        scanf("%i",&p[i].idade);
        printf("\nInforme o genero do usuario (m)masculino e (f)feminino %i:",i+1);
        p[i].genero=getche();
    }
    printf("\nConteudo do cadastro:\n");
    for(i=0;i<5;i++){
        printf("Nome usuario %i: %s\n",i+1,p[i].nome);
        printf("Idade usuario %i: %i\n",i+1,p[i].idade);
        printf("Genero usuario %i: %c\n\n",i+1,p[i].genero);

    }
    return 0;
}
