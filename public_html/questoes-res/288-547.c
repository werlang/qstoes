/**Então crie um outro programa que pergunte para o usuário o nome de um arquivo
e mostre na tela todas sequencias de caracteres contidas no arquivo que possuem tamanho maior que 20.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/// mostrar arquivos da sequencia, parte 2
void mostrar(char nome[]){
    FILE *arq=fopen(nome,"r");/// abre o arquivo
    char aux[30];
    int cont=0;
    if(arq==NULL)/// se nao existir mostra a msg
        printf("Arquivo nao existe");
    else{   /// se existir
        while(feof(arq)==0){/// percorre todo o arquivo
            fgets(aux,26,arq);/// captura as palavras
            if(strlen(aux)>20){/// se seu tamanho for maior que 20
                printf("\n%s",aux); /// mostra na tela
                cont++;/// conta quantas das 350 sequencias tem mais de 20 caracteres
            }
        }
        printf("%i possuem mais de 20 caracteres",cont);
        fclose(arq);/// fecha o arquivo
    }
}
int main(){
    char nome[20];
    printf("Informe o nome do arquivo:");
    gets(nome);
    mostrar(nome);/// chama a função
    return 0;
}
