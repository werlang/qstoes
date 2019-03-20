#include<stdio.h>
#include<math.h>
main(){
    int a, b, c, d, e;
    float f;
    printf("Informe um Numero:");
    scanf("%i",& a);
    printf("Informe outro Numero:");
    scanf("%i",& b);
    c = (a+b);
    d = (a-b);
    e = (a*b);
    f = (float)a/b;
    printf("\nAdicao: %i", c);
    printf("\nSubtracao: %i", d);
    printf("\nMultiplicacao: %i", e);
    printf("\nDivisao: %.1f", f);
    }
