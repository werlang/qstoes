#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Crie uma função que receba um valor inteiro por referência e retorne o resto da divisão deste número por 10.
Altere também o valor da variável passada por referência, fazendo com que esta receba o resultado inteiro da divisão por 10.
Faça um programa que imprima invertido os nomes dos algarismos de um número inteiro (Use a sua função).
*/
int resto_divisao(int *n){
    int resultado;
     resultado=(*n)%10;//pega o resto da divisão
     //printf("%i\n",resultado);
     *n=(*n)/10;//divisão por inteiro
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
