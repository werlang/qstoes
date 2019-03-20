#include<stdio.h>
main(){
  int num[10],i,j,s;
    for(i=0;i<10;i++){
    printf("informe 10 numeros: \n");
    scanf("%i",&num[i]);
    }

    j=9;
    for(i=0;i<5;i++){
        s = num[i] + num[j];
        j--;
        printf("%i ",s);
    }

    }
