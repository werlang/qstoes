#include<stdio.h>

main(){
    float temp, soma=0, media, cont=0;

    printf("Informe o valor da temperatura 1: ");
    scanf("%f",&temp);
    if (temp > 100){
        soma = soma + temp;
        cont = cont + 1;
    }

    printf("Informe o valor da temperatura 2: ");
    scanf("%f",&temp);
    if (temp > 100){
        soma = soma + temp;
        cont = cont + 1;
    }

    printf("Informe o valor da temperatura 3: ");
    scanf("%f",&temp);
    if (temp > 100){
        soma = soma + temp;
        cont = cont + 1;
    }

    printf("Informe o valor da temperatura 4: ");
    scanf("%f",&temp);
    if (temp > 100){
        soma = soma + temp;
        cont = cont + 1;
    }

    printf("Informe o valor da temperatura 5: ");
    scanf("%f",&temp);
    if (temp > 100){
        soma = soma + temp;
        cont = cont + 1;
    }

    media = soma/cont;
    printf("Media das temperaturas maiores que 100: %.1f",media);
}
