/**Escreva um programa que peça para o usuário digitar uma frase de até 500 caracteres, e então mostre na tela o
tamanho da maior palavra digitada.**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char f;
    int n=0, cont=0, maior=0, soma=0;
    printf("digite uma frase:");

        while(f!=13 && n<500){
        f=getche();
        cont++;
            if(f==32 || f==13){
                if(cont>maior){
                maior=cont-1;
                }
                cont=0;
            }
            n++;
        }


    printf("\nmaior palavra possue %d letras", maior);
    return 0;
}
