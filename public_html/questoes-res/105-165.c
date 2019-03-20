#include<stdio.h>
#include<math.h>
main(){
    float renda, npessoas, percapita;
    printf("\nInforme sua renda: ");
    scanf("%f", & renda);
    printf("\nInforme o numero de pessoas: ");
    scanf("%f", & npessoas);
    percapita = (float) renda/npessoas;
    printf("\nRenda Per Capita: %2.f", percapita);
    }
