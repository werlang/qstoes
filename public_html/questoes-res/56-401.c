#include<stdio.h>

main(){
    int vet[10];
    int i;

    for (i=0 ; i<10 ; i++){
        printf("Informe o %io valor: ",i+1);
        scanf("%i",&vet[i]);
    }

    int trocas;
    int aux;

    do{
        trocas = 0;
        for (i=0 ; i<9 ; i++){
            if (vet[i] < vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocas++;
            }
        }
    }while(trocas > 0);

    for (i=0 ; i<10 ; i++)
        printf("%i ",vet[i]);
}
