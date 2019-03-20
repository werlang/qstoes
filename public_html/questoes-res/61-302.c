#include <stdio.h>
main (){
//Escreva um algoritmo que peça para o usuário preencher uma matriz de 3x5 com números.
//Fazer a validação para só permitir números positivos. Então mostrar na tela o
//resultado do somatório dos números de cada coluna.
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
