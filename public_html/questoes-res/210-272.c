/**Escreva um programa que gere e mostre na tela 100 números aleatórios, onde
o primeiro deverá estar entre 1 e 100, o segundo entre 2 e 100, o terceiro entre 3 e 100, o quarto entre 4 e 100,
e assim por diante. Então mostre na tela a média dos 3 maiores números gerados.**/
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

