/*Escreva um programa que pe�a para o usu�rio informar n�meros at�
que o usu�rio digite 0 ou 10 n�meros sejam informados.
Ent�o mostre na tela a lista dos que s�o divis�veis por 2, depois por 3,
depois por 4, at� o 10.*/

#include<stdio.h>

main(){
    int vet[10], i, a=1;

    for(i=0; i<10; i++){
    printf("digite um valor: \n");
    scanf("%i", &vet[i]);
    if(vet[i]==0)
        break;
    }

    for(i=0; i<10; i++){
    if(vet[i]%a==0){
        printf("Numero %i divisivel por %i \n",vet[i], a);
        a++;
    }
    }
}
