/**Escreva um programa que tenha duas vari�veis globais. Ent�o crie uma fun��o
que pe�a para o usu�rio digitar nomes, idade, e sal�rios de funcion�rios de uma empresa.
Esta fun��o deve atribuir � primeira vari�vel global o nome do funcion�rio mais antigo,
e para a segunda o nome do funcion�rio com maior sal�rio. Mostre na fun��o main estes dois nomes, ap�s a chamada da fun��o.**/
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
char antigo[10], salario[10];
void main_ant_sal(){
    int i,velho=0,idad[5];
    float sal[5],maior=0;
    char nome[5][10];
    for(i=0;i<5;i++){/// digita o nomes dos funcionarios
        printf("\n Nome do funcionario %i: ",i+1);
        gets(nome[i]);
    }
    for(i=0;i<5;i++){/// este for serve para digitar a idade e o sal�rio
        printf("\n\n Idade do funcionario %i: ",i+1);
        scanf("%i",&idad[i]);
        printf("\n\n Sal�rio do funcionario %i: ",i+1);
        scanf("%f",&sal[i]);
        if(idad[i]>velho){/// faz as compara��es para pegar o mais velho
            velho=idad[i];
            strcpy(antigo,nome[i]);/// armazena o nome do mais velho
        }
        if(sal[i]>maior){/// faz as compara��es para pegar o que ganha mais
            maior=sal[i];
            strcpy(salario,nome[i]);/// armazena o nome do que ganha mais
        }
    }
    system("cls");/// limpa a tela
    printf(" %s � o mais velho com %i anos\n %s � o que ganha mais R$%.2f",antigo,velho,salario,maior);
}
int main(){
        setlocale(LC_ALL,"portuguese");/// somente para aceitar caracteres com acento ou �
        main_ant_sal();/// puxa a fun��o e executa ela
        return 0;
}
