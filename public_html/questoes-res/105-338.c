#include <stdio.h>
#include <stdlib.h>

main(){
    int x;
    float y;
    float z;
    printf("Questao 105\n\n - Digite o numero de pessoas na familia:\n");
    scanf("%i",&x);
    printf(" - Digite a renda total:\n");
    scanf("%f",&y);
    system("cls");
    z = y/x;
    printf("A renda percapita da familia e: %.2f \n",z);
    system("pause");
}
