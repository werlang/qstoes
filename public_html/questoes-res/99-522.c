/**Escreva uma função que receba um número a ser inserido, o tamanho de um conjunto de números e
um ponteiro para esse conjunto. A função deve retornar 0 caso o conjunto não esteja ordenado.
Caso contrário, insira o número informado por parâmetro no conjunto, de maneira que o mesmo
continue ordenado. Caso a operação seja feita com sucesso, retorne 1. Como o conjunto de números estará cheio,
seu tamanho deverá se expandir a cada número inserido (Dica: utilize um ponteiro de ponteiro).**/

#include<stdio.h>
#include<stdlib.h>
int increment (int n,int *t, int **p){
    int i,cont=0;
    for(i=0;i<(*t)-1;i++){
        if( *(*p+i) > *(*p+i+1) )
            return 0;
    }
    (*t)++;
    *p=(int*)realloc(*p,sizeof(int)*(*t));
    for(i=(*t-2);i>=0;i--){
                        ///Porque a ultima posição do novo vetor tera lixo de memoria e a penultima posição sera a ultima do vetor antigo
        if(*(*p+i)<=n){/// se o penultimo valor do vetor for menor que o numero a ser a crescentado entra aqui
            *(*p+i+1)=n;/// a ultima posição sera do numero a ser acrescentado
            break;/// finaliza a operação
        }

        else/// caso contrario
            *(*p+i+1)=*(*p+i);/// ele ira alocar as posição nos devidos lugares
    }
    for(i=0;i<*t;i++){/// esse for vai varrer o vetor para ver se nao alocou numeros repetidos
        if(*(*p+i)==*(*p+i+1)){/// se ouver uma posiçaõ igual a outra
            *(*p+i)=n;/// ele substitui por n
            break;/// finaliza a repetição
        }
    }
    return 1;
}
int main(){
    int n,t,i,res;
        printf("Informe um numero:");
        scanf("%i",&n);
        printf("Informe o tamanho do vetor:");
        scanf("%i",&t);
        int *vet=(int*)malloc(sizeof(int)*t);
        for(i=0;i<t;i++){
            printf("Informe o valor %i: ",i+1);
            scanf("%i",&*(vet+i));
        }
        res=increment(n,&t,&vet);
        printf("\nReturn %i\nO vetor ficou assim:\n",res);
        for(i=0;i<t;i++)
            printf(" %i",*(vet+i));
        return 0;
}
