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
        printf("Adivinhe o n�mero sorteado: ");
        scanf("%i",&adiv);
        cont++;
        if (n > adiv)
            printf("O n�mero sorteado � maior que %i\n",adiv);
        if (n < adiv)
            printf("O n�mero sorteado � menor que %i\n",adiv);
        if (n == adiv)
            break;
    }
    if (adiv == n)
        printf("Voc� acertou em %i tentativas.",cont);
    else
        printf("Voc� esgotou as tentativas.");
}
