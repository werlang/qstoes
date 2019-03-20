/**Escreva um programa que mostre quantos caracteres repetidos uma frase informada pelo usuário contém**/#
#include<stdio.h>
#include<string.h>

main(){
    char frase[200],aux;/// frase[200] vetor da frase a ser digitada, aux serve para auxiliar na contagem de cada caracter
    int i, j, cont[200];/// cont[200] vetor que serve para contar cada caracter individualmente
    for(i=0;i<200;i++)/// este for serve para zerar todos os contadores
        cont[i]=0;
    fgets(frase,200,stdin);/// aqui vc escreve sua frase limitando ate 200 caracteres
    int t=strlen(frase);/// t serve para ver o tamanho da frase
    for(i=0;i<t;i++){/// o for vai percorrer ate chegar em t que é o tamanho da frase
        if(frase[i]>='a' && frase[i]<='z' || frase[i]>='A' && frase[i]<='Z'){///aqui ele verifica se cada caracter consiste no alfabeto tanto minuscula quanto maiuscula
            aux=frase[i];/// aux serve receber o caracter
            cont[aux]++;/// aqui o contador conta o caracter em especifico ex:( O caracter 'a' tabela ascii correnponde a 97, entao ele incrementa no vetor cont[97] assim limitando ele a incrementar somente nos caracteres especificos)
        }
    }
    int rep=0;
    for(i=65;i<=122;i++){/// esse for serve para mostrar na tela o caracter que repetiu e a quantidade de vezes q ele repetiu( tabela ascii 65 corresponde a 'A' e 122 corresponde a 'z')
        if(cont[i]>1){// mostra os caracteres que repetiram mais de uma vez
            rep++;
            printf("\n %c repetiu %i",i,cont[i]);/// o i aqui mostra o caracter o numero q estiver no for corresponde o caracter, e seu devido contador
        }
    }
    printf("\n Repetiu %i caracteres distintos",rep);/// aqui mostra a quantidade de caracteres que repetiu
}
