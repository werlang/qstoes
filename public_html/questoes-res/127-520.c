/**Escreva uma função que receba um conjunto de números, e o tamanho deste conjunto.
A função deverá ordenar estes números, excluindo todas ocorrências de valores repetidos,
e neste caso, modificar o tamanho deste conjunto. (utilize retorno de ponteiro)**/
#include<stdio.h>
#include<stdlib.h>
int repetido(int *p,int t){/// esta função serve para capturar numeros q repetem
    int rep,i,j;
    rep=0;/// toda vez q entrar na funcção zera a variavel rep = repetido
     for(i=0;i<t-1;i++){/// vai ate o fim do vetor, exemplo vetor de 10 posições vai de 0 a 9 com menos 1 vai de 0 a 8
        for(j=i+1;j<t;j++){/// vai ate o fim do vetor, exemplo um vetor de 10 posições vai de 0 a 9 entao ele vai de 0 a 9
            if(*(p+i)==*(p+j)){/// verifica uma posição com todas as outras assim por diante
                rep=*(p+j);/// salva o que repete
                break;/// para a repetição
            }
        }
    }
     return rep;/// retorna o numero repetido
}

int *exclui(int *p,int *t,int rep){/// função que remove os repetidos
    int i,j;              /// *p ponteiro que aponta para o vetor do main *t ponteiro que a aponta para o tamanho do vetor no main
    for(i=0;i<(*t);i++){
        if(*(p+i)==rep){/// se a posição que estiver for igual o numero que repetiu entra aqui para fazer o processo de excluir
            for(j=i;j<((*t)-1);j++){/// vai ate o fim do vetor, exemplo vetor de 10 posições vai de 0 a 9 com menos 1 vai de 0 a 8
                *(p+j)=*(p+j+1);///  aqui ele vai excluir o repetido
            }
            (*t)--;/// diminui o tamanho d vetor
            p=(int*)realloc(p,sizeof(int)*((*t)+1));/// realoca para o novo tamanho
            break;/// finaliza a repetição

        }
    }
    return p;/// envia a posição de memoria do novo vetor realocado para o main
}
void ordena(int *p,int t){/// ordena o vetor do menor para o maior
    int alt,aux,i,j;/// alt significa alteração, aux significa auxiliar
    do{
        alt=0;/// cada verificação ele zera o alt
        for(i=0;i<t;i++){
            for(j=i+1;j<t;j++){
                if(*(p+i)>*(p+j)){/// caso a posição atual ser maior que a proxima ele entra nesse if
                    aux=*(p+i);/// aqui ele começa as trocas com o aux
                    *(p+i)=*(p+j);
                    *(p+j)=aux;
                    alt=1;/// se ele alterar ele recebe 1
                    break;/// finaliza a repetição
                }
            }
        }
    }while(alt!=0);/// vai repetir ate q alt seja zero ou seja ate que não tenha mais alterações
}
int main(){
    int *vet=(int*)malloc(sizeof(int));/// faz a primeira alocação
    int t=0,n,i,rep;
    do{
        printf("Digite o %i valor, caso queira encerrar digite zero:",t+1);
        scanf("%i",&n);
        if(n!=0){/// so vai salvar o numero no vetor e realocar se o numero for diferente de zero
            *(vet+t)=n;
            t++;/// incrementa o t para aumentar o tamanho para realocar
            vet=(int*)realloc(vet,sizeof(int)*(t+1));
        }
    }while(n!=0);/// repete ate que o usuario digite zero
    printf("\nTamanho do vetor antigo: %i",t);
    do{
        rep=repetido(vet,t);/// envia posição de memoria do vet e tamanho do vetor do main para a função
        vet=exclui(vet,&t,rep);/// envia a posição de memoria do vet  do tamanho e envia o numero que repetiu
    }while(rep!=0);/// esse do{}while serve para eliminar todos os que repetirem
    ordena(vet,t);/// chama a função ordena que vai ordenar em ordem crescente o vetor
    printf("\nTamanho do vetor atual (%i)\n",t);
    for(i=0;i<t;i++){
        printf(" | %i",*(vet+i));/// mostra o vetor sem nenhum repetido
    }
    return 0;
}
