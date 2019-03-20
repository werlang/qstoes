#include<stdio.h>
#include<time.h>
#include<stdlib.h>

main(){
    srand(time(NULL));
    int i, a=0,b=0,c=0, n;
    int min, max = 100;
    for (i=0 ; i<100 ; i++){
        min = i+1;
        n = rand()%(max-min+1)+min;

        if (n > a){
            c = b;
            b = a;
            a = n;
        }
        else if (n > b){
            c = b;
            b = n;
        }
        else if (n > c)
            c = n;
    }
    float media = (float)(a+b+c)/3;
    printf("Media dos tres maiores: %.1f",media);
}
