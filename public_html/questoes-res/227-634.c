/**Escreva um programa que peça para o usuário informar um número N. Após peça para ele digitar N números e mostre quais destes são primos.**/
#include<stdio.h>
main(){
    int nN,aux=0,j,cont=0,i,n;
    printf("Quantos numeros deseja informar?\n");
    scanf("%i",&nN);
    for(i=1; i<=nN; i++){
        printf("Digite o %iº Numero:\n",i);
        scanf("%i",&n);
        cont=0;
            for(j=1; j<=i; j++){
                if(n%j==0 && n%2!=0){
                    cont++;
                }
            }
                if(cont==2){
                    printf("%i-PRIMO\n\n",n);
                }
    }
}

