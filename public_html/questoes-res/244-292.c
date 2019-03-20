/**Escreva um programa que peça para o usuário escolher 6 números entre 1 e 60.
Realize a validação destes números. Então sorteie 6 números entre 1 e 60. Caso o
usuário acerte todos os 6 números informe que ele ganhou o primeiro prêmio. Caso
ele acerte 5 ou 4 dos números, informe que ele ganhou o segundo ou terceiro prêmio,
respectivamente. Os números inseridos e sorteados podem estar em qualquer ordem.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int n, num, i, y, z,k,cont=0;
    int vet[6], sort[6];
    for(i=0;i<6;i++){
        printf("Informe o %i numero: \n",i+1);
        scanf("%i",&vet[i]);
        while(vet[i]<1 || vet[i]>60 || cont>0){
            printf("Numero invalido, informe o %i numero: \n",i+1);
            scanf("%i",&vet[i]);
        }
    }
    for(y=0;y<6;y++){
        n=1+rand()%(60-1+1);
        sort[y]=n;
        printf("= %i =",sort[y]);
    }
    for(z=0;z<6;z++){
        for(k=0;k<6;k++){
            if(vet[z]==sort[k]){
                cont++;
            }
        }
    }
    if(cont==6)
        printf("\n Parabens voce ganhou o primeiro premio");
    else if(cont==5)
        printf("\n Parabens voce ganhou o segundo premio");
    else if(cont==4)
        printf("\n Parabens voce ganhou o terceiro premio");
    else
        printf("\n Que pena voce nao ganhou, tente novamente");
}
