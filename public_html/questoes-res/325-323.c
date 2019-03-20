/**Escreva um programa que peça para o usuário informar dois valores na função main.
Estes dois valores deverão ser atribuídos à variáveis globais.
Então chame duas funções no main. A primeira deve acessar o valor
destas duas variáveis globais e mostrar na tela a soma delas. A segunda deverá mostrar o resultado da multiplicação.**/
#include<stdio.h>
int a,b;
void soma(){
    int s=a+b;
    printf("%i + %i = %i\n",a,b,s);
}
void mult(){
    int m=a*b;
    printf(" %i * %i = %i ",a,b,m);
}
int main(){
    scanf(" %i %i",&a,&b);
    soma();
    mult();
    return 0;
}
