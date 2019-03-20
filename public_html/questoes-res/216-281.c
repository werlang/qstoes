/*Escreva um programa que peça para o usuário digitar números até que um número negativo seja digitado.
Ao fim, mostre na tela a diferença entre o maior valor e o menor, bem como a média dos pares e dos ímpares.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main (){
    int n,menor,maior,contpar=0,contimpar=0,par=0,impar=0,diferenca,mediapar,mediaimpar;
    printf("digite um numero: ");
    scanf("%i",&n);
    menor=n;
    maior=n;
    printf("%i\n",n);
    printf("%i\n",menor);
    printf("%i\n",maior);
    while(n>0){
        if (n%2==0){
            contpar++;
            par += n;
        }
        else{
            contimpar++;
            impar += n;
        }
        if(n>maior){
            maior=n;
        }
        else if(n<menor){
            menor=n;
        }
        printf("digite um numero: ");
        scanf("%i",&n);
    }
    diferenca=maior - menor;
    mediapar=par / contpar;
    mediaimpar=impar / contimpar;
    printf("mediapar: %i\n",mediapar);
    printf("mediaimpar: %i\n",mediaimpar);
    printf("diferenca do maior pro menor: %i\n",diferenca);

}

