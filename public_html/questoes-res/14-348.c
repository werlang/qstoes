#include<stdio.h>
main(){
    int ano;
    printf("Ano de Nascimento: \n");
    scanf("%d",&ano);

    if(ano<1999){
        printf("Maior de Idade");
    }
    else{
        printf("Menor de Idade");
    }
}
