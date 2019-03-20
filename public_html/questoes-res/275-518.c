/**Escreva um procedimento que receba dois parâmetros. O primeiro será passado por valor e o segundo por referência.
Este procedimento deve perguntar para o usuário o valor de cada uma das infrações de trânsito que ele obteve no ano.
O número de infrações deverá ser informado no primeiro parâmetro. A função então deverá atribuir à variável do segundo
parâmetro quanto o usuário receberá de desconto caso pague as infrações até o dia do vencimento (o desconto é de 20% do total).
Mostre no main o valor do desconto, bem como o valor a ser pago com desconto, e o valor a ser pago sem desconto.**/
#include<stdio.h>
#include<stdlib.h>

    float desconto(int nfrac,int *desc){
        float total=0,mult,soma=0;
        int i;
        for(i=0;i<nfrac;i++){
            printf("Informe  valor da multa %i:",i+1);
            scanf("%f",&mult);/// digita o valor da multa
            soma+=mult;/// soma todas as multas
        }
        *desc=(int)soma*20/100;/// calcula o desconto
        total=soma-*desc;/// diminui o desconto do total
        return total;/// retorna o total
    }
    int main(){
        int desc, quant;
        float total;
        printf("Informe quantas multas voce tomou:");
        scanf("%i",&quant);/// quantidade
        total=desconto(quant,&desc);/// envia por parametro a quant e por referencia a variavel desconto
        printf("Valor total sem desconto R$%.2f\n\n",total+desc);/// total que retornou com desconto entao somamos o desconto para se ter o valor sem desconto
        printf("Caso voce pagar ate o dia de vencimento:\n\nvalor do desconto R$%i \n valor total a ser pago R$%.2f",desc,total);
        return 0;
    }
