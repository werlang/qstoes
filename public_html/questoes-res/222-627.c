/**Escreva um programa que pe�a para o usu�rio digitar n�meros indefinidamente. Entre cada n�mero o usu�rio deve responder
 uma confirma��o se deseja continuar. Caso responda que n�o, o programa deve informar na tela o maior n�mero, o menor, e a
 m�dia dos n�meros que foram fornecidos.**/
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
