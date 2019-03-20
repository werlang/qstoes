/**Escreva um programa que peça para o usuário informar números até que um
número repetido (que já tenha sido informado anteriormente) seja informado.
Quando isso acontecer, mostre na tela o mmc entre o maior e o menor valor.**/
#include<stdio.h>

main(){
    int num,i=0,cont=0,y,j;
    int rep=0,vet[500];
    int maior=0,menor=0;
    do{
        printf("Informe o valor %i: \n",i);
        scanf("%i",&num);
        vet[i]=num;
        if(i>0){
            for(y=0;y<i;y++){
                if(vet[y] == vet[i]){
                    rep++;
                }
                if(y==0){
                    maior=vet[y];
                    menor=vet[y];
                }
                else if(y!=0){
                    if(vet[y]>maior){
                        maior=vet[y];
                    }
                    if(vet[y]<menor){
                        menor=vet[y];
                    }
                }
            }
        }
        i++;
    }while(rep!=1);
    for(j=1;j<=maior*menor;j++){
        if(j%maior==0 && j%menor==0){
                break;
        }
    }
    printf("%i\n %i maior\n %i menor\n mmc=%i",rep,maior,menor,j);
}
