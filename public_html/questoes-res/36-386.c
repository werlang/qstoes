/**Escreva um programa que mostre na tela um menu com as op��es:
a - Consultar saldo, b - Realizar dep�sito, c - Realizar saque, d - Sair.
O programa dever� sair somente quando o usu�rio escolher a op��o d.
Caso ele escolha as op��es b ou c, pe�a um valor, e atualize o saldo de acordo com o valor informado.
O saldo inicial dever� ser 0. Utilize a fun��o system("cls") para limpar a tela.**/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main(void){
    float saldo=0, deposito, saque, sair;
    char opcao;
    while(opcao!='d'){
        printf("\nInforme a operacao que deseja fazer: \n");
        printf(" a-consultar saldo\n b-Realizar deposito\n c-realizar saque\n d-sair\n");
        opcao=getche();
        system("cls");
        if(opcao=='a'){
            printf("\nSeu saldo e de R$%.2f\n",saldo);
        }
        else if(opcao=='b'){
            printf("\nInforme o valor do deposito: \n");
            scanf("%f",&deposito);
            saldo=saldo+deposito;
            printf("\n Seu saldo esta atualizado e de R$%.2f\n",saldo);
        }
        else if(opcao=='c'){
            printf("\nInforme o valor do saque: \n");
            scanf("%f",&saque);
            saldo=saldo-saque;
            printf("\n Seu saldo depois do saque e de R$%.2f\n",saldo);
        }
    }
}
