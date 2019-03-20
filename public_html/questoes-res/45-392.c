#include<stdio.h>

main(){
    int n,i,cont;
    int soma=0;
    while(cont!=2){
        cont=0;
        scanf("%i",&n);
        for (i=1 ; i<=n ; i++){
            if (n%i==0)
                cont++;
        }
        if (cont!=2)
            soma+=n;
    }
    printf("Soma: %i",soma);

}
