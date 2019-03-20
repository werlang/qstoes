/**Escreva um programa que peça para o usuário inserir diferentes valores para
seus gastos de um mês. Quando o usuário digitar 0 para um gasto, peça para ele
começar a digitar os gastos do próximo mês da mesma maneira. Faça isso até que
os gastos de todos os 12 meses seja computado. Ao fim, mostre qual o número do
mês que teve o maior gasto, bem como de quanto foi esse gasto.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    float gasto,maior=0;
    int i=1,x=0;
    do{
        printf("Agora informe do mes %i: ",i);
        scanf("%f",&gasto);
        if(i==1){
            x=i;
            maior=gasto;
        }
        else{
            if(maior<gasto){
                x=i;
                maior=gasto;
            }
        }
        i++;
    }while(gasto>=0 && i!=13);
    printf("O mes %i teve o maior gasto de R$%.2f",x,maior);
}
