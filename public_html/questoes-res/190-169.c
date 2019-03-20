#include <stdio.h>
#include<math.h>
main () {
    float a1, r, n, an, sn;
    printf("\nDigite o valor de A1: ");
    scanf("%f", & a1);
    printf("\nDigite o valor de R: ");
    scanf("%f", & r);
    printf("\nDigite o valor de N: ");
    scanf("%f", & n);
    an = a1+r*(n-1);
    sn = (a1+an)*n/2;
    printf("\nTermo An e: %f", an);
    printf("\nSomatorio e: %f", sn);
    }
