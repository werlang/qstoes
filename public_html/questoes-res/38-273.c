/**Escreva um programa que pe�a para o usu�rio informar uma frase at� que ele digite um ENTER.
Ent�o mostre quantas palavras cont�m a frase digitada.
O que delimita o fim de uma palavra e o in�cio de uma nova � o caractere ESPA�O**/
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
