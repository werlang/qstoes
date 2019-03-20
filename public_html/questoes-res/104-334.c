#include <stdio.h>
#include <stdlib.h>

main(){
    int x;
    float y;
    float z;
    printf("Questao 104\n\n - Digite o valor da conta:\n");
    scanf("%i",&x);
    printf(" - Digite a porcentagem de juros:\n");
    scanf("%f",&y);
    system("cls");
    z = y/100;
    z *= x;
    printf("JUROS: %.2f \n",z);
    z = x+z;
    printf("VALOR: %.2f \n",z);
    system("pause");
}
