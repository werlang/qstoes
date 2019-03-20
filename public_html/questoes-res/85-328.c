/**Escrever uma função que recebe um caractere e retorna este caractere convertido em maiúsculo ou
o próprio caractere se não for letra. Então fazer outra função que faça o mesmo para minúsculo.**/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char conversao(char copia){
    if(copia >= 'a' && copia <= 'z')
        copia-=32;
    else if(copia >= 'A' && copia <= 'Z')
            copia+=32;
    return copia;
}

int main(){
    char caract,novo;
    printf("Informe um caracter: ");
    caract=getche();
    novo=conversao(caract);
    if(novo!=caract)
        printf("\n O caracter foi convertido (%c)",novo);
    else
        printf("\nO caracter nao foi convertido");
}
