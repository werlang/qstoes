/**Escreva um programa que simule um financiamento.
Peça para o usuário inserir o valor que deseja financiar,
então peça para ele informar sua renda e número de parcelas que ele deseja fazer o financiamento.
Supondo que não há juros no financiamento, mostre na tela se o usuário terá seu financiamento aprovado ou não.
Caso seja aprovado, mostre o valor da parcela que o usuário deverá pagar. O financiamento do usuário só será aprovado se
o valor da parcela não ultrapassar 30% da sua renda, bem como o número de parcelas escolhidas for no máximo 180.**/
#include<stdio.h>

main(){
printf("Simulador de Financiamento\n");
float valor, renda, parcel, valorparcel;
printf("Informe o valor do financiamento: \n");
scanf("%f",&valor);
printf("Informe sua renda: \n");
scanf("%f",&renda);
printf("Informe o numero de parcelas do financiamento: \n");
scanf("%f",&parcel);
valorparcel=valor/parcel;
/**só será aprovado se
o valor da parcela não ultrapassar 30% da sua renda**/
if(parcel<=180 && valorparcel<renda*30/100){
    printf("Seu financiamento foi aprovado \n R$%.1f",valorparcel);
}
else{
    printf("Seu financiamento foi reprovado");
}
}

