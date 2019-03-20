#include<stdio.h>
/*
Escreva um programa que permita que o usuário digite textos, então quando o usuário digitar ENTER duas vezes consecutivas,
peça para ele informar o nome do arquivo, então grave o texto inserido no arquivo informado, com a extensão .txt.
*/
main(){
FILE *arq;
int cont = 0, i=0;
char texto[1000],c, nome_arq[50];
do{
    c = getche();
    if(c==13){
        texto[i] = '\n';
        printf("\n");
        cont++;
    }else{
        texto[i] = c;
        cont = 0;
    }
    i++;
}while(cont<2);
printf("Digite o nome do arquivo onde deseja salvar:");
gets(nome_arq);
arq = fopen(nome_arq,"w");
fputs(texto,arq);
fclose(arq);
}
