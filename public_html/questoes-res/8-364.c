#include<stdio.h>
#include<conio.h>
/*Questão #8:
Assuntos: Estruturas de seleção (IF/SWITCH).
Pedir para o usuário informar a temperatura de um tanque de gás. Então mostrar na tela o estado do tanque. Considere que o tanque está em estado Normal
 entre 0º e 300 ºC e que o tanque atinge o estado crítico em -50ºC e 500ºC. Para todas as outras temperaturas, ele estará em estado de alerta.*/
main(){
    float temperatura;
	printf("\ninforme a temperatura : ");
	scanf("%f",&temperatura);
	if(temperatura >= 0 && temperatura <= 300){
		printf("status = NORMAL");
	}else if(temperatura <= -50 || temperatura >= 500){
		printf("status = critico");
	}else{
		printf("status = alerta");
	}
}