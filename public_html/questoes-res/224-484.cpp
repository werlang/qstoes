#include<stdio.h>
/*Escreva um programa que pe�a para o usu�rio digitar notas de N alunos.
 Ao fim, mostre a nota do aluno que obteve maior e menor m�dia,
bem como a contagem de quantos aprovaram e quantos reprovaram (m�dia 6).*/
main(){
	int alunos,nota,apro,repro,mamed,memed;
	printf("de quantos alunos ira digitar notas: ");
		scanf("%i",&alunos);
	int i=0;
	for(i=1;i<=alunos;i++){
		printf("\ndigite a nota do aluno %i:  ",i);
			scanf("%i",&nota);
		
		if(nota>=6)
			apro++;
		else
			repro++;
		
		if (i==1){
			mamed=nota;
			memed=nota;
		}
		else if(nota>mamed)
			mamed=nota;
		else if(nota<memed)
			memed=nota;
		
	}
	
	printf("\nmaior media: %i",mamed);
	printf("\nmenor media: %i",memed);
	printf("\nnumero de aprovados: %i",apro);
	printf("\nnumero de reprovados: %i",repro);
	
	
	
}
