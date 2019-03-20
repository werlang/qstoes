#include<stdio.h>
#include<string.h>

main(){
    char nome1[100], nome2[100];
    printf("Nome do arquivo 1: ");
    gets(nome1);
    printf("Nome do arquivo 2: ");
    gets(nome2);

    FILE *arq1 = fopen(nome1,"r");
    FILE *arq2 = fopen(nome2,"r");
    if (arq1 != NULL && arq2 != NULL){
        char conteudo1[1000][1000], conteudo2[1000][1000], buffer[1000];
        int i1=0, i2=0;
        while (!feof(arq1)){
            if (fgets(buffer, 1000, arq1) != NULL){
                strcpy(conteudo1[i1], buffer);
                i1++;
            }
        }
        while (!feof(arq2)){
            if (fgets(buffer, 1000, arq2) != NULL){
                strcpy(conteudo2[i2], buffer);
                i2++;
            }
        }
        int i, lim;
        if (i1 >= i2)
            lim = i1;
        else
            lim = i2;

        FILE *log = fopen("changelog.txt","w");
        for (i=0 ; i<lim ; i++){
            if (strcmp(conteudo1[i], conteudo2[i]) != 0){
                printf("%i: %s",i,conteudo2[i]);
                fprintf(log, "%i: %s",i,conteudo2[i]);
            }
        }
    }
    else
        printf("Arquivo nao encontrado");
}
