/**Escreva um programa que pe�a para o usu�rio digitar n�meros indefinidamente.
Entre cada n�mero o usu�rio deve responder uma confirma��o se deseja continuar.
Caso responda que n�o, o programa deve informar na tela o maior n�mero, o menor,
e a m�dia dos n�meros que foram fornecidos.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    int n=1, maior=1, menor=10*n;
    float media=0,soma=0,cont=0;
    char opcao;
    while( opcao!='n' ){
        printf("Digite um numero: \n\n");
        scanf("%i",&n);
        printf(" Voce deseja continuar parte (s) para sim ou (n) para nao: \n\n");
        scanf(" %c",&opcao);
        if(n>=0 || n<0){
            soma=soma+n;
            cont++;
            if(n>maior){
                maior=n;
            }
            if(menor>n){
                menor=n;
            }
        }
    }
    media=(float)soma/cont;
    printf("A media dos numeros digitados e %.2f\n\n",media);
    printf("%i e maior \n %i e menor",maior,menor);
}
