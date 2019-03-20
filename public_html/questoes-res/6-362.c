#include<stdio.h>
#include<conio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");

    int l1,l2,l3;
    printf("Informe os três lados do triângulo: ");
    scanf("%i %i %i",&l1,&l2,&l3);

    if (l1 == l2 && l1 == l3)
        printf("Equilátero");
    else{
        if (l1 != l2 && l1 != l3 && l2 != l3)
            printf("Escaleno");
        else
            printf("Isósceles");
    }
}
