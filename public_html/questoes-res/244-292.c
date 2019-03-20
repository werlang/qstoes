/**Escreva um programa que pe�a para o usu�rio escolher 6 n�meros entre 1 e 60.
Realize a valida��o destes n�meros. Ent�o sorteie 6 n�meros entre 1 e 60. Caso o
usu�rio acerte todos os 6 n�meros informe que ele ganhou o primeiro pr�mio. Caso
ele acerte 5 ou 4 dos n�meros, informe que ele ganhou o segundo ou terceiro pr�mio,
respectivamente. Os n�meros inseridos e sorteados podem estar em qualquer ordem.**/
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
