//Escreva um programa que peça para o usuário inserir uma palavra de até 10 letras.
//Então mostre na tela o resultado da concatenação desta palavra com a palavra invertida.
//Ex. Palavra: programacao. Resultado: programacaooacamargorp
#include <stdio.h>
#include <string.h>

main(){
    char vet1[10], vet2[10], aux[10];
    int a=0,i=0;
    printf("Informe a palavra com ate 10 letras: ");
    gets(vet1);
    strcpy(aux,vet1);
    a=strlen(aux);
    for(i=0;i<a;i++){
        vet2[i] = aux[a-1-i];
    }
    vet2[i] = '\0';
    printf("%s%s",vet1,vet2);
}
