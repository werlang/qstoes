/**Escreva um programa que mostre na tela um menu com quatro op��es:
a - Consultar saldo
b - Realizar saque
c - Realizar dep�sito
d - Sair do programa.
O programa somente dever� sair quando o usu�rio escolher a �ltima op��o do menu.
Considere que o saldo inicia em 0 R$ e que caso as op��es b ou c sejam escolhidas
o programa dever� pedir um valor para reduzir ou adicionar ao saldo. Caso a op��o
a seja escolhida, mostre na tela o valor atual do saldo. A tarefa de limpar a tela
e mostrar o menu dever� ser executada por uma fun��o.**/
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
    char op;
    float saldo=0;
void menu(){
    printf("Qual opera��o deseja fazer:\n a - Consultar saldo\n b - Realizar saque\n c - Realizar dep�sito\n d - Sair do programa.");
}
void escol(){
    float saq,dep;
    system("cls");
    switch(op){
    case 'a':
        printf("\n Seu Saldo � R$%.2f \n\n",saldo);
        break;
    case 'b':
        printf("\nDigite o valor do saque: ");
        scanf("%f",&saq);
        saldo-=saq;
        printf("\n voce ficou com R$%.2f de saldo\n\n",saldo);
        break;
    case 'c':
        printf("\nInforme o valor do deposito: ");
        scanf("%f",&dep);
        saldo+=dep;
        printf("\n Seu saldo ficou com R$%.2f\n\n",saldo);
        break;
    }
}
int main(){
    setlocale(LC_ALL,"portuguese");
    while(op !='d'){
        menu();
        op=getch();
        escol();
    }
    return 0;
}
