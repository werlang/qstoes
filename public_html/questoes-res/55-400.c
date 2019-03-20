#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

main(){
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int n, ale;
    int vet[10],i;
    int achou=0;
    printf("Informe um número: ");
    scanf("%i",&n);
    int cont=0;
    printf("Números aleatórios: ");
    while (cont < 10 && cont < n){
        ale = rand()%(n+1);
        achou = 0;
        for (i=0 ; i<cont ; i++){
            if (vet[i] == ale)
                achou++;
        }
        if (achou == 0){
            vet[cont] = ale;
            cont++;
            printf("%i ",ale);
        }
    }
}
