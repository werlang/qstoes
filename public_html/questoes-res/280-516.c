/**Crie uma função que receba por referência um vetor do tipo char.
A função deverá formatar a string dada como entrada de maneira que ao término da execução
da função a primeira letra de todas as palavras sejam maiúsculas e as outras letras minúsculas.
O vetor recebido por referência deverá ser acessado através de um ponteiro.**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    void editor(char *p){/// p ponteiro q acessa as posições da string
        int t=strlen(p),i;/// captura o tamanho da string
        for(i=0;i<t;i++){
            if(*(p+i)>='a' && *(p+i)<='z'){/// verifica se o conteudo que esta na posição esta no alfabeto minusculo
                if(i==0 || *(p+i-1)==' ')/// caso seja o primeiro a ser verificado ou se o caracter anterior seja um espaço el modifica o caracter para maiuscula
                    *(p+i)-=32;/// transforma para maiuscula
            }
            if(i!=0 && *(p+i)>='A' && *(p+i)<='Z' && *(p+i-1)!=' ')/// caso nao seja a primeira verificação e seja do alfabeto maiusculo e o caracter anterior seja diferente de espaço
                    *(p+i)+=32;/// transforma para minuscula
        }
    }
    int main(){
        char frase[500];
        gets(frase);/// digita a frase
        editor(&frase);/// desse jeito envia a posição do primeiro caracter da string
        printf("\nfrase edititada\n%s",frase);/// printa a string na tela
        return 0;
    }
