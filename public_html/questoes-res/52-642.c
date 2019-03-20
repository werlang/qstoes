/*Escreva um programa que peça para o usuário informar números até
que o usuário digite 0 ou 10 números sejam informados.
Então mostre na tela a lista dos que são divisíveis por 2, depois por 3,
depois por 4, até o 10.*/

#include<stdio.h>

main(){
    int vet[10], i, a=1;

    for(i=0; i<10; i++){
    printf("digite um valor: \n");
    scanf("%i", &vet[i]);
    if(vet[i]==0)
        break;
    }

    for(i=0; i<10; i++){
    if(vet[i]%a==0){
        printf("Numero %i divisivel por %i \n",vet[i], a);
        a++;
    }
    }
}
