#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int A,I,S;
    printf("Informe o valor A: ");
    scanf("%i",&A);
    printf("Informe o valor I: ");
    scanf("%i",&I);
    printf("Informe o valor S: ");
    scanf("%i",&S);

    int inf=A;
    int sup=3*A;
    int i,n;
    float soma=0;
    int cont=0;
    for (i=0 ; i<10 ; i++){
        n=rand()%(sup-inf+1)+inf;
        printf("%i ",n);
        if (n>=I && n<=S){
            soma+=n;
            cont++;
        }
    }
    printf("Media entre %i e %i: %.1f",I,S,soma/cont);
}
