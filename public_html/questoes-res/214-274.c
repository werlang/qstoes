/**Elabore um programa que pe�a para o usu�rio digitar uma frase de at� 255 caracteres. Ap�s, mostre na tela a frase,
e indique quantos dos caracteres digitados s�o letras mai�sculas, quantos s�o min�sculas, e quantos n�o s�o letras.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    char let;
    int cont=0;
    int contMI=0,contMA=0,contFo=0;
    while(cont!=255){
        let=getche();
        if(let!=32){
            cont++;
        }
        if(let>='a' && let<='z'||let>='A' && let<='Z'){
            if(let>='a' && let<='z')
                contMI++;
            if(let>='A' && let<='Z')
                contMA++;
        }
        else
            contFo++;
    }
    printf("\n Total de caracter = %i\n Total de letras minusculas = %i\n Total de letras maiusculas %i\n Total que nao sao letras %i",cont,contMI,contMA,contFo);
}
