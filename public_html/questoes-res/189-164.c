#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<stdio.h>
main(){
    setlocale(LC_ALL, "Portuguese");

    int area, hipo, a, b;

    printf("Informe os catetos:\n");
    scanf("%i %i",&a,&b);

    area= (a*b)/2;
    hipo= sqrt( pow(a,2)+ pow(b,2));

    printf("Área do triângulo é %i e a Hipotenusa é %i.",area,hipo);
}
