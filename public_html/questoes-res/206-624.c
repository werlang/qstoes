/**Escreva um programa que gere e mostre na tela 10 seq��ncias de letras aleat�rias.
Cada sequencia dever� ter um tamanho aleat�rio entre 10 e 25 caracteres. Mostre cada sequencia separada por um espa�o.**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int j, i, q;
    char n;
    for(i=0; i<10; i++){
        q=rand()%16+10;
        for(j=0; j<q; j++){
        n=rand()%26+97;
        printf(" %c ", n);
        }
        printf("\n\n");
    }
    return 0;
}
