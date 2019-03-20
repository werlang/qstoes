/**Escreva uma função que receba dois números como parâmetros e retorna o MMC (mínimo múltiplo comum) destes dois números.**/
#include<stdio.h>

int mmc(int n1, int n2){/// aqui a função recebe dois parametros n1 e n2
    int i;
    for(i=1;i<(n1*n2);i++){/// aqui ela faz as contas necessarias para calcular o mmc
        if(i%n1==0 && i%n2==0){
            return i;/// a primeira vez q ele entrar ja retorna a função com o resultado
        }
    }
}
int main(){
    int n1,n2;
    scanf("%i",&n1);/// insere o primeiro valor
    scanf("%i",&n2);/// insere o segundo valor
    printf(" %i e o mmc de %i e %i",mmc(n1,n2),n1,n2);/// printa o mmc e os valores digitados
}
