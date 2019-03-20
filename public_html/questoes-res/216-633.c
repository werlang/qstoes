#include<stdio.h>

main() {
    int numero=0,maior=0,menor=0,par=0;
    int impar=0,contp=0,conti=0,mediai,mediap,dif;

    while(numero>=0){
        printf("informe um  numero: ");
        scanf("%i",&numero);

        if(numero>maior){
            maior=numero;
        }
        if(numero<maior){
            menor=numero;
        }
        if(numero%2==0){
            par+=numero;
            contp++;
        }
        else{
            impar+=numero;
            conti++;
        }

    }
        mediap=par/contp;
        mediai=impar/conti;
        dif=maior-menor;
        printf(" Media dos Pares e: %i\n",mediap);
        printf("Media dos impares e: %i\n",mediai);
        printf("Diferenca entre o Maior %i e o Menor %i e: %i",maior,menor,dif);


}
