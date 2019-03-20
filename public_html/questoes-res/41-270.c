/**Escreva um programa que peça para o usuário digitar números até
que pelo menos 5 números pares e 5 números ímpares tenham sido digitados.
Ao fim, mostre na tela se o somatório dos números pares ou dos ímpares é maior.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    int numer;
    int contp=0,conti=0;
    int somap=0,somai=0;
    while(contp!=5 && conti!=5){
        printf("Digite um numero: \n");
        scanf("%i",&numer);
        if(numer%2==0){
            somap=somap+numer;
            contp++;
        }
        else{
            somai=somai+numer;
            conti++;
        }
    }
    if(somap>somai){
        printf("A soma de todos os pares e maior");
    }
    else{
        printf("A soma de todos os impares e maior");
    }
}
