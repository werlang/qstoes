#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

main(){
    setlocale(LC_ALL,"portuguese");

    srand(time(NULL));
    int n = rand()%201-100;

    int i, adiv,cont=0;
    for (i=0 ; i<10 ; i++){
        printf("Adivinhe o número sorteado: ");
        scanf("%i",&adiv);
        cont++;
        if (n > adiv)
            printf("O número sorteado é maior que %i\n",adiv);
        if (n < adiv)
            printf("O número sorteado é menor que %i\n",adiv);
        if (n == adiv)
            break;
    }
    if (adiv == n)
        printf("Você acertou em %i tentativas.",cont);
    else
        printf("Você esgotou as tentativas.");
}
