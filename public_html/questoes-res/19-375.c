/**Pedir para o usuário informar 15 números.
Então mostrar na tela quantos são positivos e negativos.**/
#include<stdio.h>

main(){
    int i, n, positivo=0, negativo=0;
    for(i=1;i<=15;i++){
        printf("Infome o valor %i: ",i);
        scanf("%i",&n);
        if(n>0)
            positivo++;
        else if(n!=0)
            negativo++;
    }
    printf(" %i sao positivos \n %i sao negativos",positivo,negativo);
}
