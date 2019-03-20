/**Peça para o usuário digitar 5 números, e então realize 50000 sorteios de números de 1 até 100.
Então mostre na tela qual a porcentagem de vezes que cada número escolhido inicialmente foi sorteado.**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int i,y,vet[5],n,num;
    int cont0=0,cont1=0,cont2=0,cont3=0,cont4=0;
    for(i=0;i<5;i++){
        printf("Informe o %i valor: \n",i+1);
        scanf("%i",&num);
        vet[i]=num;
    }
    i=0;
    for(i=0;i<5;i++){
        if(vet[i]){
            for(y=0;y<50000;y++){
                n=1+rand()%(100-1+1);
                if(vet[0]==n){
                    cont0++;
                }
                if(vet[1]==n){
                    cont1++;
                }
                if(vet[2]==n){
                    cont2++;
                }
                if(vet[3]==n){
                    cont3++;
                }
                if(vet[4]==n){
                    cont4++;
                }
            }
        }
    }
    float m0=(float)cont0*100/50000;
    float m1=(float)cont1*100/50000;
    float m2=(float)cont2*100/50000;
    float m3=(float)cont3*100/50000;
    float m4=(float)cont4*100/50000;
    printf("\n%i repetiu %i e representa %.1f%%",vet[0],cont0,m0);
    printf("\n%i repetiu %i e representa %.1f%%",vet[1],cont1,m1);
    printf("\n%i repetiu %i e representa %.1f%%",vet[2],cont2,m2);
    printf("\n%i repetiu %i e representa %.1f%%",vet[3],cont3,m3);
    printf("\n%i repetiu %i e representa %.1f%%",vet[4],cont4,m4);
}
