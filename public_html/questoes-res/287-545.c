/**Escreva uma função que receba por referência uma string contendo o nome de um arquivo e uma string de busca.
Esta função deve retornar -1 caso haja erro na abertura do arquivo, caso contrário deve retornar o número de
ocorrências da string de busca que foram encontradas dentro do arquivo.
Mostre no main uma mensagem informando o usuário de quantas ocorrências foram encontradas, ou uma mensagem informando o erro.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tamanho_arq(char nome[]){ /// essa função serve para capturar a quantidade de caracteres que contem no arquivo
    int cont=0;
    char t[1000];
    FILE *arq=fopen(nome,"r");
    if(arq==NULL)
        return -1;
    else{
        while(feof(arq)==0){
            fgetc(arq);
            cont++;
        }
        fclose(arq);
        return cont;
    }
}
int contador(char name[],char *busc,int t){/// nome do arquivo, ponteiro para a busca e quantidade de caracteres
    int cont=0;
    char aux[t],*p;/// string aux tem o tamanho do arquivo

    FILE *arq=fopen(name,"r");/// abre o arquivo para leitura

    if(arq==NULL)
        return -1;
    else{                   /// se existir ele entra aqui
        while(feof(arq)==0) /// repetir ate chegar no fim do arquivo
            fgets(aux,t,arq); /// copia o que tem no arquivo para o vetor aux
        p=aux;/// p aponta para aux
        while(p!=NULL){
            if(p=strstr(p,busc)){/// caso encontre uma ocorrencia de busca em aux p passa a apontar para a primeira ocorrencia caso contrario retornara null
                p+=strlen(busc);/// p vai passar a apontar para depois da ocorrencia
                cont++;/// conta as ocorrencias
            }
        }
        fclose(arq);/// fecha arquivo
        return cont;
    }
}
int main(){
    char nome[100],busc[100];
    printf("Informe o nome do arquivo:");
    gets(nome);
    printf("informe a palavra que busca no texto:");
    gets(busc);
    int t=tamanho_arq(nome);
    int cont=contador(nome,busc,t);
    if(cont>-1)
        printf("\n Repetiu %i vezes a palavra %s",cont, busc);
    else
        printf("Arquivo nao existe!!");
    return 0;
}
