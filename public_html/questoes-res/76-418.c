#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

float saldo = 0;

void menu(){
    system("cls");
    printf("1 - Consultar saldo\n2 - Realizar saque\n3 - Realizar dep�sito\n4 - Sair\n\nEscolha uma op��o: ");
}

void saque(){
    float valor;
    printf("\nInforme o valor para o saque: ");
    scanf("%f",&valor);
    saldo -= valor;
    printf("Saque efetuado com sucesso. Saldo atual: R$ %.2f",saldo);
    getch();
}

void consulta(){
    printf("\nSaldo: R$ %.2f",saldo);
    getch();
}

void deposito(){
    float valor;
    printf("\nInforme o valor para o dep�sito: ");
    scanf("%f",&valor);
    saldo += valor;
    printf("Dep�sito efetuado com sucesso. Saldo atual: R$ %.2f",saldo);
    getch();
}

main(){
    char op;
    while(op != '4'){
        menu();
        op = getche();
        if (op == '1')
            consulta();
        if (op == '2')
            saque();
        if (op == '3')
            deposito();
    }
}

