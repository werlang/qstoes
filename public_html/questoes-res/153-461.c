#include<stdio.h>
#include<stdlib.h>

int main(){
    int *vet = (int*)malloc(sizeof(int));
    int n, t=0;
    do{
        scanf("%i",&n);
        if (n != 0){
            *(vet+t) = n;
            t++;
            vet = (int*)realloc(vet, sizeof(int) * (t+1));
        }
    }while(n != 0);
    
    int i, j, k, re, prox, difn, difp;
    scanf("%i",&re);
    for (k=0 ; k<5 ; k++){
        for (i=0 ; i<t ; i++){
            if (i == 0){
                prox = 0;
                difp = vet[0] - re;
                if (difp < 0)
                    difp *= -1;
            }
            else{
                difn = vet[i] - re;
                if (difn < 0)
                    difn *= -1;
                if (difn < difp){
                    difp = difn;
                    prox = i;
                }
            }
        }
        for (j=prox ; j<t ; j++){
            vet[j] = vet[j+1];
        }
        t--;
        vet = (int*)realloc(vet, sizeof(int) * (t+1));
    }
    for (i=0 ; i<t ; i++){
        printf("%i ",vet[i]);
    }
    return 0;
}