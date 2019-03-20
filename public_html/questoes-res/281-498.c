/*
Elabore uma função que tenha por finalidade inserir números em um vetor.
 A função deverá receber por parâmetro o vetor e o número a ser inserido
(e outros, a critério do aluno).
Então esta função deverá inserir o número informado na primeira posição do vetor,
deslocando todos os outros números uma posição adiante.
Caso o vetor esteja lotado, a função deverá retornar o número que foi deslocado
para fora do vetor, caso contrário deverá retornar 0.
Não poderão ser usadas variáveis globais. Esta estrutura é chamada de fila.
*/

#include<stdio.h>

int inserir(int v[], int p, int t, int n){
    int i, r=0;
    for (i=p ; i>0 ; i--){
        if (i < t)
            v[i] = v[i-1];
        else
            r = v[i-1];
    }
    v[0] = n;
    return r;
}

int main(){
    int t,n,p=0,i,j;
    printf("Tamanho do vetor: ");
    scanf("%i",&t);
    int vetor[t];
    for (i=0 ; i<10 ; i++){
        printf("Inserir valor: ");
        scanf("%i",&n);
        int r = inserir(vetor, p, t, n);
        if (p == t)
            printf("Vetor cheio. valor retornado: %i Vetor:",r);
        else{
            printf("Numero inserido. Vetor: ");
            p++;
        }
        for (j=0 ; j<p ; j++){
            printf("%i ",vetor[j]);
        }
        printf("\n");
    }
}
