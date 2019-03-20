#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
float dist (float ax, float ay,float bx,float by){
	float da,db,p,ab;
	int i;
	da=bx-ax;
	db=by-ay;

	da=pow(da,2);
    db=pow(db,2);

	p=da+db;
	
    ab=sqrt(p);
	
	return ab;
}


main (){


float ax,ay,bx,by;
int i,j;

printf ("informe a localizaçao do primeiro ponto: \n");
   	printf ("eixo x: ");
   	scanf ("%f",&ax);
   	printf ("eixo y: ");
   	scanf ("%f",&ay);
printf ("informe a localizacao do segundo ponto: \n");
    printf ("eixo x: ");
	scanf ("%f",&bx);
	printf ("eixo y: ");
	scanf ("%f",&by);
	
	float distancia = dist (ax,ay,bx,by);
	printf ("a distancia entre os pontos são: %.1f",distancia);   	
   	
}


