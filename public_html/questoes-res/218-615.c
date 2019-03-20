#include<stdio.h>

main(){
    int n, i;
    int a=0,b=1,c;
    printf("Informe N: ");
    scanf("%i",&n);
    if (n >= 1)
        printf("0 ");
    if (n >= 2)
        printf("1 ");
    for (i=3 ; i<=n ; i++){
        c = a+b;
        a = b;
        b = c;
        printf("%i ",c);
    }
}
