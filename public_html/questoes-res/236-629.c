#include<stdio.h>

main(){
    char tipo, tamanho;
    float valor, espacototal=0, total=0, imposto;

    while (espacototal < 25){
        printf("Tamanho da caixa [p/m/g]: ");
        scanf(" %c",&tamanho);
        printf("Valor declarado: ");
        scanf("%f",&valor);
        printf("Tipo do produto [l/e/r]: ");
        scanf(" %c",&tipo);

        if (tipo == 'l')
            imposto = 0;
        else if (tipo == 'e')
            imposto = 0.6 * valor;
        else if (tipo == 'r')
            imposto = 0.15 * valor;

        total += imposto;
        printf("Imposto pago por esta caixa: R$ %.2f\n",total);
    }
    printf("\nTotal de imposto pago: R$ %.2f\n",total);
}
