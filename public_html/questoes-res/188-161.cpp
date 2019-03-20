#include<stdio.h>
/*Elabore um programa que calcule e mostre a média das 5 notas de um aluno*/
 
 main(){
 	int n1, n2, n3, n4, n5;
 	float media;
 	
 	printf("digite a primeira nota: ");
 		scanf("%i",&n1);
 		
 	printf("digite a segunda nota: ");
 		scanf("%i",&n2);
 		
 	printf("digite a terceira nota: ");
 		scanf("%i",&n3);
 		
 	printf("digite a quarta nota: ");
 		scanf("%i",&n4);
 		
 	printf("digite a quinta nota: ");
 		scanf("%i",&n5);
 		
 	media=(n1+n2+n3+n4+n5)/5;
 	
 	printf("sua media foi de: %.2f", media);
 	
 	
 	
 }

