#include<stdio.h>
#include<string.h>

main(){
    char frase[100], palavra[3][20];
    int i, soma=0;

    printf("Informe uma frase: ");
    gets(frase);

    for (i=0 ; i<3 ; i++){
        printf("Informe a palavra %i: ",i+1);
        gets(palavra[i]);
    }

    for (i=0 ; i<3 ; i++){
        if (strstr(frase, palavra[i]) != NULL){
            soma += strlen(palavra[i]);
            printf("A palavra %s consta na frase.\n",palavra[i]);
        }
    }

    printf("As palavras que constam na frase somam %i caracteres",soma);

}
