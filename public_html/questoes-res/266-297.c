/**Escreva um programa que preencha e mostre na tela uma matriz de 10 linhas por 100 colunas com números aleatórios.
Na primeira linha deverão conter números entre 1 e 10, na segunda entre 11 e 20, na terceira entre 21 e 30, e assim por diante.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int mat[10][100];
    int i,y;
    int menor=1, maior=10;
    for(i=0;i<10;i++){
        for(y=0;y<100;y++){
            mat[i][y]=menor+rand()%(maior-menor+1);
        }
        menor+=10;
        maior+=10;
    }

    for(i=0;i<10;i++){
        for(y=0;y<100;y++){
            printf(" %i ",mat[i][y]);
        }
        printf("\n\n");
    }
}
