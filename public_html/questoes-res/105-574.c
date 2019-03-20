#include<stdio.h>
main(){
    float a, b, c;
    printf("\nInforme sua renda: ");
    scanf("%f", & a);
    printf("\nInforme o numero de pessoas: ");
    scanf("%f", & b);
    c = (float) a/b;
    printf("\nRenda Per Capita: %2.f", c);
}
