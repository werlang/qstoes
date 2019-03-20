/**Escreva um programa que tenha duas variáveis globais. Então crie uma função
que peça para o usuário digitar nomes, idade, e salários de funcionários de uma empresa.
Esta função deve atribuir à primeira variável global o nome do funcionário mais antigo,
e para a segunda o nome do funcionário com maior salário. Mostre na função main estes dois nomes, após a chamada da função.**/
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
    for(i=0;i<5;i++){/// este for serve para digitar a idade e o salário
        printf("\n\n Idade do funcionario %i: ",i+1);
        scanf("%i",&idad[i]);
        printf("\n\n Salário do funcionario %i: ",i+1);
        scanf("%f",&sal[i]);
        if(idad[i]>velho){/// faz as comparações para pegar o mais velho
            velho=idad[i];
            strcpy(antigo,nome[i]);/// armazena o nome do mais velho
        }
        if(sal[i]>maior){/// faz as comparações para pegar o que ganha mais
            maior=sal[i];
            strcpy(salario,nome[i]);/// armazena o nome do que ganha mais
        }
    }
    system("cls");/// limpa a tela
    printf(" %s é o mais velho com %i anos\n %s é o que ganha mais R$%.2f",antigo,velho,salario,maior);
}
int main(){
        setlocale(LC_ALL,"portuguese");/// somente para aceitar caracteres com acento ou ç
        main_ant_sal();/// puxa a função e executa ela
        return 0;
}
