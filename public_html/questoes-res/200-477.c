#include<stdio.h>

main(){
    int l1, l2, l3, soma=0, cont=0;
    printf("Informe a primeira medida: \n");
    scanf("%i",&l1);
    printf("Informe a segunda medida: \n");
    scanf("%i",&l2);
    printf("Informe a terceira medida: \n");
    scanf("%i",&l3);
    ///lados iguais a zero
 if(l1==0 && l2==0 && l3==0 || l1==0 || l2==0 || l3==0){
    printf("invalido\n");
 }
 ///lados com medidas q formam um triangulo
 else if((l1+l2>l3) || (l1+l3>l2) || (l2+l3>l1)){
    printf("Suas medidas formam um triangulo\n");
}
///triangulo equilatero todos os lados iguais maiores q zero
if(l1==l2 && l1==l3 && l1>0&&l2>0&&l3>0){
    printf("Seu triangulo e equilatero");
}
///triangulo isosceles pelo menos dois lados iguais e maiores q zero
else if((l1==l2&&l1>0&&l2>0)||(l1==l3 && l1>0&&l3>0)|| (l2==l3 && l2>0&&l3>0)){
    printf("Seu triangulo e isosceles");
}
///triangulo escaleno todos os lados sao destintos e maiores q zero
else if(l1!=l2&&l1!=l3&&l2!=l3 && l1>0 && l2>0 && l3>0){
    printf("Seu triangulo e escaleno");
}
///quando nao forma triangulo
else{
    printf("Nao formou um triangulo");
}
}
