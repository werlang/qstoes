#include<stdio.h>

//Escreva um algoritmo que pe�a para o usu�rio informar um n�mero, e mostre na tela se este n�mero � positivo, negativo ou zero.

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

