#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
/*
Crie uma função que receba por referência um vetor do tipo char.
A função deverá formatar a string dada como entrada de maneira que ao término da execução da função
a primeira letra de todas as palavras sejam maiúsculas e as outras letras minúsculas.
O vetor recebido por referência deverá ser acessado através de um ponteiro.

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
