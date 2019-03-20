#include<stdio.h>

main(){
    int x;
    float soma=0, num;
    for(x=1 ; x<=10 ; x++){
        printf("informe um numero: ");
        scanf("%f",&num);
        soma += num;
    }
    float media = soma/10;
    printf("media: %.1f",media);

}
