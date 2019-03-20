#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3,n4;
    printf("Informe quantos km/l seu carro faz\n");
    scanf("%f",&n1);
    printf("Informe a distancia percorrida\n");
    scanf("%f",&n2);
    printf("Informe o valor do litro de gasolina em nosso pais de corruptos\n");
    scanf("%f",&n3);
    n4=(n2/n1)*n3;
    printf("Voce gastara %f temers para realizar o trajeto\n",n4);
    return 0;
}
