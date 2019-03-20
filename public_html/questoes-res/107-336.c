#include<stdio.h>
main(){
    float nota1,nota2,nota3;
    printf("Informe a nota do primeiro Trimestre: ");
    scanf ("%f",&nota1);
    printf("Informe a nota do segundo Trimestre: ");
    scanf ("%f",&nota2);
    printf("Informe a nota do terceiro Trimestre: ");
    scanf ("%f",&nota3);
    float media,soma;
    soma=nota1+nota2+nota3;
    media=soma/3;
    printf("Sua media anual e de: %.1f",media);
        }
