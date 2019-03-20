#include<stdio.h>
#include<string.h>

main(){
    char palavra[30], frase[200];

    printf("Informe uma frase: ");
    gets(frase);
    printf("Informe uma palavra: ");
    gets(palavra);

    if (strstr(frase, palavra) != NULL){
        int i,j,cont;
        for (i=0 ; i<strlen(palavra) ; i++){
            cont = 0;
            for (j=0 ; j<strlen(frase) ; j++){
                if (palavra[i] == frase[j])
                    cont++;
            }
            printf("A letra %c aparece %i vezes na frase.\n",palavra[i],cont);
        }
    }
    else
        printf("Não possui nenhuma ocorrência.");
}
