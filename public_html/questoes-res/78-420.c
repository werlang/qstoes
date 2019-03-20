#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void rola_dados(int n, int l){
    srand(time(NULL));
    if (l != 4 && l!= 6 && l!= 8 && l!= 10 && l!= 12 && l!= 20)
        printf("numero de lados invalido");
    else{
        int i,ale;
        for (i=0 ; i<n ; i++){
            ale = rand()%l+1;
            printf("%i ",ale);
        }
    }
}

main(){
    int n, l;
    scanf("%i %i", &n, &l);
    rola_dados(n,l);
}
