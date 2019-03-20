/**Escrever uma função que receba dois números e retorne o maior deles.**/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
/// essas bibliotecas ( conio.h , locale.h e stdlib.h ) é para o printf aceitar acentos e simbolos
int retorn_maior(int vet[]){/// função que serve para retornar o maior entre eles
    int maior=0,i;
    for(i=0;i<2;i++){
        if(vet[i]>maior)/// faz a comparação para ver qual é o maior
            maior=vet[i];/// guarda o maior
    }
    return maior;/// retorna para o main com o maior de todos
}
int main(){
    setlocale(LC_ALL,"portuguese");/// somente para aceitar caracteres com acento ou simbolos
    int vet[2],i;
    for(i=0;i<2;i++){
        printf("Informe o %i° numero: ",i+1);
        scanf("%i",&vet[i]);/// vetor vai ate duas posições vet[0] e vet[1]
    }
    printf("\n %i e o maior dos dois",retorn_maior(vet));/// printa o resultado que retorna da função retorn_maior
    return 0;
}
