#include<stdio.h>

main(){
    int valor1,valor2;
    int soma,subi,multi;
    float divi;
    printf("Informe um valor: ");
    scanf("%i",&valor1);
    printf("Informe outro valor: ");
    scanf("%i",&valor2);

    int acertos=0;

    printf("%i+%i= ",valor1,valor2);
    scanf("%i",&soma);
    printf("%i-%i= ",valor1,valor2);
    scanf("%i",&subi);
    printf("%i*%i= ",valor1,valor2);
    scanf("%i",&multi);
    printf("%i/%i= ",valor1,valor2);
    scanf("%f",&divi);

    if(soma == valor1+valor2){
        acertos++;
    }
    if(subi == valor1-valor2){
        acertos++;
    }
    if(multi == valor1*valor2){
        acertos++;
    }
    if(divi == (float)valor1/valor2){
        acertos++;
    }
    printf("Voce obteve %i acertos.",acertos);


}
