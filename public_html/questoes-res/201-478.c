/**Escreva um programa que simule um financiamento.
Pe�a para o usu�rio inserir o valor que deseja financiar,
ent�o pe�a para ele informar sua renda e n�mero de parcelas que ele deseja fazer o financiamento.
Supondo que n�o h� juros no financiamento, mostre na tela se o usu�rio ter� seu financiamento aprovado ou n�o.
Caso seja aprovado, mostre o valor da parcela que o usu�rio dever� pagar. O financiamento do usu�rio s� ser� aprovado se
o valor da parcela n�o ultrapassar 30% da sua renda, bem como o n�mero de parcelas escolhidas for no m�ximo 180.**/
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
/**s� ser� aprovado se
o valor da parcela n�o ultrapassar 30% da sua renda**/
if(parcel<=180 && valorparcel<renda*30/100){
    printf("Seu financiamento foi aprovado \n R$%.1f",valorparcel);
}
else{
    printf("Seu financiamento foi reprovado");
}
}

