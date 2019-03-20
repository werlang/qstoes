#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

void menu(){
    system("cls");
    printf("a - Consultar saldo\nb - Realizar saque\nc - Realizar depósito\nd - Sair\n\nEscolha uma opção: ");
}

main(){
    setlocale(LC_ALL,"portuguese");
    char op;
    float saldo = 0;
    float valor;
    while(op != 'd'){
        menu();
        op = getche();
        if (op == 'a'){
            printf("\nSaldo: R$ %.2f",saldo);
        }
        if (op == 'b'){
            printf("\nInforme o valor para o saque: ");
            scanf("%f",&valor);
            saldo -= valor;
            printf("Saque efetuado com sucesso. Saldo atual: R$ %.2f",saldo);
        }
        if (op == 'c'){
            printf("\nInforme o valor para o depósito: ");
            scanf("%f",&valor);
            saldo += valor;
            printf("Depósito efetuado com sucesso. Saldo atual: R$ %.2f",saldo);
        }
        getch();
    }
}
