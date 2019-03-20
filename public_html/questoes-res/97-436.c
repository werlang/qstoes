#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    int q=10;
    srand(time(NULL));
    int i, n[q], maior, menor;
    for (i=0 ; i<q ; i++){
        printf("Informe o valor %i: ",i+1);
        scanf("%i",&n[i]);
        if (i==0){
            maior = n[i];
            menor = n[i];
        }
        else{
            if (n[i] > maior)
                maior = n[i];
            if (n[i] < menor)
                menor = n[i];
        }
    }

    int ale[q], contem=0, j, t=0;
    int *conjuntos = (int*)malloc(sizeof(int)*q);
    while (contem < q){
        contem=0;
        for (i=0 ; i<q ; i++){
            ale[i] = rand()%(maior-menor+1)+menor;
            *(conjuntos+(t*q)+i) = ale[i];
            printf("%i ",ale[i]);
        }
        t++;
        conjuntos = (int*)realloc(conjuntos,sizeof(int) * (t+1) * q);
        printf("\n");
        for (i=0 ; i<q ; i++){
            for (j=0 ; j<q ; j++){
                if (n[i] == ale[j]){
                    contem++;
                    break;
                }
            }
        }
    }
}
