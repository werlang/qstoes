/**Escreva um programa que pe�a para o usu�rio informar um n�mero N. Ap�s pe�a para ele digitar N n�meros e mostre quais destes s�o primos.**/
#include<stdio.h>
main(){
    int nN,aux=0,j,cont=0,i,n;
    printf("Quantos numeros deseja informar?\n");
    scanf("%i",&nN);
    for(i=1; i<=nN; i++){
        printf("Digite o %i� Numero:\n",i);
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

