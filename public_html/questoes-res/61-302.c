#include <stdio.h>
main (){
//Escreva um algoritmo que pe�a para o usu�rio preencher uma matriz de 3x5 com n�meros.
//Fazer a valida��o para s� permitir n�meros positivos. Ent�o mostrar na tela o
//resultado do somat�rio dos n�meros de cada coluna.
int mat[3][5], i, j, numeros, soma;

    for ( i=0; i<3; i++ ) {
        for ( j=0; j<5; j++ ){
            scanf ( "%d",& numeros );

            while (numeros <= 0){
                scanf ( "%d",& numeros );
            }
            mat[i][j] = numeros;
        }
    }

    for ( i=0; i<3; i++ ) {
        for ( j=0; j<5; j++ ){
            printf("%d ",mat[i][j]);
        }
        printf ("\n");
    }

    for ( j=0; j<5; j++) {
        soma=0;
        for ( i=0; i<3; i++) {
            soma+=mat[i][j];
        }
        printf ("%d ",soma);
    }

}
