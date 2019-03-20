/**Escreva uma função recursiva que retorne o maior elemento de um vetor de inteiros.**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maior(int *v2, int t){
    if (t==0)
        return 0;
    if (v2[t-1] > maior(v2,t-1) )
        return (v2[t-1]);
}
int main(){
    srand(time(NULL));
    int vet[10],n;
    int i,j,exist;

    for(i=0;i<10;i++){/// forma um vetor tamanho 10 com numeros distintos
        n=0+rand()%(20+1);/// gera um numero aleatorio
        exist=0;/// zera existe
        for(j=0;j<i;j++){/// for vai de zero ate posição de i
            if(vet[j]==n){/// compara vet na posição i for igual a n "numero sorteado"
                exist=1;/// caso for igual existe recebe 1
                break;/// finaliza a repetição
            }
        }
        if(exist==1)/// existe for igual a 1
            i--;/// decrementa o i
        else /// caso contrario
            vet[i]=n;/// vetor na posição i recebe n "numero sorteado"
    }

    for(i=0;i<10;i++)/// serve para mostrar na tela os numeros do vetor
        printf("v[%i] = %i\n",i+1,vet[i]);
    int m=maior(vet,10);
    printf("\nMaior: %i",m);
    return 0;
}
