#include <stdio.h>
#include <stdlib.h>
main(){
    float v;
    float x;
    float y;
    float v1;
    float v2;
    float z;
    printf("Questao 188\n\n - Digite a primeira nota:\n");
    scanf("%f",&v);
    printf(" - Digite a segunda nota:\n");
    scanf("%f",&x);
    printf("\n - Digite a terceira nota:\n");
    scanf("%f",&y);
    printf("\n - Digite a quarta nota:\n");
    scanf("%f",&v1);
    printf("\n - Digite a quinta nota:\n");
    scanf("%f",&v2);
    system("cls");
    z = (v+x+y+v1+v2)/5;
    printf("Nota final: %.2f\n",z);
    system("pause");
    }
