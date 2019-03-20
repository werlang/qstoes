#include<stdio.h>
#include<string.h>

main(){
    char palavra[20], maiorp[20];
    int i, maiort;

    for (i=0 ; i<10 ; i++){
        printf("Informe a palavra %i: ",i+1);
        gets(palavra);
        if (strlen(palavra)>maiort || i==0){
            maiort = strlen(palavra);
            strcpy(maiorp,palavra);
        }
    }
    printf("A maior palavra inserida foi: %s",maiorp);
}
