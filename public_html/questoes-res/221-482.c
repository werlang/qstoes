/**Escreva um programa que pe�a para o usu�rio informar um n�mero.
A seguir, pe�a para ele informar mais 10 n�meros.
Ent�o compare cada um dos 10 n�meros ao primeiro digitado,
e dos que forem distintos, mostre qual o mais pr�ximo.**/
#include<stdio.h>

main(){
    int numero, i, n10, maiordosmenor=0, menordosmaior=0, pmai=0, pmen=0;
    printf("Informe um numero qualquer: \n");
    scanf("%i",&numero);
    for(i=1;i<=10;i++){
        printf(" Informe mais um valor: ");
        scanf("%i",&n10);
        if(n10>numero){
            if(pmen==0){
                menordosmaior=n10;
                pmen=1;
            }
            else if(n10<menordosmaior){
            menordosmaior=n10;
            }
        }
        if(n10<numero){
            if(pmai==0){
                maiordosmenor=n10;
                pmai=1;
            }
            else if(n10>maiordosmenor){
                maiordosmenor=n10;
            }
        }
    }
    printf("esse e o mais proximo dos maiores %i \n esse e o mais proximo dos menores  %i ",menordosmaior, maiordosmenor);
}
