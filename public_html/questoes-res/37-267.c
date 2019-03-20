/**Escreva um programa que gere e mostre na tela números aleatórios entre 2 e 10 até que o somatório
dos números gerados ultrapasse 100, ou 15 números tenham sido informados, o que acontecer primeiro.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    int n, i=0,soma=0;
    srand(time(NULL));
    while(soma<100 && i<15){
        i++;
        n=2+rand()%(10-2+1);
        printf("%i\n",n);
        soma=soma+n;
    }
    if(i>=15){
    printf("Foi informado 15 numeros\n");
    }
    if(soma>100){
        printf("A soma de todos os numeros deu %i",soma);
    }
}
