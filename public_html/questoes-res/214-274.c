/**Elabore um programa que peça para o usuário digitar uma frase de até 255 caracteres. Após, mostre na tela a frase,
e indique quantos dos caracteres digitados são letras maiúsculas, quantos são minúsculas, e quantos não são letras.**/
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
