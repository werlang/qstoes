#include<stdio.h>
#include<conio.h>
main(){
    /*Escreva um programa que pe�a para o usu�rio informar uma frase. ent�o grave um arquivo com a frase do usu�rio.
    Ent�o escreva outro programa, que pe�a o nome de um arquivo e mostre na tela o conte�do deste arquivo.*/
    char frase[512];
    printf("entre com uma frase: ");
    gets(frase);
    FILE *arq;
    if((arq = fopen("frase.txt","w")) == NULL){
        printf("\nerro critico, nao foi possivel abrir arquivo...");
    }else{
        fprintf(arq, "%s", frase);
        fclose(arq);
        printf("\narquivo salvo com sucesso...");
    }
    printf("\n %s", frase);
    return 0;
}
