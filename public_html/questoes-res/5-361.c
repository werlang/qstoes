#include<stdio.h>
#include<conio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");

    char g1,g2,g3,g4;
    int i1,i2,i3,i4;
    int contm=0, contf=0;

    printf("Informe a idade da pessoa 1: ");
    scanf("%i",&i1);
    printf("Informe o gênero da pessoa 1: ");
    scanf(" %c",&g1);

    printf("Informe a idade da pessoa 2: ");
    scanf("%i",&i2);
    printf("Informe o gênero da pessoa 2: ");
    scanf(" %c",&g2);

    printf("Informe a idade da pessoa 3: ");
    scanf("%i",&i3);
    printf("Informe o gênero da pessoa 3: ");
    scanf(" %c",&g3);

    printf("Informe a idade da pessoa 4: ");
    scanf("%i",&i4);
    printf("Informe o gênero da pessoa 4: ");
    scanf(" %c",&g4);

    if (i1 > 18){
        if (g1 == 'm')
            contm++;
        if (g1 == 'f')
            contf++;
    }

    if (i2 > 18){
        if (g2 == 'm')
            contm++;
        if (g2 == 'f')
            contf++;
    }
    if (i3 > 18){
        if (g3 == 'm')
            contm++;
        if (g3 == 'f')
            contf++;
    }
    if (i4 > 18){
        if (g4 == 'm')
            contm++;
        if (g4 == 'f')
            contf++;
    }

    printf("%i pessoas são mulheres maiores de 18 anos e %i pessoas são homens maiores de 18 anos",contf,contm);
}
