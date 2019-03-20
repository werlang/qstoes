#include <stdio.h>
main(){
    float A,B,C;
    printf("Informe o valor da conta:");
    scanf("%f",&A);
    printf("Informe a porcentagem do juros:");
    scanf("%f",&B);
    C=(A/100)*B;
    printf("O valor dos juros e %.2f e total da conta e %.2f\n",C,C+A);

}
