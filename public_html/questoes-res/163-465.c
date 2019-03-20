#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char *crypt(char frase[]){
    int t = strlen(frase);
    int soma = 0, i;
    for (i=0 ; i<t ; i++){
        soma += frase[i];
    }
    double eq = pow(10,16) * log(soma);
    int nval=0;
    int dig, ncasas = 15;
    char *letras = (char*)malloc(sizeof(char)*9);
    while (nval < 8){
        dig = (int)(eq/pow(10,ncasas));
        eq = eq - dig * pow(10,ncasas);
        ncasas -= 2;
        letras[nval] = (dig%25) + 'a';
        nval++;
    }
    letras[8] = '\0';
    return letras;
}

main(){
    char frase[100], *result = NULL;
    printf("Informe uma frase: ");
    gets(frase);
    result = crypt(frase);
    printf("Chave criptografica: %s",result);
}
