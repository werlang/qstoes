#include<stdio.h>
#include<conio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");
    int n,tam=0;
    int vet[10];
    printf("Informe números. 0 para encerrar: ");
    while (tam<10 && n!=0){
        scanf("%i",&n);
        vet[tam] = n;
        tam++;
    }

    int i,j;
    for (i=2 ; i<=10 ; i++){
        printf("Os números divisíveis por %i são:\n",i);
        for (j=0 ; j<tam ; j++){
            if (vet[j]%i == 0)
                printf("%i ",vet[j]);
        }
        printf("\n");
    }
    getch();
}
