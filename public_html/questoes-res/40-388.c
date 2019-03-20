#include <stdio.h>
main(){

int valor,i;
float cont=0, porcentagem;


for (i=0; i<10; i++){
    printf("informe 10 valores %i:", i+1);
    scanf ("%i",&valor);
    while (valor<=0){
        printf("valor invalido. informe outro valor: ");
        scanf ("%i",&valor);
    }
    if (valor<10){
        cont=cont+1;
    }
}

porcentagem=(cont/10)*100;
printf(" %.1f%% de numeros abaixo de 10",porcentagem);

}
