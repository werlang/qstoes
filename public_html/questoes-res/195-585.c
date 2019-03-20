#include<stdio.h>

main(){
    int valor, maior, menor;
    printf("Informe o primeiro valor:");
    scanf("%i",&valor);
    maior = valor;
    menor = valor;

    printf("Informe o segundo valor:");
    scanf("%i",&valor);
    if (valor > maior){
        maior = valor;
    }
    if (valor < menor){
        menor = valor;
    }

    printf("Informe o terceiro valor:");
    scanf("%i",&valor);
    if (valor > maior){
        maior = valor;
    }
    if (valor < menor){
        menor = valor;
    }

    printf("Maior valor: %i\n",maior);
    printf("Menor valor: %i\n",menor);
}
