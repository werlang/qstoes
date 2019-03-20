/**Escreva um programa que peça para o usuário informar uma frase até que ele digite um ENTER.
Então mostre quantas palavras contém a frase digitada.
O que delimita o fim de uma palavra e o início de uma nova é o caractere ESPAÇO**/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>>

main(){
    int soma=1;
    char letra;
    printf("Escreva uma frase: \n");
    while(letra!=13){
        letra=getche();
        if(letra==32){
                soma=soma+1;
            }
    }
    printf("Foi digitado %i palavra(s) em sua frase",soma);
}
