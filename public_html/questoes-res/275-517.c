/**Escreva um procedimento que receba dois par�metros. O primeiro ser� passado por valor e o segundo por refer�ncia.
Este procedimento deve perguntar para o usu�rio o valor de cada uma das infra��es de tr�nsito que ele obteve no ano.
O n�mero de infra��es dever� ser informado no primeiro par�metro. A fun��o ent�o dever� atribuir � vari�vel do segundo
par�metro quanto o usu�rio receber� de desconto caso pague as infra��es at� o dia do vencimento (o desconto � de 20% do total).
Mostre no main o valor do desconto, bem como o valor a ser pago com desconto, e o valor a ser pago sem desconto.**/
#include<stdio.h>
#include<stdlib.h>

    float desconto(int nfrac,int *desc){
        float total=0,mult,soma=0;
        int i;
        for(i=0;i<nfrac;i++){
            printf("Informe  valor da multa %i:",i+1);
            scanf("%f",&mult);
            soma+=mult;
        }
        *desc=(int)soma*20/100;
        total=soma-*desc;
        return total;
    }
    int main(){
        int desc, quant;
        float total;
        scanf("%i",&quant);
        total=desconto(quant,&desc);
        printf("Valor total sem desconto R$%.2f\n\n",total+desc);
        printf("Caso voce pagar ate o dia de vencimento:\n\nvalor do desconto R$%i \n valor total a ser pago R$%.2f",desc,total);
        return 0;
    }
