/**Elabore um programa que gere 100 números aleatórios entre -15 e 50,
e na medida que forem gerados, classifique-os em pares, ímpares, positivos e negativos.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    int i,n;
    srand(time(NULL));
    for(i=1;i<=100;i++){
        n=(-50)+rand()%(50-(-50)+1);
        if(n==0){
            printf("\n%i esse numero e nulo \n",n);
        }
        if(n%2==0 && n!=0){
            if(n>0)
                printf("\n%i esse numero e par e positivo \n",n);
            else
                 printf("\n%i esse numero e par e negativo \n",n);
        }
        else if(n%2!=0 && n!=0){
            if(n>0)
                printf("\n%i esse numero e impar e positivo \n",n);
            else
                printf("\n%i esse numero e impar e negativo \n",n);
        }
    }
}
