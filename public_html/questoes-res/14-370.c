#include<stdio.h>

//Escreva um algoritmo que pergunte para o usu�rio o ano em que ele nasceu. Ent�o mostre na tela se ele � maior ou menor de idade.

main (){



int x=500, y, z;

while (x!=0){

printf("\n Informe o ano em que estamos. \n");
    scanf("%d",&x);
printf("Informe o ano em que voce nasceu. \n");
    scanf("%d",&y);

    z = x-y;

if(z>=18){

    printf("Se voce jah fez aniversario esse ano, vc eh MAIOR DE IDADE \n", x);

} else {

    printf("Voce eh MENOR DE IDADE \n", x);

}
}
}
