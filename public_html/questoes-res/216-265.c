/**Escreva um programa que peça para o usuário digitar números até que um número negativo seja digitado.
Ao fim, mostre na tela a diferença entre o maior valor e o menor, bem como a média dos pares e dos ímpares.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    int n=1;
    int maior=0,menor=n;
    int soma=0,soma2=0,dif=0;
    int cont=0,cont2=0;
    float media=0,media2=0;
    while(n>=0){
        printf("Digite um numero: \n");
        scanf("%i",&n);
        if(n>maior){
            maior=n;
        }
        if(menor>n){
            menor=n;
        }
        if(n%2==0){
            soma=soma+n;
            cont++;
        }
        else{
            soma2=soma2+n;
            cont2++;
        }
    }
    dif=maior-menor;
    media=(float)soma/cont;
    media2=(float)soma2/cont2;
    printf("%i maior \n %i menor\n e a diferenca entre eles e %i\n",maior,menor,dif);
    printf("%.2f media de numeros pares \n",media);
    printf("%.2f media de numeros impares \n",media2);
}
