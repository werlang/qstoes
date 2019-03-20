#include<stdio.h>
#include<stdlib.h>
/*Escreva um algoritmo que peça para o usuário preencher uma matriz de 3x5 com números.
Fazer a validação para só permitir números positivos. Então mostrar na tela o resultado do somatório dos números de cada coluna.*/

main()
{

	int matriz[3][5],lin,col;
	
	for(lin=0; lin<3; lin++)
	{
		for(col=0; col<5; col++)
		{
			scanf ("%d", &matriz[lin][col]);
			while(matriz[lin][col]<0)
			{
				printf("numero invalido, digite um positivo\n");
				scanf ("%d", &matriz[lin][col]);
			}
		}
	}
			
   	
		
		
		for(lin=0; lin<3; lin++)
		{
			for(col=0; col<5; col++)
			{
			printf(" %i |",matriz[lin][col]);
				
			}
			printf("\n\n");
		
		}
	int soma=0;
	for(col=0; col<5; col++)
	{
		soma=0;
		for(lin=0; lin<3; lin++)
		
		{
			soma+= matriz[lin][col];
			
			
		}
		printf("soma %i \n",soma);
		
	}
	
}
		





