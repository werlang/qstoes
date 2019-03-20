#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main(){
    int m,b,a;
    int crime[5][6][12];
    int h;
    for (a=0 ; a<5 ; a++){
        printf("Ano %i:\n",a+1);
        for (b=0 ; b<6 ; b++){
            printf("Bairro %i:\n",b+1)
            for (m=0 ; m<12 ; m++){
                printf("Informe o numero de homicidios no mes %i: ",m+1);
                scanf("%i",&h);
                crime[a][b][m] = h;
            }
        }
    }

    int maior, mesp, soma;
    for (a=0 ; a<5 ; a++){
        printf("Mes mais perigoso no ano %i: ",a+1);
        for (m=0 ; m<12 ; m++){
            soma = 0;
            for (b=0 ; b<6 ; b++){
                soma += crime[a][b][m];
            }
            if (m == 0 || soma > maior){
                maior = soma;
                mesp = m+1;
            }
        }
        printf("%i\n",mesp);
    }

    int inicio, fim, bairrop;
    for (b=0 ; b<6 ; b++){
        inicio = 0;
        fim = 0;
        for (m=0 ; m<12 ; m++){
            inicio += crime[0][b][m];
            fim += crime[4][b][m];
        }
        if (b == 0 || fim-inicio > maior){
            maior = fim-inicio;
            bairrop = b;
        }
    }
    printf("O bairro %i foi o que mais aumentou a criminalidade.\n",bairrop);

}
