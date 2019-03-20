#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main(){
    srand(1);
    int n,i;
    int max = 100, min = 10;
    for (i=0 ; i<25 ; i++){
        n = rand()%(max-min+1)+min;
        printf("%i ",n);
    }
}
