#include<stdio.h>

main() {
       float n1,n2,soma;

    printf(" digite a 1 nota: ");
    scanf("%f",&n1);
    printf(" digite a 2 nota: ");
    scanf("%f",&n2);

    soma=(n1+n2)/2;

    if(soma>6){
        printf("aprovado");
    }
    else{
        printf("reprovado");
    }



}
