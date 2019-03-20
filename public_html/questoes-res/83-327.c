/**Escreva uma função que receba por parâmetro um vetor e
o número de elementos deste vetor, e retorne a média destes números.**/
#include<stdio.h>
#include<stdlib.h>
    int i;
    float media(int vet[],int qnt){/// função media( int vet[] recebe copia dos valores do vetor valr do main, int qnt recebe copia do valor qnt do main
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
        printf("\n A media dos valores digitados e %.2f",media(valr,qnt));/// printa a media feita na função media
        return 0;
    }
