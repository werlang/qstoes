#include <stdio.h>
main(){
    float nota1,nota2,nota11,nota22;
    printf("Informe a nota 1 do aluno1:");
    scanf("%f",&nota1);
    printf("Informe a nota 2 do aluno1:");
    scanf("%f",&nota2);
    float media=(nota1+nota2)/2;
    printf("media=%.1f",media);

    printf("\nInforme nota 1 do aluno2:");
    scanf("%f",&nota11);
    printf("Informe nota 2 do aluno2:");
    scanf("%f",&nota22);
    float media2=(nota11+nota22)/2;
    printf("media=%.1f",media2);
    if(media>media2){
        printf("\naluno 1 teve media maior com:%.1f",media);
    }
     if(media2>media){
        printf("\naluno 2 teve media maior com:%.1f",media2);
    }
}
