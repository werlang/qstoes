/**Elabore um programa que gere 350 sequencias de letras aleatórias de tamanho entre 10 e 25 cada.
Armazene estas sequencias uma em cada linha de um arquivo de nome escolhido pelo usuário e extensão .txt.
Então crie um outro programa que pergunte para o usuário o nome de um arquivo
e mostre na tela todas sequencias de caracteres contidas no arquivo que possuem tamanho maior que 20.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/// programa que cria as 350 sequencias parte 1
void sequencia(char nome[]){
    srand(time(NULL));
    int i,t,j;
    char texto[26];
    FILE *arq = fopen(nome,"a+");
    for(i=0;i<350;i++){
        t=10+rand()%(25-10+1);
        for(j=0;j<t;j++){
            texto[j]='a'+rand()%('z'-'a'+1);
        }
        texto[t]='\n';
        texto[t+1]='\0';
        fputs(texto, arq);
    }
    fclose(arq);
}
int main(){
    char nome[20];
    printf("Informe o nome do arquivo que voce deseja armazenar as sequencias:");
    gets(nome);
    sequencia(nome);
}
