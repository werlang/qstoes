/**Escreva um programa que pe�a 15 n�meros e ent�o
 mostre quantos s�o pares e quantos s�o �mpares.**/
 #include<stdio.h>
 main(){
    int i, n, impar=0, par=0;
    for(i=1;i<=15;i++){
        printf("Informe o valor %i: ",i);
        scanf("%i",&n);
        if(n%2==0){
            par++;
        }
        else{
            impar++;
        }
    }
    printf("Dos numeros digitados %i sao par(es)\n %i sao impar(es)",par,impar);
 }
