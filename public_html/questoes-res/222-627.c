/**Escreva um programa que peça para o usuário digitar números indefinidamente. Entre cada número o usuário deve responder
 uma confirmação se deseja continuar. Caso responda que não, o programa deve informar na tela o maior número, o menor, e a
 média dos números que foram fornecidos.**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x=0, maior=0, menor=0, cont=0, soma=0;
    char op;
    do{
            printf("digite um numero: ");
            scanf("%d", &n);
            printf("Deseja continuar SIM(s) ou NAO(n): ");
            scanf(" %c", &op);
                if(x==0){
                maior=n;
                menor=n;
                x++;
            }
            else if(n>maior){
                maior=n;
            }
            else if(n<menor){
                menor=n;
            }
            cont++;
            soma=soma+n;
            while(op!='n' && op!='s'){
            printf("Invalido, N para sair ou S para continuar ");
            scanf(" %c", &op);
            }
                if(op=='n'){
                break;
                }

    }
    while(n>=0 || n<=0);
    float media;
    media=(float)soma/cont;
    printf("maior: %d\nmenor: %d\nmedia: %.2f", maior, menor, media);
    return 0;
}
