/**Escreva um programa que peça para o usuário uma frase e uma palavra.
Exclua da frase todas as ocorrências da palavra.**/

#include<stdio.h>
#include<string.h>

int main(){
    char fras[500], palv[20],aux[500],*p,*q;
    int cont=0;
    printf("Informe uma frase:\n");
    gets(fras);
    printf("Informe uma palavra:\n");
    gets(palv);
    strcpy(aux,fras);/// copia a frase para a variavel auxiliar
    p=strstr(fras,palv);/// p aponta para a posição da primeira ocorrencia primeiro caracter
    q=strstr(aux,palv);/// q faz a mesma coisa q o ponteiro p mas faz o procedimento na string aux
    while(p!=NULL){/// vai repetir ate q não tenha mais nenhuma ocorrencia na frase
        q+=strlen(palv);/// anda na string auxiliar que serve como espelho da antiga string, e faz o ponteiro andar o numero de caracteres da palavra original
        strcpy(p,q);/// aqui copia as cordenadas do ponteiro q para o p para o p apontar apartir de onde ele estava antes da troca
        p=strstr(p,palv);/// aqui ele faz novamente a comparação se existe ocorrencia da string palv na frase apartir de onde ele estava
        q=strstr(q,palv);/// faz a mesma coisa para a variavel aux andar junta, e servi como guia da string principal
    }
    printf("\nstring formatada:\n%s",fras);/// mostra a string transformada
    return 0;
}
