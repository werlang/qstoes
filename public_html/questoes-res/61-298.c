/**Escreva um algoritmo que pe�a para o usu�rio preencher uma matriz de 3x5 com n�meros.
Fazer a valida��o para s� permitir n�meros positivos.
Ent�o mostrar na tela o resultado do somat�rio dos n�meros de cada coluna.**/
#include<stdio.h>

main(){
    int mat[3][5];
    int n,y,i,soma;
    for(i=0;i<3;i++){
        for(y=0;y<5;y++){
            printf("Informe o valor: \n");
            scanf("%i",&n);
            while(n<0){
                printf("Numero invalido, Digite um valor positivo: \n");
                scanf("%i",&n);
            }
            mat[i][y]=n;
        }
    }
    for(y=0;y<5;y++){
        soma=0;
        for(i=0;i<3;i++){
            soma+=mat[i][y];
        }
        printf(" %i |",soma);
    }
}
