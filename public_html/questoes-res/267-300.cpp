#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/*Elabore um programa que preencha uma matriz bidimensional de tamanho 1000 com n�meros aleat�rios de -50 at� 50.
Ap�s pe�a para o usu�rio informar uma coluna e uma linha. Mostre na tela o resultado de multiplica��o de L por C,
onde L � o somat�rio de todos elementos da linha informada e C � o somat�rio de todos elementos da coluna informada.*/

main()
{
	int mat[3][3],lin,col;
//	srand(time(NULL));
	
	for(lin=0; lin<3; lin++)
	{
		for(col=0; col<3; col++)
		{
			mat[lin][col]= rand() %(50 - -49-1)+(-50);
		}
	}
	
	for(lin=0; lin<3; lin++)
	{
			for(col=0; col<3; col++)
			{
				printf("  %i  ",mat[lin][col]);
			}
		printf("\n\n");	
	}
	
	int nl,nc,somaL=0, somaC=0;
	
	printf("digite uma linha: ");
		scanf("%i",&nl);
		
	printf("digite uma coluna: ");
		scanf("%i",&nc);
	
	for(lin=0; lin<3; lin++)
	{
			for(col=0; col<3; col++)
			{
				 if(lin == nl-1)
				{
					somaL += mat[lin][col];
				}
				if(col == nc-1)	
				{
					somaC += mat[lin][col];
				}
			}
		printf("\n\n");	
	}
	
	printf(" soma da linha %i e:  %i\n", nl, somaL);
	printf(" soma da coluna %i e:  %i\n", nc,somaC);
	
	
	int multi=somaL * somaC;
	
	printf(" multiplica��o =  %i\n",multi);
	
	system("pause");
	
	
	
	
}
