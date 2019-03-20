#include<stdio.h>

main(){
    int h1,m1,s1,h2,m2,s2;
    printf("Informe o tempo atual:\n");
    printf("Horas: ");
    scanf("%i",&h1);
    printf("Minutos: ");
    scanf("%i",&m1);
    printf("Segundos: ");
    scanf("%i",&s1);

    printf("\nInforme outro horario:\n");
    printf("Horas: ");
    scanf("%i",&h2);
    printf("Minutos: ");
    scanf("%i",&m2);
    printf("Segundos: ");
    scanf("%i",&s2);

    int h = h2 - h1;
    int m = m2 - m1;
    int s = s2 - s1;

    if (s < 0){
        s = s + 60;
        m = m - 1;
    }
    if (m < 0){
        m = m + 60;
        h = h - 1;
    }
    if (h < 0){
        h = h + 24;
    }

    printf("Faltam para o segundo horario:\n %ih %im %is",h,m,s);
}
