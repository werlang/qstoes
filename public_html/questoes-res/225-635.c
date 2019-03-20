/**Escreva um programa que calcule a soma de todos números inteiros dentro do intervalo entre A e B. Peça para o usuário informar os valores de A e B.
Faça a verificação para garantir que A seja menor que B.**/
#include<stdio.h>
main(){
    int n,soma=0,a,b,i;
    printf("Informe o valor A:\n",a);
    scanf("%i",&a);
    printf("Informe o valor B:\n",b);
    scanf("%i",&b);
    if(a<b){
        for(i=1; i<=b; i++){
        if(i>1 && i<b)
        soma=soma+i;
        }
    }
    printf("A soma dos numeros inteiros do intervalo entre A e B: = %i \n",soma);
}
