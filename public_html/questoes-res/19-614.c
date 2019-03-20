#include<stdio.h>


main() {
    int i,num,positivo=0,negativo=0;
    for(i=0;i<=15;i++){
        printf("Informe o valor de %i:",i+1);
        scanf("%i",&num);
        if(num>0){
            positivo++;
        }
        if(num<0){
            negativo++;
        }
    }

    printf(" Positivos: %i  Negativos: %i",positivo,negativo);




}
