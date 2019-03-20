/*
Elabore uma fun��o que tenha por finalidade inserir n�meros em um vetor.
 A fun��o dever� receber por par�metro o vetor e o n�mero a ser inserido
(e outros, a crit�rio do aluno).
Ent�o esta fun��o dever� inserir o n�mero informado na primeira posi��o do vetor,
deslocando todos os outros n�meros uma posi��o adiante.
Caso o vetor esteja lotado, a fun��o dever� retornar o n�mero que foi deslocado
para fora do vetor, caso contr�rio dever� retornar 0.
N�o poder�o ser usadas vari�veis globais. Esta estrutura � chamada de fila.
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
