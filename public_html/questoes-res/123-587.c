#include<stdio.h>

main ()  {
      int mes,ano,dia,numero;

      printf("digite um numero referente ao dia do mes: ");
      scanf("%i",&dia);
      printf("digite um numero referente ao mes do ano: ");
      scanf("%i",&mes);
      printf("digite um numero referente ao ano: ");
      scanf("%i",&ano);


        numero=mes;

    if(mes==1){
        printf("charqueadas %i de janeiro de %i",dia,ano);
    }

    if(mes==2){
        printf("charqueadas %i de fevereiro de %i",dia,ano);
     }
    if(mes==3){
        printf("charqueadas %i de março de %i",dia,ano);
     }
     if(mes==4){
        printf("charqueadas %i de abril de %i",dia,ano);
     }
     if(mes==5){
        printf("charqueadas %i de maio de %i",dia,ano);
     }
     if(mes==6){
        printf("charqueadas %i de junho de %i",dia,ano);
     }
     if(mes==7){
        printf("charqueadas %i de julho de %i",dia,ano);
     }
     if(mes==8){
        printf("charqueadas %i de agosto de %i",dia,ano);
     }
     if(mes==9){
        printf("charqueadas %i de setembro de %i",dia,ano);
     }
     if(mes==10){
        printf("charqueadas %i de outubro de %i",dia,ano);
     }
    if(mes==11){
        printf("charqueadas %i de novembro de %i",dia,ano);
     }
     if(mes==12){
        printf("charqueadas %i de dezembro de %i",dia,ano);
     }
     if(mes>12){
          printf("valor invalido");
        }else if(mes<1){
             printf(" valor invalido");
          }

}
