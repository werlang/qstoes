#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*

*/
int ordem(int **vet,int *t,int num){
int i,j,cont=0;
    for(i=0;i<(*t);i++){
        if(*(*vet+i)==num){
            for(j=i;j<(*t-1);j++){
                *(*vet+j)=*(*vet+(j+1));
            }(*t)--;*vet=(int*)realloc(*vet,sizeof(int)*(*t));cont=1;
        }
    }

    return cont;
}
int main(){
int resp,i,t,num;
printf("Informe o tamanho do vetor:");
scanf("%i",&t);
int *vet=(int*)malloc(sizeof(int)*t);
for(i=0;i<t;i++){
    printf("Informe o %i numero:",i+1);
    scanf("%i",&vet[i]);
}
printf("Informe o numero a ser procurado no vetor:");
scanf("%i",&num);
resp=ordem(&vet,&t,num);
printf("O retorno eh: %i\n",resp);
for(i=0;i<t;i++){
    printf("%i ",*(vet+i));
    }
return 0;
}
