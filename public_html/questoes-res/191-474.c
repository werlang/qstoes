#include<stdio.h>

main(){
    int s, m, h, d;
    printf("Informe a quantidade de segundos: ");
    scanf("%i",&s);

    m = s/60;
    s = s%60;

    h = m/60;
    m = m%60;

    d = h/24;
    h = h%24;

    printf("%i dias\n%i horas\n%i minutos\n%i segundos",d,h,m,s);
}
