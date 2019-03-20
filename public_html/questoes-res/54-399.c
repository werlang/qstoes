#include<stdio.h>

main(){
    char frase[20], letra;
    int tam=0;

    printf("Informe uma frase: ");
    while(letra != 13 && tam<20){ //cai fora quando digitar um enter ou alcançar tamanho 20
        letra = getche(); //captura letra
        frase[tam] = letra; //guarda no vetor
        tam++; //incrementa o vetor pra saber onde será a proxima posicao a ser armazenada no vetor
    }

    printf("\n\nFrase formatada:\n");
    int i;
    int palavra=1; //contador de palavras
    for(i=0 ; i<tam ; i++){ //percorre o vetor
        if (palavra%2==1 && frase[i] >= 'a' && frase[i] <= 'z') //se for uma palavra impar, e o caractere estiver entre a-z
            frase[i] -= 32; //converte pra maiusculo 97(a) - 32 = 65(A)
        if (palavra%2==0 && frase[i] >= 'A' && frase[i] <= 'Z') //se for uma palavra par, e o caractere estiver entre A-Z
            frase[i] += 32; //converte pra minusculo 65(A) + 32 = 97(a)
        if (frase[i] == ' ') //se o caracterere for um espaço
            palavra++; //incrementa o contador pra saber que iniciou uma nova palavra.
        printf("%c",frase[i]); //mostra o caractere na tela.
    }
}
