/**Escreva uma fun��o que receba um n�mero a ser inserido, o tamanho de um conjunto de n�meros e
um ponteiro para esse conjunto. A fun��o deve retornar 0 caso o conjunto n�o esteja ordenado.
Caso contr�rio, insira o n�mero informado por par�metro no conjunto, de maneira que o mesmo
continue ordenado. Caso a opera��o seja feita com sucesso, retorne 1. Como o conjunto de n�meros estar� cheio,
seu tamanho dever� se expandir a cada n�mero inserido (Dica: utilize um ponteiro de ponteiro).**/

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
                        ///Porque a ultima posi��o do novo vetor tera lixo de memoria e a penultima posi��o sera a ultima do vetor antigo
        if(*(*p+i)<=n){/// se o penultimo valor do vetor for menor que o numero a ser a crescentado entra aqui
            *(*p+i+1)=n;/// a ultima posi��o sera do numero a ser acrescentado
            break;/// finaliza a opera��o
        }

        else/// caso contrario
            *(*p+i+1)=*(*p+i);/// ele ira alocar as posi��o nos devidos lugares
    }
    for(i=0;i<*t;i++){/// esse for vai varrer o vetor para ver se nao alocou numeros repetidos
        if(*(*p+i)==*(*p+i+1)){/// se ouver uma posi�a� igual a outra
            *(*p+i)=n;/// ele substitui por n
            break;/// finaliza a repeti��o
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
