#include<stdio.h>
#include<string.h>

void substitui(char frase[], char busca[], char subst[]){
    char aux[1000];
    char *p, *q;
    strcpy(aux, frase);
    p = strstr(frase, busca);
    q = strstr(aux, busca);
    while(p!= NULL){
        strcpy(p, subst);
        p += strlen(subst);
        q += strlen(busca);
        strcpy(p, q);
        p = strstr(p, busca);
        q = strstr(q, busca);
    }
}

int pegaarquivo(char nome[], char texto[]){
    strcpy(texto, "");
    FILE *arq = fopen(nome,"r");
    if (arq == NULL){
        return 0;
    }
    else{
        char buffer[10];
        while (feof(arq) == 0){
            if (fgets(buffer,10,arq) != 0)
                strcat(texto,buffer);
        }
        fclose(arq);
        return 1;
    }
}

void salvaarquivo(char nome[], char texto[]){
    FILE *arq = fopen(nome,"w");
    fputs(texto, arq);
    fclose(arq);
}

int main(){
    char nome[50];
    gets(nome);
    char texto[10000];
    if (pegaarquivo(nome, texto) == 0){
        printf("arquivo nao existe.\n");
    }
    else{
        char busca[50], subst[50];
        gets(busca);
        gets(subst);
        substitui(texto, busca, subst);
        salvaarquivo(nome, texto);
    }
}
