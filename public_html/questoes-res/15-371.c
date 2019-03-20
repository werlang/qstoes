#include<stdio.h>

main(){
    int v1,v2,v3;
    printf("Informe o primeiro valor: ");
    scanf("%i",&v1);
    printf("Informe o segundo valor: ");
    scanf("%i",&v2);
    printf("Informe o terceiro valor: ");
    scanf("%i",&v3);

    if (v2>v1){
        printf("%i maior que %i\n",v2,v1);
    }
    if (v3>v2){
        printf("%i maior que %i\n",v3,v2);
    }
}
