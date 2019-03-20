/**Escreva um programa que sorteie um n�mero entre -100 e 100. Ent�o pe�a para o usu�rio adivinhar o n�mero sorteado.
 Em cada tentativa, mostre na tela se o n�mero escolhido � maior ou menor que o sorteado. Caso ele n�o acerte em at� 10
  tentativas mostre uma mensagem e encerre o programa. Caso acerte em alguma das 10 tentativas, mostre uma mensagem parabenizando-o
  e mostrando quantas tentativas ele utilizou e encerre o programa.**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i=0, x, n;
    x=rand()%201-100;

    do{
        printf("Adivinhe um numero: ");
        scanf("%d", &n);
        if(x>n){
            if(n!=x)
            printf("maior que %d\n", n);
        }
        else if(x<n){
            if(n!=x)
            printf("menor que %d\n", n);
        }
        i++;
    }
    while(x!=n && i<10);
    if(n==x)
        printf("Parabens!!!\n%d Tentativas",i);
        else{
            printf("Game Over!!!\nR:%d",x);
        }

    return 0;
}
