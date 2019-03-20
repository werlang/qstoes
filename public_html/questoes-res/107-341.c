#include <stdio.h>
#include <stdlib.h>
main(){
    float v;
    float x;
    float y;
    float z;
    printf("Questao 107\n\n - Digite a primeira nota:\n");
    scanf("%f",&v);
    printf(" - Digite a segunda nota:\n");
    scanf("%f",&x);
    printf("\n - Digite a terceira nota:\n");
    scanf("%f",&y);
    system("cls");
    z = (v+x+y)/3;
    printf("Nota final: %.2f\n",z);
    system("pause");
    }
