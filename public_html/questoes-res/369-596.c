#include<stdio.h>

main(){
    int p,d1,d2,s;
    printf("Informe P (0 ou 1): ");
    scanf("%i",&p);
    printf("Informe D1: ");
    scanf("%i",&d1);
    printf("Informe D2: ");
    scanf("%i",&d2);

    s = d1+d2;
    if (p == 0){
        if (s%2 == 0)
            printf("Jogador 1 venceu.\n");
        else
            printf("Jogador 2 venceu.\n");
    }
    else{
        if (s%2 == 0)
            printf("Jogador 2 venceu.\n");
        else
            printf("Jogador 1 venceu.\n");
    }
}
