/*
7 - Escreva um programa que ajude o usu�rio a calcular informa��es sobre um tri�ngulo ret�ngulo.
Pergunte para o usu�rio o que ele deseja saber, de acordo com o menu abaixo:
1 - Hipotenusa H
2 - Cateto A
3 - Cateto B
4 - �ngulo entre A e H
Ent�o baseado na resposta do usu�rio pe�a informa��es sobre o tri�ngulo para que seja poss�vel o c�lculo.
Ent�o realize o c�lculo desejado e informe o resultado na tela.
*/

#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>

main(){
    setlocale(LC_ALL,"portuguese");

    float a,b,h,ang;
    printf("Informe o que voc� deseja saber sobre o tri�ngulo: ");
    printf("\n1 - Hipotenusa H\n2 - Cateto A\n3 - Cateto B\n4 - �ngulo entre A e H\n");
    char op;
    op = getch();
    switch(op){
    case '1':
        printf("Informe o comprimento do cateto A: ");
        scanf("%f",&a);
        printf("Informe o comprimento do cateto B: ");
        scanf("%f",&b);
        h = sqrt(a*a + b*b);
        printf("O valor da hipotenusa H �: %.2f",h);
        break;
    case '2':
        printf("Informe o comprimento da hipotenusa H: ");
        scanf("%f",&h);
        printf("Informe o comprimento do cateto B: ");
        scanf("%f",&b);
        a = sqrt(h*h - b*b);
        printf("O valor do cateto A �: %.2f",a);
        break;
    case '3':
        printf("Informe o comprimento da hipotenusa H: ");
        scanf("%f",&h);
        printf("Informe o comprimento do cateto A: ");
        scanf("%f",&a);
        b = sqrt(h*h - a*a);
        printf("O valor do cateto A �: %.2f",b);
        break;
    case '4':
        printf("Informe o comprimento do cateto A: ");
        scanf("%f",&a);
        printf("Informe o comprimento do cateto B: ");
        scanf("%f",&b);
        ang = tan(b/a) * 180 / 3.14;
        printf("O valor do �ngulo entre A e H �: %.2f",ang);
        break;
    default:
        printf("Op��o inv�lida!");
    }
}
