#include<stdio.h>

main(){
    char letra;
    int valida = 1;
    int cont = 0;
    do{
        scanf("%c",&letra);
        if (letra != 10){
            if ((letra < 'A' || letra > 'Z') && (letra < 'a' || letra > 'z')){
                valida = 0;
                cont++;
            }
        }
    }while(letra != 10); //no windows é o 13
    if (valida == 1)
        printf("Palavra valida.\n");
    else{
        printf("Palavra invalida.\n");
        printf("%i caracteres informados sao invalidos.\n",cont);
    }
}