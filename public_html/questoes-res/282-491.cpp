#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Crie uma fun��o que receba por refer�ncia um vetor de origem e um de destino.
A fun��o dever� pegar o �ltimo elemento do vetor de origem,
remov�-lo e ent�o colocar este elemento na primeira posi��o vazia do vetor de destino.
Considere que as posi��es vazias do vetor est�o preenchidas com 0.
*/
troca(int vet_origem[],int *t_origem,int vet_destino[],int *t_destino){
	int i;
	*t_origem-=1;//decrementa o inice do vetor origem para acessar o ultimo indice do vetor e assim pegar o valor
	for(i=0;i<*t_destino;i++){
        printf("%i\n",i);
		if(vet_destino[i]==0){
			vet_destino[i]=vet_origem[*(t_origem)];//realiza a troca dos valores
			break;//finaliza o for
		}
	}
    vet_origem=(int*)realloc(vet_origem,sizeof(int)*(*t_origem));//realoca o tamanho do vetor origem

}
int main(){

	int td=0,to=0,i;
	printf("informe o Tamanho do vetor de Origem:");
	scanf("%i",&to);
	printf("Informe o tamanho do vetor de Destino:");
	scanf("%i",&td);

	int*vet_origem=(int*)malloc(sizeof(int)*to);//aloca dinamicamente o vetor origem

	printf("Informe os valores asseguir do vetor Origem:");
	for(i=0;i<to;i++){
		printf("\nInforme o %i valor",i+1);
		scanf("%i",&vet_origem[i]);
	}

	int*vet_destino=(int*)malloc(sizeof(int)*td);//aloca dinamicamente o vetor destino

	printf("\nInforme os valores asseguir do vetor Destino:\n para deixar um espa�o no vetor insira um 0 no indice desejado!");
	for(i=0;i<td;i++){
		printf("\nInforme o %i valor",i+1);
		scanf("%i",&vet_destino[i]);
	}

	troca(vet_origem,&to,vet_destino,&td);//chamada da fun��o

		for(i=0;i<td;i++){//impress�o do destino
			printf("%i ",*(vet_destino+i));
		}
		printf("\n");
		for(i=0;i<to;i++){//impress�o do origem
			printf("%i ",*(vet_origem+i));
		}
return 0;
}
