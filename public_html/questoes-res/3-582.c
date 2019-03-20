#include<stdio.h>
    main(){
        int numero;
        printf("Digite um numero:");
        scanf("%i",&numero);

        if(numero>0){
                printf("%i e maior que 0",numero);
        }
        if(numero<0){
                printf("%i e menor que 0",numero);
        }
        if(numero==0){
                printf("%i e igual a 0",numero);
        }
    }
