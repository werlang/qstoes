/**Escrever uma fun��o que recebe um caractere e retorna este caractere convertido em mai�sculo ou
o pr�prio caractere se n�o for letra. Ent�o fazer outra fun��o que fa�a o mesmo para min�sculo.**/

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
