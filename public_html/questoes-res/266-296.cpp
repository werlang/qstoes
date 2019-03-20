#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*Escreva um programa que preencha e mostre na tela uma matriz de 10 linhas por 100 colunas com números aleatórios.
Na primeira linha deverão conter números entre 1 e 10, na segunda entre 11 e 20, na terceira entre 21 e 30, e assim por diante.*/

main()
{

	int matriz[10][100],lin,col;
	srand(time(NULL));
	
	int menor=1,maior=10;
	for(lin=0; lin<10; lin++)
	{
		for(col=0; col<100; col++)
		{
			matriz[lin][col] =maior - rand () %(maior-menor+1);
			
			
			
		}
			maior+=10;
			menor+=10;
	}
		
		for(lin=0; lin<10; lin++)
		{
			for(col=0; col<100; col++)
			{
				printf(" %i |",matriz[lin][col]);
				
			}
			printf("\n\n");
		
		}
	
	
}
