/**Escreva um programa que pe�a para o usu�rio inserir diferentes valores para
seus gastos de um m�s. Quando o usu�rio digitar 0 para um gasto, pe�a para ele
come�ar a digitar os gastos do pr�ximo m�s da mesma maneira. Fa�a isso at� que
os gastos de todos os 12 meses seja computado. Ao fim, mostre qual o n�mero do
m�s que teve o maior gasto, bem como de quanto foi esse gasto.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    float gasto,maior=0;
    int i=1,x=0;
    do{
        printf("Agora informe do mes %i: ",i);
        scanf("%f",&gasto);
        if(i==1){
            x=i;
            maior=gasto;
        }
        else{
            if(maior<gasto){
                x=i;
                maior=gasto;
            }
        }
        i++;
    }while(gasto>=0 && i!=13);
    printf("O mes %i teve o maior gasto de R$%.2f",x,maior);
}
