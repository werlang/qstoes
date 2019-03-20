#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main(){

    int d,soma=0;
    printf("Quantos dados queres lancar? ");
    scanf("%d", &d);
    int n,i;
    for (i=0 ; i<d ; i++){
        n=rand()%7;
        printf("%i ",n);
        soma+=n;
    }

    printf("%d", soma);
}
