/**Escreva um programa que contenha uma fun��o que grave em um arquivo .doc um milh�o de caracteresde a at� z aleat�rios.
Escreva outra fun��o que busque dentro desse arquivo e mostre quantas ocorr�ncias de um caractere especificado pelo
usu�rio existem. O usu�rio deve especificar o nome do arquivo que ser� criado e consultado.
Mostre uma mensagem de erro caso o arquivo n�o possa ser aberto.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void gravar(char texto[],char nome[]){/// grava o vetor criado no documento especificado
    FILE *arq=fopen(nome,"a+");/// abre o arquivo se n�o existir ele cria um
    fputs(texto,arq);/// faz a grava��o
    fclose(arq);/// fecha o arquivo
}
void criatexto(char *p){/// gera letras aleatoriamente de a ate z, e guarda num vetor no main
    srand(time(NULL));/// e armazena por poteiro
    int i;
    for(i=0;i<1000000;i++)/// lan�a os 1000000 de caracteres
        *(p+i)='a'+rand()%('z'-'a'+1);
}
int busca(char busc, char nome[]){/// fun��o que busca quantos caracteres tem igual o de busca no arquivo
    FILE *arq=fopen(nome,"r");
    char caract;
    int cont=0;
    if(arq==NULL)
        printf("Nao foi possivel abrir o arquivo!!");
    else{                       /// no else ele entra no while que so vai sair quando chegar no fim do documento
        while(feof(arq)==0){
            caract=fgetc(arq);/// captura um caracter por vez do arquivo
            if(caract==busc)/// compara se o caracter do documento � igual o de busca
                cont++;
        }
    }
    fclose(arq);/// fecha o arquivo
    return cont;/// retorna a quantidade de caracteres s�o iguais os de busca
}
int main(){
    char nome[1000],texto[1000000],busc;
    printf("Digite nome do arquivo:");
    gets(nome);
    printf("\nInforme um caracter de busca:");
    busc=getche();
    criatexto(texto);
    gravar(texto,nome);
    int r=busca(busc,nome);
    printf("\n\n(Existem %i caracteres iguais a (%c)",r,busc);
    return 0;
}
