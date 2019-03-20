#include<stdio.h>

main(){
    int dias;
    int i;
    char proximo;
    int chuvas[100][12];
    int anos=0;

    while (proximo != 'n' && anos < 100){
        for (i=0 ; i<12 ; i++){
            printf("Quantos dias de chuva teve no mes %i do ano? ",i+1);
            scanf("%i",&dias);
            while (dias<0 || dias>30){
                printf("Invalido. Informe um numero entre 0 e 30: ");
                scanf("%i",&dias);
            }
            chuvas[anos][i] = dias;

        }
        printf("Deseja informar o proximo ano? (s/n) ");
        proximo = getche();
        printf("\n");
        anos++;
    }

    int j;
    int soma=0;
    int maior=0;
    int vencedor;
    for (j=0 ; j<12 ; j++){
        soma=0;
        for (i=0 ; i<anos ; i++){
            soma+=chuvas[i][j];
        }
        if (soma > maior){
            maior = soma;
            vencedor = j;
        }
    }
    printf("O mes com mais dias chuvosos foi: %i",vencedor+1);
}

