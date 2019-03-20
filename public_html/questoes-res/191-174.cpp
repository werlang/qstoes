#include <stdio.h>

main(){
	int dia,horas,segundos,minutos,segundo;
	
	printf("Digite um valor em segundos:");
	scanf("%i",&segundos);
	
	dia=segundos/86400;
	printf("\n%i dia(s)",dia);
	
	horas=((segundos%86400)/3600);
	printf(",%i hora(s)",horas);
	
	minutos=((segundos%86400)/60);
	printf(",%i minuto(s)",minutos);
	
	segundo=((segundos%86400)-(minutos*60));
	printf(",%i segundo(s)",segundo);
	
	
}
