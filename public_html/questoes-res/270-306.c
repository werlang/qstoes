/**Escreva um programa que armazene atrav�s de repeti��es em uma matriz 9x9 n�meros conforme o padr�o abaixo
**/
#include<stdio.h>
#include<stdlib.h>

main(){
    int i,j;
    int mat[9][9], aux=0;
    for(i=8;i>=0;i--){
        for(j=8;j>=0;j--){
            mat[i][j]=(i+1)-j;
            if(mat[i][j]<0)
                mat[i][j]=0;
            printf(" %i ",mat[i][j]);
        }
        printf("\n\n");
    }
}
