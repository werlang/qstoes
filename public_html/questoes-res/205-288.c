/**Escreva um programa que pe�a para o usu�rio inserir uma palavra de at� 10 letras.
Ent�o mostre na tela o resultado da concatena��o desta palavra com a palavra invertida.
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
