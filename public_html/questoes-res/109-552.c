#include<stdio.h>

struct data {
    int dia, mes, ano;
};

struct pessoa {
    char nome[50];
    char genero;
    struct data datanasc;
};

main(){
    struct pessoa p[5];
    int i;
    for (i=0 ; i<5 ; i++){
        printf("Informe o nome: ");
        gets(p[i].nome);
        printf("Informe o genero: ");
        scanf("%c",&p[i].genero);
        printf("Informe o dia, mes e ano do nascimento: ");
        scanf("%i",&p[i].datanasc.dia);
        scanf("%i",&p[i].datanasc.mes);
        scanf("%i",&p[i].datanasc.ano);
        fflush(stdin);
    }
    printf("Dados cadastrados:\n");
    for (i=0 ; i<5 ; i++){
        printf("Nome: %s\n",p[i].nome);
        printf("Genero: %c\n",p[i].genero);
        printf("Data de nascimento: %i/%i/%i\n\n", p[i].datanasc.dia, p[i].datanasc.mes, p[i].datanasc.ano);
    }
}
