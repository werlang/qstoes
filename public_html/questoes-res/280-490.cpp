#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
/*
Crie uma fun��o que receba por refer�ncia um vetor do tipo char.
A fun��o dever� formatar a string dada como entrada de maneira que ao t�rmino da execu��o da fun��o
a primeira letra de todas as palavras sejam mai�sculas e as outras letras min�sculas.
O vetor recebido por refer�ncia dever� ser acessado atrav�s de um ponteiro.

*/

char* format(char vet[]){
int i,j,t,t1;
char var_test[27]="BCDFGHJKLMNPQRSTVWXYZAEIOU";
t1=strlen(var_test);
t=strlen(vet);
    for(i=0;i<t;i++){
        for(j=0;j<t1;j++){
            if(vet[i]==var_test[j]){
                vet[i]=vet[i]+32;
             }
        }
    }
    for(i=0;i<t;i++){
     if(i==0){
       vet[i]=vet[i]-32;
       }
     if(vet[i]==' '){
            vet[i+1]=vet[i+1]-32;
       }

    }
    return vet;
}
int main(){
char vet[100];
char *resp;
printf("Informe uma frase:");
gets(vet);
resp=format(vet);
   puts(resp) ;
return 0;
}
