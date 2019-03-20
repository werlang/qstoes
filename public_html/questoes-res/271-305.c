/**Escreva um programa que pergunte para o usuário quantos dias tem o mês atual, bem como em que dia da
semana ele inicia. Então preencha em uma matriz bidimensional o calendário do mês atual, conforme o exemplo abaixo.
Inicia em: Sexta 	Dias: 31 **/
#include<stdio.h>
#include<stdlib.h>

main(){
    int mat[6][7];
    int i,j,dia,sem,d=1;
    printf("Dia da semana :\n 1 - Domingo\n 2 - Seguda\n 3 - Terca\n 4 - Quarta\n 5 - Quinta\n 6 - Sexta\n 7 - Sabado \n");
    scanf("%i",&sem);
    printf("Quantos dias tem o mes atual: ");
    scanf("%i",&dia);
    printf("  D   S   T   Q   Q   S   S\n\n");
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
                if(d<=dia){
                    if(i==0){
                        if(j==(sem-1)){
                            mat[i][j]=d;
                            d++;
                            printf("  %i ",mat[i][j]);
                        }
                        else if(j>(sem-1)){
                            mat[i][j]=d;
                            d++;
                            printf("  %i ",mat[i][j]);
                        }
                        else
                            printf("    ");
                    }
                    else{
                        if(d<10){
                            mat[i][j]=d;
                            d++;
                            printf("  %i ",mat[i][j]);
                        }
                        else{
                            mat[i][j]=d;
                            d++;
                            printf(" %i ",mat[i][j]);
                        }
                    }
                }
        }
        printf("\n\n");
    }
}
