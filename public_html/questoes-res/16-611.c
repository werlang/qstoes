#include<stdio.h>

main() {
    int i,nota;
    float soma=0;
    for (i=0; i<10; i++) {
            printf("Digite a Nota: ");
            scanf("%i",&nota);
            soma+=nota;
    }
    float media=soma/10;
    printf("A media das 10 notas e: %.1f\n",media);


}
