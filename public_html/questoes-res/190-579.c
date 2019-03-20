/*Faça um programa que dado um valor inicial A1, uma razão r,
e o número de termos n, calcule o termo An da PA. Com os mesmo
dados, encontre o somatório desta PA*/

#include<math.h>
#include<stdio.h>

main(){
    float A1, r, n, An, Sn;
    printf("digite um valor pra A1: \n");
    scanf("%f",&A1);
    printf("digite um valor pra razao: \n");
    scanf("%f",&r);
    printf("digite um valor para o numero de termos n: \n");
    scanf("%f",&n);

    An = (A1 + (n - 1) * r);
    Sn = (n*(A1 + An))/2;

    printf("valor de An: %.2f \n", An);
    printf("valor de Sn: %.2f \n",Sn);

    return 0;
}
