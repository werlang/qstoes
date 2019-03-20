#include<stdio.h>

main () {

    int lado1,lado2,lado3;
    printf("informe o primeiro lado: ");
    scanf("%i",&lado1);
    printf("informe o segundo lado: ");
    scanf("%i",&lado2);
    printf("informe o terceiro lado: ");
    scanf("%i",&lado3);
    int equilatero,esosceles,escaleno;

    if(lado1==lado2 && lado1==lado3 && lado2==lado1 && lado2==lado3 && lado3==lado1 && lado3==lado2){
         printf("Triangulo Equilatero");

    }
    if(lado1==lado2 || lado2==lado3 || lado1==lado3 ){
         printf("Triangulo Esosceles");
    }
    else{
         printf("Triangulo Escaleno");

    }







}
