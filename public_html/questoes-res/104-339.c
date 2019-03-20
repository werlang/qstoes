#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3;
    printf("Informe o valor da conta\n");
    scanf("%f",&n1);
    printf("Informe agora a porcentagem dos juros da conta\n");
    scanf("%f",&n2);
    n3=(n1/100)*n2;
    printf("O valor dos juros eh %f e total da conta eh %f\n",n3,n3+n1);
    return 0;
}
