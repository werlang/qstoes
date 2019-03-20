/**Escreva um programa que peça para o usuário digitar números até que um número negativo seja digitado. Ao fim,
mostre na tela a diferença entre o maior valor e o menor, bem como a média dos pares e dos ímpares.**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, maior=0, menor=0, dif=0, contp=0, conti=0;
    int somap=0, somai=0, mediap=0, mediai=0;
    do{
        printf("Digite um numero:");
        scanf("%d", &n);
        if(n%2==0 && n>0){
            printf("Par\n");
            somap=somap+n;
            contp++;
        }
        else if(n%2!=0 && n>0){
            printf("Impar\n");
            somai=somai+n;
            conti++;
        }
        if(n>maior){
            maior=n;
            if(menor==0){
                menor=n;
            }
        }
        else if(n<menor && n>0){
            menor=n;
        }

    }while(n>0);
    dif=maior-menor;
    mediap=(float)somap/contp;
    mediai=(float)somai/conti;
    printf("maior: %d\nmenor: %d\n", maior, menor);
    printf("Diferenca entre (%d) e (%d) : %d\n", maior, menor, dif);
    printf("media par: %.2f\nmedia impar: %.2f", mediap, mediai);
    return 0;
}
