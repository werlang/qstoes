/**Escreva um programa que peça para o usuário inserir uma palavra de até 10 letras.
Então mostre na tela o resultado da concatenação desta palavra com a palavra invertida.
Ex. Palavra: programacao. Resultado: programacaooacamargorp**/
#include<stdio.h>

main(){
    char i,y,let, pal[11];
    for(i=0;i<11;i++){
        let=getche();
        pal[i]=let;
    }
    for(y=10;y>-1;y--){
        printf("%c",pal[y]);
    }
}
