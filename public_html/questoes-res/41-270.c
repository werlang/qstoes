/**Escreva um programa que pe�a para o usu�rio digitar n�meros at�
que pelo menos 5 n�meros pares e 5 n�meros �mpares tenham sido digitados.
Ao fim, mostre na tela se o somat�rio dos n�meros pares ou dos �mpares � maior.**/
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
