#include<stdio.h>

main() {
    int i,valor,maior=0,menor=0;
    for (i=0;i<=5;i++) {
        printf("informe o valor de %i:",i+1);
        scanf("%i",&valor);
        if(valor>maior){
            maior=valor;
        }
        if(i==0 || valor<menor){
            menor=valor;
        }
    }
    printf("valor Maior: %i\n",maior);
    printf("valor Menor: %i\n",menor);



}
