#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3;
    printf("Informe 2 algarismos!\n");
    scanf("%f",&n1);
    scanf("%f",&n2);
    n3=n1+n2;
    printf("O resultado da adicao eh %f\n",n3);
    n3=n1*n2;
    printf("O resultado da multiplicacao eh %f\n",n3);
    n3=n1/n2;
    printf("O resultado da divisao eh %f\n",n3);
    return 0;
}
