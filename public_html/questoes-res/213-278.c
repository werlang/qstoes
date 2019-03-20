/**Escreva um programa que peça para o usuário inserir caracteres.
Quando o usuário informar o mesmo caractere quatro vezes consecutivas,
mostre na tela a quantidade de vogais que foram digitadas e feche o programa.
Cuide para que os quatro caracteres repetidos não entrem na contagem das vogais.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    char letra,prim;
    int consecutiv=0,i=1;
    int contvogal=0,con=0;
    while(consecutiv!=3){
        letra=getche();
        if(i==1){
            prim=letra;
        }
        if(i!=1){
            if(letra=='a' || letra=='A' || letra=='e' || letra=='E' || letra=='i' || letra=='I' || letra=='o' || letra=='O' || letra=='u' || letra=='U'){
                if(prim==letra){
                    con--;
                    prim=letra;
                }
            }
            if(prim==letra){
                consecutiv++;
                prim=letra;
            }
            else{
                prim=letra;
                consecutiv=0;
            }
        }
        if(letra=='a' || letra=='A' || letra=='e' || letra=='E' || letra=='i' || letra=='I' || letra=='o' || letra=='O' || letra=='u' || letra=='U'){
            contvogal++;
        }
        i++;
    }
    if(con==-3)
        printf("\n%i sao o numero de vogais",contvogal+con-1);
    else
        printf("\n%i sao o numero de vogais",contvogal);
}
