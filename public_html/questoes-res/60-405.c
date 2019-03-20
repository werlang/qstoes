#include<stdlib.h>
#include<time.h>
#include<stdio.h>

/* Preencher em uma matriz 10x10 o conteúdo das tabuadas do 1 ao 10 e mostrar na tela o conteúdo desta matriz linha a linha. */
main(){
    int i,j;
    int mat[10][10];
    for (i=0 ; i<10 ; i++){
        for (j=0 ; j<10 ; j++){
            mat[i][j] = (j+1)*(i+1);
            if (mat[i][j] < 10)
                printf("0");
            printf("%i ",mat[i][j]);
        }
        printf("\n");
    }
}
