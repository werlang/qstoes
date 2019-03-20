#include<stdio.h>
#include<conio.h>
main(){
    /*Escreva um programa que peça para o usuário informar uma frase. então grave um arquivo com a frase do usuário.
    Então escreva outro programa, que peça o nome de um arquivo e mostre na tela o conteúdo deste arquivo.*/
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
