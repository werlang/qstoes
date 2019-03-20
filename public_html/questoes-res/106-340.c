#include <stdio.h>
#include <stdlib.h>
main(){
    float x;
    float y;
    float preco;
    float z;
    printf("Questao 106\n\n - Digite o o cunsumo de gasolina do seu carro em km/l:\n");
    scanf("%f",&x);
    printf(" - Qualdistancia sera percorrida durante o percurso:\n");
    scanf("%f",&y);printf(" - Qualdistancia o valor do combustivel:\n");
    scanf("%f",&preco);
    system("cls");
    z = (x/y)*preco;
    printf("Voce gatasra: %.2f R$\n",z);
    system("pause");
    }
