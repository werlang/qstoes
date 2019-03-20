#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main(){
    srand(time(NULL));
    int n, soma=0, i, d;
    printf("Informe quantos dados deseja rolar: ");
    scanf("%i", &d);

    for(i=0; i<d; i++){
        n=rand()%6+1;
        printf("%i, ", n);
        soma=soma+n;
    }
    printf("\nA soma de %i dados foi: %i", d, soma);
}
