#include<stdio.h>
/*
Escreva um programa que permita que o usu�rio digite textos, ent�o quando o usu�rio digitar ENTER duas vezes consecutivas,
pe�a para ele informar o nome do arquivo, ent�o grave o texto inserido no arquivo informado, com a extens�o .txt.
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
