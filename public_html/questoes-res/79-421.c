#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Escreva uma função que conta e mostra na tela quantas palavras uma frase enviada por parâmetro possui. */
int cont_palavra(char frase[]){
    int palavras=1;
    int i;
    for(i=0 ; i<strlen(frase); i++){
        if(frase[i]==32){
            palavras++;
        }
    }
    return palavras;
}
main(){
    char frase[50];
    printf("Informe uma frase: \n");
    gets(frase);

    resultado=cont_palavra(frase);
    printf("A frase contem %i palavras ",resultado);
}