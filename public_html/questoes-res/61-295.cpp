#include<stdio.h>
#include<stdlib.h>
/*Escreva um algoritmo que pe�a para o usu�rio preencher uma matriz de 3x5 com n�meros.
Fazer a valida��o para s� permitir n�meros positivos. Ent�o mostrar na tela o resultado do somat�rio dos n�meros de cada coluna.*/

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
		





