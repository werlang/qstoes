/**Escreva uma fun��o que recebe tr�s n�meros como par�metro.
Esta fun��o deve retornar a raz�o entre o somat�rio dos dois elementos que s�o numericamente mais pr�ximos e o outro elemento:
Ex: Os n�meros passados foram: 11,3,10. C�lculo: (11+10)/3=7.**/
#include<stdio.h>
float calcul (int vet[]){
    int i,maior,menor,meio;
    float c1,c2;
    for(i=0;i<3;i++){
        if(i==0 || vet[i]>maior)/// captura o maior dos tres
            maior=vet[i];
        if(i==0 || vet[i]<menor)/// captura o menor dos tres
            menor=vet[i];
    }
   for(i=0;i<3;i++){
        if(vet[i]!=maior && vet[i]!=menor)/// captura o do meio
            meio=vet[i];
    }
    c1=(float)maior-meio;/// faz a conta um
    c2=(float)meio-menor;/// faz a conta dois
    if(c1<c2){/// verifica qual � a menor e mostra
        printf("(%i+%i)/%i =",maior,meio,menor);/// aqui
        return (maior+meio)/menor;/// retorna o resultado da conta
    }                                           /// ou
    else{
        printf("(%i+%i)/%i =",meio,menor,maior);/// aqui
        return (meio+menor)/maior;/// retorna o resultado da conta
    }
}
int main(){
    int i, vet[3];
    for(i=0;i<3;i++)
        scanf("%i",&vet[i]);/// digita os tres numeros
    printf(" %.1f",calcul(vet));/// printa o retorno do parametro
    return 0;
}
