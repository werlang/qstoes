/**Escreva um programa que peça para o usuário informar três números, então gere 5000 números aleatórios entre o maior e
o menor informado pelo usuário. Ao fim, mostre na tela quantos números são maiores que o número intermediário informado.**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i, j, n, cont=0, naleatorio, maior=0, menor=0, medio=0;

    for(i=0; i<3; i++){
    printf("informe o %d numero: ", i+1);
    scanf("%d", &n);
        if(i==0){
        maior=n;
        menor=n;
        }
        if(n>maior){
            medio=maior;
            maior=n;
        }
        else if(n<menor){
            medio=menor;
            menor=n;
        }
        else{
            medio=n;
        }

    }
    for(j=0; j<10; j++){
        naleatorio=rand()%(maior-menor+1)+menor;
        printf("%d | ", naleatorio);
        if(medio<naleatorio){
        cont++;
        }
    }

    printf("\nmaior: %d\nmedio: %d\nmenor: %d\nexiste %d numeros maior que %d", maior, medio, menor, cont, medio);
    return 0;
}
