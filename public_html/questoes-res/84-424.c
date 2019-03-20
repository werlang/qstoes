#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int aleatorio(int inf, int sup){
    srand(time(NULL));
    int n;
    if (inf > sup)
        n = rand()%(inf-sup+1)+sup;
    else
        n = rand()%(sup-inf+1)+inf;
    return n;
}

main(){
    int a,b;
    printf("Informe a margem inferior: ");
    scanf("%i",&a);
    printf("Informe a margem superior: ");
    scanf("%i",&b);

    int num = aleatorio(a,b);
    printf("Numero gerado: %i",num);
}
