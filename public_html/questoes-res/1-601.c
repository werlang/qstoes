#include<stdio.h>//Escreva um algoritmo que peça para o usuário informar quatro números.
//Então mostre na tela quantos são positivos e quantos são negativos.

main() {

     int a,b,c,d,positivo,negativo;

     printf("informe o valor de a: ");
     scanf("%i",&a);
     printf("informe o valor de b: ");
     scanf("%i",&b);
     printf("informe o valor de c: ");
     scanf("%i",&c);
     printf("informe o valor de d: ");
     scanf("%i",&d);

     if(a>0){
        printf(" A positivo\n");
     }
     if(a<0){
        printf(" A negativo\n");
     }
     if(b>0){

        printf(" B positivo\n");
      }
      if(b<0){
          printf(" B negativo\n");
       }
     if(c>0){
        printf(" C positivo\n");
      }
       if(c<0){
          printf(" C negativo\n");
       }
          if(d>0){
            printf(" D positivo\n");
          }
              if(d<0){
                printf(" D negativo\n ");
               }

}








