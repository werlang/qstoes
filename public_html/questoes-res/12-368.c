/*
7 - Escreva um programa que ajude o usuário a calcular informações sobre um triângulo retângulo.
Pergunte para o usuário o que ele deseja saber, de acordo com o menu abaixo:
1 - Hipotenusa H
2 - Cateto A
3 - Cateto B
4 - Ângulo entre A e H
Então baseado na resposta do usuário peça informações sobre o triângulo para que seja possível o cálculo.
Então realize o cálculo desejado e informe o resultado na tela.
*/

#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>

main(){
    setlocale(LC_ALL,"portuguese");

    float a,b,h,ang;
    printf("Informe o que você deseja saber sobre o triângulo: ");
    printf("\n1 - Hipotenusa H\n2 - Cateto A\n3 - Cateto B\n4 - Ângulo entre A e H\n");
    char op;
    op = getch();
    switch(op){
    case '1':
        printf("Informe o comprimento do cateto A: ");
        scanf("%f",&a);
        printf("Informe o comprimento do cateto B: ");
        scanf("%f",&b);
        h = sqrt(a*a + b*b);
        printf("O valor da hipotenusa H é: %.2f",h);
        break;
    case '2':
        printf("Informe o comprimento da hipotenusa H: ");
        scanf("%f",&h);
        printf("Informe o comprimento do cateto B: ");
        scanf("%f",&b);
        a = sqrt(h*h - b*b);
        printf("O valor do cateto A é: %.2f",a);
        break;
    case '3':
        printf("Informe o comprimento da hipotenusa H: ");
        scanf("%f",&h);
        printf("Informe o comprimento do cateto A: ");
        scanf("%f",&a);
        b = sqrt(h*h - a*a);
        printf("O valor do cateto A é: %.2f",b);
        break;
    case '4':
        printf("Informe o comprimento do cateto A: ");
        scanf("%f",&a);
        printf("Informe o comprimento do cateto B: ");
        scanf("%f",&b);
        ang = tan(b/a) * 180 / 3.14;
        printf("O valor do ângulo entre A e H é: %.2f",ang);
        break;
    default:
        printf("Opção inválida!");
    }
}
