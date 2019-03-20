#include<stdio.h>
#include<conio.h>

main(){
    char letra;
    int i;
    int maiusculas=0;
    int minusculas=0;
    int numeros=0;
    for (i=1 ; i<=15 ; i++){
        printf("\nInforme um caractere: ");
        letra = getche();
        if (letra >= 'a' && letra <= 'z'){
            minusculas++;
        }
        if (letra >= 'A' && letra <= 'Z'){
            maiusculas++;
        }
        if (letra >= '0' && letra <= '9'){
            numeros++;
        }
    }
    printf("\n%i caracteres sao letras maiusculas\n",maiusculas);
    printf("%i caracteres sao letras minusculas\n",minusculas);
    printf("%i caracteres sao numeros\n",numeros);
}
