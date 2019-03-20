#include<stdio.h>
    main(){
        int timeA, timeB;

        printf("Gols marcados pelo time A: ");
        scanf("%i",&timeA);

        printf("Gols marcados pelo time B: ");
        scanf("%i",&timeB);

        if(timeA > timeB){
                printf("O vencedor foi o time A ");
        }
        if(timeA < timeB){
                printf("O vencedor foi o time B");
        }
        if(timeA==timeB){
            printf("Houve empate");
        }
    }
