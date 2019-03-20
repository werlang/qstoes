#include<stdio.h>

//Escreva um algoritmo que peça para o usuário informar um número, e mostre na tela se este número é positivo, negativo ou zero.

main (){



int x=0;

printf("\n Informe um numero qualquer \n");
    scanf("%d",&x);

if(x>0){
    printf("O NUMERO %d EH POSITIVO \n", x);
    }
if(x<0){
    printf("O NUMERO %d EH NEGATIVO \n", x);
    }
if(x==0){
    printf("O NUMERO %d EH ZERO", x);
}
}

