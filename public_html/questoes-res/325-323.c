/**Escreva um programa que pe�a para o usu�rio informar dois valores na fun��o main.
Estes dois valores dever�o ser atribu�dos � vari�veis globais.
Ent�o chame duas fun��es no main. A primeira deve acessar o valor
destas duas vari�veis globais e mostrar na tela a soma delas. A segunda dever� mostrar o resultado da multiplica��o.**/
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
