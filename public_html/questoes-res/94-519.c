#include<stdio.h>

void ordena(int *v, int tam){
	int i, temp, trocou=0;
	//variavel trocou é incrementada cada vez que detectar que há um número fora de ordem
	//o programa repete o ato de varrer o vetor enquanto houver alguma troca. quando tiver varrido o vetor todo e nao houver trocas, quer dizer q ele ta ordenado
	do{
		trocou=0; //logo antes de começar a varredura, zera as trocas
		for (i=1 ; i<tam ; i++){ //começa o i=1 porque ele analisa o vet[i] com vet[i-1], entao incialmente compara posição 1 com a 0
			if (*(v+i) < *(v+i-1)){ //compara conteudo apontado pelos ponteiros. *(v+i) é o conteudo de vet[i], pois v aponta para o vet do main. caso numero que tem dentro da posição i seja menor que o numero da posição anterior entra no if, pois tem que trocar
				temp = *(v+i); //troca os dois numeros do vetor com ajuda do temp
				*(v+i) = *(v+i-1);
				*(v+i-1) = temp;
				trocou++; //e incrementa o contador, indicando que gouve uma troca
			}
		}
	}while(trocou!=0);
}

void insere_vet(int *vet, int *t, int n){
    int i, posi;
    for (i=0 ; i<*t ; i++){
        if (*(vet+i) > n){
            posi = i;
            break;
        }
    }
    if (i == *t)
        posi = i;
      
    for(i=*t ; i>posi ; i--){
        *(vet+i) = *(vet+i-1);
    }
    *(vet+i) = n;
    (*t)++;
}

int remove_vet(int *vet, int *t, int n){
    int i,j;
    for (i=0 ; i<*t ; i++){
        if (*(vet+i) == n){
            for (j=i ; j<*t-1 ; j++){
                *(vet+j) = *(vet+j+1);
            }
            (*t)--;
            return 1;
        }
        else if (*(vet+i) > n)
            return 0;
    }
}

int main(){
    int t,i;
    scanf("%i",&t);
    int vet[10000];
    for (i=0 ; i<t ; i++){
        scanf("%i",&vet[i]);
    }
    ordena(vet,t);
    
    int ni, nr;
    scanf("%i %i",&ni, &nr);
    
    insere_vet(vet,&t,ni);
    int r = remove_vet(vet,&t,nr);
    
    for (i=0 ; i<t ; i++){
        printf("%i ",vet[i]);
    }
    printf("\nR: %i",r);
    return 0;
}