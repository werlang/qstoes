/**Crie uma fun��o que receba por refer�ncia um vetor do tipo char.
A fun��o dever� formatar a string dada como entrada de maneira que ao t�rmino da execu��o
da fun��o a primeira letra de todas as palavras sejam mai�sculas e as outras letras min�sculas.
O vetor recebido por refer�ncia dever� ser acessado atrav�s de um ponteiro.**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    void editor(char *p){/// p ponteiro q acessa as posi��es da string
        int t=strlen(p),i;/// captura o tamanho da string
        for(i=0;i<t;i++){
            if(*(p+i)>='a' && *(p+i)<='z'){/// verifica se o conteudo que esta na posi��o esta no alfabeto minusculo
                if(i==0 || *(p+i-1)==' ')/// caso seja o primeiro a ser verificado ou se o caracter anterior seja um espa�o el modifica o caracter para maiuscula
                    *(p+i)-=32;/// transforma para maiuscula
            }
            if(i!=0 && *(p+i)>='A' && *(p+i)<='Z' && *(p+i-1)!=' ')/// caso nao seja a primeira verifica��o e seja do alfabeto maiusculo e o caracter anterior seja diferente de espa�o
                    *(p+i)+=32;/// transforma para minuscula
        }
    }
    int main(){
        char frase[500];
        gets(frase);/// digita a frase
        editor(&frase);/// desse jeito envia a posi��o do primeiro caracter da string
        printf("\nfrase edititada\n%s",frase);/// printa a string na tela
        return 0;
    }
