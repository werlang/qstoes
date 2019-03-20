/**Escreva um programa que peça para o usuário informar 10 números.
Sorteie 2 dos números inseridos, levando em conta que os 2 números sorteados não poderão ser iguais.
Então mostre na tela estes dois números, bem como o somatório de todos os outros 8 números.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int vet[10],i,y,n;
    int maior=0,menor=0,soma=0,res=0;
    for(i=0;i<10;i++){
        printf("Informe o valor %i: \n",i+1);
        scanf("%i",&vet[i]);
        soma+=vet[i];
        if(i==0){
            maior=vet[0];
            menor=vet[0];
        }
        else{
            if(maior<vet[i]){
                maior=vet[i];
            }
            else if(menor>vet[i]){
                menor=vet[i];
            }
        }
    }
    int sort[2];
    for(y=0;y<2;y++){
        n=menor+rand()%(maior-menor+1);
        sort[y]=n;
        printf("sorteio numero %i foi %i\n",y+1,n);
    }
    res=soma-(menor+maior);
    printf("\n soma dos 8 numeros restantes e %i",res);
}
