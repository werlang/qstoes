/**Escrever uma função recursiva que calcule o fatorial.**/

#include<stdio.h>
#include<stdlib.h>
int fatorial(int n){
    if(n==1)/// quando na ultima chamada o n for igual a 1
        return 1;///retorna um para a ultima chamada
    return n*fatorial(n-1);/// se for pedido fatorial de 4 vem retornando cada chamada de traz para frente 1*2.. 2*3...3*4=24
}
int main(){
    int numer;
    printf("Informe um numero: ");
    scanf("%i",&numer);
    int res=fatorial(numer);
    printf("\nfatorial:%i",res);
    return 0;
}
