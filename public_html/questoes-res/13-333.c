#include <stdio.h>
#include <stdlib.h>

main(){
    int x;
    int y;
    float z;
    printf("Questao 13\n\n - Digite o primeiro numero:\n");
    scanf("%i",&x);
    printf(" - Digite o segundo numero:\n");
    scanf("%i",&y);
    system("cls");
    z = x+y;
    printf("Resultado operacoes entre %d e %d \n",x,y);
    printf(" - SOMA: %.2f \n",z);
    z = x-y;
    printf(" - SUBITRACAO: %.2f \n",z);
    z = x*y;
    printf(" - MULTIPLICACAO: %.2f \n",z);
    z = x/y;
    printf(" - DIVISAO: %.2f \n",z);
    system("pause");
}
