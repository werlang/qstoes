/*Elabore um programa que peça para o usuário inserir 10 valores em um vetor. Após, mostre na tela todos os valores que o
usuário digitou em ordem crescente*/
#include<stdio.h>
main()
{
    int i,j,vet[10],valor, aux;
    for(i=0; i<10; i++)
    {
        printf("informe o (%i) valor\n >>>",i+1);
        scanf("%i",&valor);
        vet[i]=valor;
    }
    for(i=0; i<9; i++)
    {
        for(j=i+1; j<10;j++)
        {
            if(vet[i]>vet[j])
            {
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
    for(i=0; i<10; i++)
    {
        printf("%i ", vet[i]);
    }
}
