/**Escreva um algoritmo que peça para o usuário preencher uma matriz de 3x5 com números.
Fazer a validação para só permitir números positivos.
Então mostrar na tela o resultado do somatório dos números de cada coluna.**/
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
