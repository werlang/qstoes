#include<stdio.h>
#include<stdlib.h>
/*Escreva um programa que peça para o usuário informar 10 números.
Então mostre na tela o somatório do primeiro pelo último,
do segundo pelo penúltimo, e assim por diante.*/

main()
{
    int vet[10],n,k,i;

        for(i=0;i<10;i++)
        {
            scanf("%i",&n);
                vet[i]=n;

        }
        int l,soma5=0,soma4=0,soma3=0,soma2=0,soma1=0;


    for(k=0;k<5;k++)
    {
        soma5 = vet[9]+vet[0];
        soma4 = vet[8]+vet[1];
        soma3 = vet[7]+vet[2];
        soma2 = vet[6]+vet[3];
        soma1 = vet[5]+vet[4];


    }
        printf("\nsoma ultimo + primeiro %i",soma5);
        printf("\nsoma penultimo + segundo %i",soma4);
        printf("\nsoma antipenultimo + terceiro %i",soma3);
        printf("\nsoma setimo + quarto %i",soma2);
        printf("\nsoma sexto + quinto %i",soma1);
}

