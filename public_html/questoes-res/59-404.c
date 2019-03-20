#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    int num;
    int maiorprimo=0;
    int vet[500], tam=0;
    int quantos=0;
    printf("Informe um numero entre 0 e 100: ");
    scanf("%i",&num);
    while(num<0 || num>100){
        printf("Invalido. Digite entre 0 e 100: ");
        scanf("%i",&num);
    }
    int ale;

    while (ale != num){
        ale = rand()%101;
        printf("%i ",ale);
        vet[tam] = ale;
        tam++;

        int cont=0;
        int i;
        for (i=1 ; i<=ale ; i++){
            if (ale%i==0)
                cont++;
        }
        if (cont == 2){
            if (ale > maiorprimo)
                maiorprimo = ale;
        }

    }
    printf("\nmaior primo: %i", maiorprimo);
    int i;
    for (i=0 ; i<tam ; i++){
        if (vet[i] < maiorprimo)
            quantos++;
    }
    printf("\n%i numeros menores que o maior primo sorteado.",quantos);
}
