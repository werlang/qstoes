#include<stdio.h>
#include<stdlib.h>

main(){
	//Escreva um programa que peça para o usuário informar um frase em um vetor alocado dinamicamente, de um tamanho grande. 
	//Ao fim da execução do programa, a única memória alocada deve ser do tamanho exato da frase digitada pelo usuário. 
	//Realize esta função sem usar a função realloc.
	
	int tam=0,i;
	char *f, *temp, c;
	
	f=(char*)malloc(sizeof(char));
	printf("Frase: ");
	do{
		c=getche();
		if(c!=13){
			*(f+tam)=c;
			tam++;
			
			temp=(char*)malloc(sizeof(char)*tam+1);
			for(i=0;i<tam;i++){
				*(temp+i)=*(f+i);
			}
			
			free(f);
			f=(char*)malloc(sizeof(char)*tam+1);
			for(i=0;i<tam;i++){
				*(f+i)=*(temp+i);
			}
			
			free(temp);
		}
	}while(c!=13);
	
	for(i=0;i<tam;i++){
		printf("%c",*(f+i));
	}
	
}
