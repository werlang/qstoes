#include<stdio.h>
#include<stdlib.h>
int fibo(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fibo(n-1) + fibo(n-2);
}
int main(){
    int n=8;
    int f=fibo(n);
    printf("%i",f);
    return 0;
}
