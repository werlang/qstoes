#include<stdio.h>
#include<math.h>
main(){
float valor, juro, pjuro, vcomjuro, vtotal;
    printf("\nDigite o valor: ");
    scanf("%f",& valor);
    printf("\nDigite o juro: ");
    scanf("%f",& juro);
    pjuro = (float) juro/100;
    vcomjuro = pjuro*valor;
    vtotal = vcomjuro+valor;
    printf("\nValor Juro: %.2f", vcomjuro);
    printf("\nValor Total: %.2f", vtotal);
    }
