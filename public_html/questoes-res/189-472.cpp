#include <stdio.h>
#include <math.h>
main(){
	float altura,base,area,hipo;
		
		printf("Digite o valor do cateto altura:");
		scanf("%f",&altura);
		printf("Digite o valor do cateto base:");
		scanf("%f",&base);
		
		area=((altura*base)/2);
		hipo=sqrt(pow(altura,2)+ pow(base,2));
		
		printf("Area da base do triangulo: %.2f",area);
		printf("\nHipotenusa do triangulo: %.2f",hipo);
}
