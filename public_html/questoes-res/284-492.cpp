#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Crie uma fun��o que receba um valor inteiro por refer�ncia e retorne o resto da divis�o deste n�mero por 10.
Altere tamb�m o valor da vari�vel passada por refer�ncia, fazendo com que esta receba o resultado inteiro da divis�o por 10.
Fa�a um programa que imprima invertido os nomes dos algarismos de um n�mero inteiro (Use a sua fun��o).
*/
int resto_divisao(int *n){
    int resultado;
     resultado=(*n)%10;//pega o resto da divis�o
     //printf("%i\n",resultado);
     *n=(*n)/10;//divis�o por inteiro
     //printf("%i\n",*n);
     return resultado;

}
int main(){
    int num;
	printf("Informe um numero para realizar o resto da divisao:");
	scanf("%i",&num);
	printf("O resto da divisao eh: %i\n",resto_divisao(&num));
	printf("A divisao inteira eh: %i\n",num);


return 0;
}
