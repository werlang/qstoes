#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*Escreva um programa que contenha uma matriz 10x10 preenchida com '.' (caractere ponto).
Na posição central preencha com um caractere '@' (arroba). Então, ao ser digitados as teclas w,s,a,d (ASCII 119,115,97,100 respectivamente)
a arroba deve se mover para cima, baixo, esquerda ou direita (dependendo da tecla pressionada).
Entre cada tecla pressionada limpe a tela (comando system("cls")) e mostre o conteúdo da matriz linha a linha na tela.*/

main()
{
	char matriz[10][10];
	int lin=0, col=0;
	
	for(lin=0; lin<10; lin++)
	{
		for(col=0; col<10; col++)
		{
			matriz[lin][col]= '.';
		}
	}
	
	matriz[4][5]= '@';
	
	int l=4,c=5;
	char letra;
	
	while(1)
	{
		system("cls");
			for(lin=0; lin<10; lin++)
			{
				for(col=0; col<10; col++)
				{
					printf(" %c ",matriz[lin][col]);
				}
				
				printf("\n");
			}
			letra = getch();
			matriz[l][c] = '.';
		
			if(letra == 'w' && l>0)
				l--;
			if(letra == 's' && l<9)
				l++;
			if(letra == 'a' && c>0)
				c--;
			if(letra == 'd' && c<9)
				c++;
			
			matriz[l][c]= '@';
		
		
	}
	
	
	

	
	
	
	
	
}
