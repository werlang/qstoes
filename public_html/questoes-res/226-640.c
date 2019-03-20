#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, maior=0, cont=0;
    do{
            printf("digite um numero: ");
            scanf("%d", &n);
            if(n>maior){
               printf("\n%d maior que %d\n\n", n, maior);
               maior=n;
            }
            else if(n<maior){
                maior=n;
            }
            cont++;
    }while(n!=0 && cont!=20);
    return 0;
}
