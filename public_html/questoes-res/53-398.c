/*
Escreva um programa que gere números
 entre 1 e 10 até que cada número tenha
  sido sorteado pelo menos 5 vezes.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int num[10];
    int i,n;
    //zera vetor de contadores
    for (i=0 ; i<10 ; i++)
        num[i] = 0; //zera todas posicoes, vetor é contador

    int chegou=0;
    while(chegou < 10){
        n = rand()%10+1; //sorteia
        num[n-1]++; //incrementa o vetor na posicao n-1

        chegou=0; //quantos chegaram no valor 5
        for(i=0 ; i<10 ; i++){ //varre o vetor
            if (num[i] >= 5) //posicao atual chegou no 5???
                chegou++;
        }
    }

    for (i=0 ; i<10 ; i++) //mostra o vetor
        printf("%i ",num[i]);

}
