#include<stdio.h>
#include<time.h>

main(){
	//Escreva um programa que mostre na tela 5 sequ�ncias de rolagens de dados. 
	//Em cada sequ�ncia 4 dados de seis faces dever�o ser rolados (a rolagem de um dado dever� ser feita atrav�s da gera��o de um n�mero aleat�rio entre 1 e 6). 
	//Ao fim de cada sequ�ncia, a soma dos 3 maiores dados deve ser mostrada (dica: some todos 4, subtraia o valor do menor).
	srand(time(NULL)); //inicia a sequencia
	
	int x,i,n,soma,menor,maiores;
	for (x=0;x<5;x++){
		soma=0;
		menor=0;
		maiores=0;
		for(i=0;i<4;i++){
			n=rand()%6+1;
			printf("%i\n",n);
			soma+=n;
			if(i==0){
				menor=n;
			}
			if(n<menor){
				menor=n;
			}
		}
		maiores=soma-menor;
		printf("A soma dos 3 maiores numeros �: %i\n",maiores);	
	}

}
