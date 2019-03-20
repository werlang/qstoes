/**Escreva um programa que peça para o usuário digitar caracteres até que o ENTER seja pressionado. Mostrar na tela somente os
caracteres que forem letras maiúsculas, minúsculas, números, ou espaço.
**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char l;

    do{
        l=getch();

        if((l>='A' && l<='Z')||( l>='a' && l<='z') || (l>=0) || (l==32)){
        printf(" %c", l);
        }

    }while(l!=13);

    return 0;
}
