#include<stdio.h>     //Bibliotecas de funções de entrada e saida
#include<locale.h>   //Biblioteca para ter os acentos no executavel
#include<stdlib.h>   //Biblioteca para funções de repetição
#include<math.h>     // Biblioteca para calculos matematicos



 int main()  //Função principal
 {

//------------------------------------------------------------------------------//
setlocale(LC_ALL,"portuguese");
//------------------------------------------------------------------------------//
// Faça um programa que calcule a área de um triângulo retângulo e a sua hipotenusa tendo como informação o
//comprimento dos catetos deste triângulo, que devem ser informados pelo usuário //

float CatOp,CatAdj,Hipo,Area; // Declaração das variaveis

printf("Digite o valor do cateto oposto: \n");
scanf("%f",&CatOp);

printf("Digite o valor do cateto adjascente:\n");
scanf("%f",&CatAdj);

Hipo=sqrt((CatAdj*CatAdj)+(CatOp*CatOp));

Area=(CatAdj*CatOp)/2;

printf("A hipotenusa é:%f e a Area é: %f\n",Hipo,Area);

system("pause");
}
