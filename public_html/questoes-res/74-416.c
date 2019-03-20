#include<stdio.h>
#include<stdlib.h>
int i,cont=0,n;
void primo(){
    for(i=1;i<=n;i++){
        if(n%i==0){
            cont++;

        }
    }
    if(cont==2){
        printf("e primo :)\n");
    }
    else{
        printf("n e primo :(\n");
    }
    }
main(){
    printf("digite um numero:\n");
    scanf("%d",&n);
    primo();
    system("pause");



}


