#include<stdio.h>
#include<conio.h>
main(){
    FILE *ark;
    char arquivo[64];
    printf("Entre com o nome do arquivo e sua extensao... ");
    gets(arquivo);
    ark = fopen(arquivo, "r");
    if(ark == NULL){
        printf("\n\n   arquivo NAO encontrado...");
    }else{
        while(!feof(ark)){
            if(fgets(arquivo, 64, ark)){
                printf("\n%s",arquivo);
            }else{
                printf("\nnao foi possivel ler...");
            }
        }
    }
    fclose(ark);
    return 0;
}
