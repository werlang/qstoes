/**Escreva uma fun��o que receba por par�metro um vetor e
o n�mero de elementos deste vetor, e retorne a m�dia destes n�meros.**/
#include<stdio.h>
#include<stdlib.h>
    int i;
    float media(int vet[],int qnt){/// fun��o media( int vet[] recebe copia dos valores do vetor valr do main, int qnt recebe copia do valor qnt do main
        float soma=0,res;
        for(i=0;i<qnt;i++)
            soma+=vet[i];/// soma todos os valores do vetor
        res=(float)soma/qnt;/// faz a media
        return res;
    }

    int main(){
        int qnt;
        printf("Informe a quantidade de valores a serem inseridos: ");
        scanf("%i",&qnt);/// quantidade de valores inseridos
        int valr[qnt];/// vetor dos valores
        for(i=0;i<qnt;i++){/// for para inserir os valores
            printf("\nInforme o %i valor: ",i+1);
            scanf("%i",&valr[i]);
        }
        printf("\n A media dos valores digitados e %.2f",media(valr,qnt));/// printa a media feita na fun��o media
        return 0;
    }
