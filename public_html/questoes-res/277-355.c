/**Escreva uma função que receba por valor um caractere, e por referência um vetor tipo
char (string). Esta função deve concatenar esta string com o caractere,
sem usar a função strcat. Dica: use o caractere '\0' para demarcar o fim de string.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void concatena(char *p){/// *p ponteiro que aponta para a primeira posição da estring que esta no main
    char carc;
    printf("\nDigite um caracter:\n");
    scanf(" %c",&carc);/// insere o caracter de sua preferencia
    int t=strlen(p),i;/// captura o tamanho da string que o ponteiro esta apontando
    for(i=0;i<=t;i++){
        if(i==(t)){/// quando i for igual ao tamanho da string
            *(p+i)=carc;/// na posição que esta alocado o '\0' ele coloca o caracter digitado
            *(p+i+1)='\0';/// e para dar fim a estring a posição depois do caracter alocado ele coloca o '\0'
        }
    }
}
int main(){
    char frase[50];
    printf("Digite uma frase ou palavra:\n");
    gets(frase);/// digita a frase
    concatena(&frase);/// manda para a função o parametro do posicionamento de memoria da string
    printf("\nFrase concatenada:\n%s",frase);/// printa a frase concatenada
    return 0;
}
