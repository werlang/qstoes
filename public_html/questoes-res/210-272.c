/**Escreva um programa que gere e mostre na tela 100 n�meros aleat�rios, onde
o primeiro dever� estar entre 1 e 100, o segundo entre 2 e 100, o terceiro entre 3 e 100, o quarto entre 4 e 100,
e assim por diante. Ent�o mostre na tela a m�dia dos 3 maiores n�meros gerados.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    int i=1,n;
    srand(time(NULL));
    for(i=1;i<=100;i++){
        n=i+rand()%(100-i+1);
        printf("%i = %i\n",i,n);
    }
}

