#include <stdio.h>
/*Fa�a um programa que dado um valor inicial A1,
 uma raz�o r, e o n�mero de termos n, 
 calcule o termo An da PA. 
Com os mesmo dados, encontre o somat�rio desta PA*/
main(){
	int a1,sn,razao,num_termos,an;
	
	printf("Informe o valor inicial:");
	scanf("%i",&a1);
	printf("\nInforme a razao:");
	scanf("%i",&razao);
	printf("\nInforme o numero de termos n:");
	scanf("%i",&num_termos);
	
	an=(a1+(razao*(num_termos-1)));
	printf("\nValor do An:%i",an);
	
	sn=((a1+an)*num_termos)/2;
	printf("\n\nSoma dos termos: %i",sn);
}
