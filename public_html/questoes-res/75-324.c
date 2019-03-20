/**Escreva um programa que mostre na tela um menu com quatro opções:
a - Consultar saldo
b - Realizar saque
c - Realizar depósito
d - Sair do programa.
O programa somente deverá sair quando o usuário escolher a última opção do menu.
Considere que o saldo inicia em 0 R$ e que caso as opções b ou c sejam escolhidas
o programa deverá pedir um valor para reduzir ou adicionar ao saldo. Caso a opção
a seja escolhida, mostre na tela o valor atual do saldo. A tarefa de limpar a tela
e mostrar o menu deverá ser executada por uma função.**/
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
    char op;
    float saldo=0;
void menu(){
    printf("Qual operação deseja fazer:\n a - Consultar saldo\n b - Realizar saque\n c - Realizar depósito\n d - Sair do programa.");
}
void escol(){
    float saq,dep;
    system("cls");
    switch(op){
    case 'a':
        printf("\n Seu Saldo é R$%.2f \n\n",saldo);
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
