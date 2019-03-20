#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Escreva um programa que peça para o usuário cadastrar em uma struct o nome data de mascimento e gênero de 5 pessoas.
//Então mostre na tela os dados de todas elas. A data de nascimento deverá ser uma struct com os campos dia, mês e ano.
struct data{
    int dia, mes, ano;
};

struct pessoa {
    char nome[50];
    struct data datan;
    char genero[10];
};

main(){
    int x,i;
    struct pessoa p[5];
    for (i=0;i<5;i++){
        printf("Informe o nome: ");
        gets(p[i].nome);
        fflush(stdin);
        printf("Informe a data nascimento (dia): ");
        scanf("%i",&p[i].datan.dia);
        fflush(stdin);
        printf("Informe a data nascimento (mes): ");
        scanf("%i",&p[i].datan.mes);
        fflush(stdin);
        printf("Informe a data nascimento (ano): ");
        scanf("%i",&p[i].datan.ano);
        fflush(stdin);
        printf("Informe o genero: ");
        gets(p[i].genero);
        fflush(stdin);
    }
    for (i=0;i<5;i++){
        printf("\nNome: %s",p[i].nome);
        if(p[i].datan.dia < 10 && p[i].datan.mes < 10){
            printf("\nData Nascimento: 0%i/0%i/%i",p[i].datan.dia, p[i].datan.mes, p[i].datan.ano);
        }
        if(p[i].datan.dia >= 10 && p[i].datan.mes < 10){
            printf("\nData Nascimento: %i/0%i/%i",p[i].datan.dia, p[i].datan.mes, p[i].datan.ano);
        }
        if(p[i].datan.dia < 10 && p[i].datan.mes >= 10){
            printf("\nData Nascimento: 0%i/%i/%i",p[i].datan.dia, p[i].datan.mes, p[i].datan.ano);
        }
        if(p[i].datan.dia >= 10 && p[i].datan.mes >= 10){
            printf("\nData Nascimento: %i/%i/%i",p[i].datan.dia, p[i].datan.mes, p[i].datan.ano);
        }
        printf("\nGenero: %s",p[i].genero);
        printf("\n");
    }
}
