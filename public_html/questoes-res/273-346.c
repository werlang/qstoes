/**Escreva uma fun��o que receba dois n�meros como par�metros e retorna o MMC (m�nimo m�ltiplo comum) destes dois n�meros.**/
#include<stdio.h>

int mmc(int n1, int n2){/// aqui a fun��o recebe dois parametros n1 e n2
    int i;
    for(i=1;i<(n1*n2);i++){/// aqui ela faz as contas necessarias para calcular o mmc
        if(i%n1==0 && i%n2==0){
            return i;/// a primeira vez q ele entrar ja retorna a fun��o com o resultado
        }
    }
}
int main(){
    int n1,n2;
    scanf("%i",&n1);/// insere o primeiro valor
    scanf("%i",&n2);/// insere o segundo valor
    printf(" %i e o mmc de %i e %i",mmc(n1,n2),n1,n2);/// printa o mmc e os valores digitados
}
