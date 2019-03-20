/**Escreva um programa que peça para o usuário informar um número. Mostre na tela se este número é primo ou não.**/
#include<stdio.h>
main(){
    int numero,i;
    int cont=0;
    printf("Informe um numero: ");
    scanf("%i",&numero);
    for(i=1; i<=numero; i++)
    {
    if(numero%i==0)
        cont++;
    }
     if(cont==2)
            printf("primo\n");
        else
            printf("nao eh primo\n");
}
