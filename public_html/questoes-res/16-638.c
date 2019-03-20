//Escreva um programa que peça para o usuário informar 10 números. Ao fim mostrar a média dos valores informados.
#include<stdio.h>
#include<stdlib.h>
    main(){
        int i;
        float soma=0, media=0,num;
        for(i=0;i<10;i++){
            printf("Informe um numero: ");
            scanf("%f",&num);
            soma+=num;
        }
        media = soma/2;
        printf("A media dos numeros informados e %.2f",media);
    }
