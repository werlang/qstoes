#include <stdio.h>

main(void){
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a>b) {
        printf("Time A ganhou com %d gols", a);
    }
    if (b>a) {
        printf("Time B ganhou com %d gols", b);
    }
    else {
        printf("Empate");
    }
    system("pause");
    return 0;
    }
