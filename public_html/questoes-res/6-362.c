#include<stdio.h>
#include<conio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");

    int l1,l2,l3;
    printf("Informe os tr�s lados do tri�ngulo: ");
    scanf("%i %i %i",&l1,&l2,&l3);

    if (l1 == l2 && l1 == l3)
        printf("Equil�tero");
    else{
        if (l1 != l2 && l1 != l3 && l2 != l3)
            printf("Escaleno");
        else
            printf("Is�sceles");
    }
}
