#include<stdio.h>
#include<conio.h>
#include<locale.h>
 main(){
     setlocale(LC_ALL,"portuguese");
     float vendas[10][250]={0};
     int cont_vendas[10]={0};
     int vend, cont=0;
     float valor=999;

     while(valor > 0 && cont < 250){
         printf("Informe o número do vendedor: ");
         scanf("%i",&vend);
         while (vend < 0 || vend > 9){
             printf("Vendedor invalido. Informe um numero entre 0 e 9: ");
             scanf("%i",&vend);
         }
         printf("Informe o valor do produto: ");
         scanf("%f",&valor);
         if (valor > 0){
             vendas[vend][ cont_vendas[vend] ] = valor;
             cont_vendas[vend]++;
             cont++;
         }
     }
     int i,j;
     printf("Produtos vendidos pelos vendedores:\n");
     for (i=0 ; i<10 ; i++){
        if (cont_vendas[i] > 0){
            printf("\nVendedor %i: ",i);
            for (j=0 ; j < cont_vendas[i] ; j++){
                printf(" R$ %.2f ",vendas[i][j]);
            }
        }
     }

}
