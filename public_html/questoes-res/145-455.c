#include<stdio.h>

main(){
    int idade;
    char genero;

    printf("Informe sua idade: ");
    scanf("%i",&idade);
    printf("Informe seu genero (m/f): ");
    scanf(" %c",&genero);

    if (genero == 'm'){
        if (idade >= 18){
            printf("Homem maior de idade");
        }
        else{
            printf("Homem menor de idade");
        }
    }
    if (genero == 'f'){
        if (idade >= 18){
            printf("Mulher maior de idade");
        }
        else{
            printf("Mulher menor de idade");
        }
    }

}
