/*Escreva um programa que
pe�a para o usu�rio informar 5 n�meros,
e ent�o mostre na tela a lista dos que s�o maiores do que a m�dia.*/

#include<stdio.h>

main(){
    int vet[5], i,media=0;

    for(i=0; i<5; i++){
    printf("informe um valor: \n");
    scanf("%i", &vet[i]);
    }

    media= (vet[0]+vet[1]+vet[2]+vet[3]+vet[4])/5;
    printf("Media %i \n", media);

    for(i=0; i<5; i++){
    if(vet[i]> media)
        printf("Maiores que a media %i \n", vet[i]);
}
}
