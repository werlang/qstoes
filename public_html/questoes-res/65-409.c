#include<stdio.h>
#include<string.h>

main(){
    char palavra[5][20];
    int i, menor;

    for (i=0 ; i<5 ; i++){
        printf("Informe a palavra %i: ",i+1);
        gets(palavra[i]);
        if (strlen(palavra[i])<menor || i==0){
                menor = strlen(palavra[i]);
        }
    }

    printf("Plavras cortadas:\n");
    for (i=0 ; i<5 ; i++){
            palavra[i][menor] = '\0';
            printf("%s\n", palavra[i]);
    }


}
