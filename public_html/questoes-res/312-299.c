/**Escreva um programa que pe�a para o usu�rio informar um n�mero. Mostre na tela se este n�mero � primo ou n�o.**/
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
