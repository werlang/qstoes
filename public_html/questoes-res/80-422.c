#include<stdio.h>
#include<stdlib.h>

/* Escreva uma função que receba um vetor inteiro e seu tamanho.
 A função deve mostrar na tela o maior elemento deste vetor. */

int vet[20]; /* Vetor global pode ser declarado como qualquer tamanho (NESTE CASO), pois quem escolhe o tam e o usuario */
int n; /* variavel n usada para receber os numeros do usuario */
int i; /* variavel i usada no for */
int tam; /* Variavel tam utilizada para o usuario informar qual o tamanho que ele deseja usar no vetor */
int resultado; /* Variavel usada como retorno da funcao */

/* Declaração de variaveis globais para que eu não tenha que ficar declarando elas a todo momento dentro do main
e também dentro da função maior utilizada para saber qual e o maior numero dentro do vetor */

int maior(int vet[], int tam){
	int maior_num=vet[0];
 	for(i=0 ; i<tam ; i++){
 		if(vet[i] > maior_num){
 			maior_num = vet[i];
		 }
	 }
	 resultado=maior_num;
	 return resultado;
}
main(){
	printf("Digite o tamanho do vetor que voce deseja: \n");
	scanf("%i",&tam);

	for(i=0 ; i<tam ; i++){
		printf("Informe um valor: \n");
		scanf("%i",&n);
		vet[i]=n;
	}
	resultado=maior(vet,tam);
	printf("O maior elemento desde vetor e o numero %i ",resultado);
}
