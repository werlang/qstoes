#include<stdio.h>

main () {
    int idade;
    printf("Informe sua idade: ");
    scanf("%i",&idade);

    if(idade<13){
         printf("Crianca");
    }

    if(idade>=13 && idade<=19){
           printf("Adolecente");
    }
    else{

        if(idade>=20 && idade<=60){
            printf("Adulto");
        }
        else{
            if(idade>=60){
                printf("Idoso");
            }
        }
    }

}
