#include<stdio.h>     //Bibliotecas de fun��es de entrada e saida
#include<locale.h>   //Biblioteca para ter os acentos no executavel
#include<stdlib.h>   //Biblioteca para fun��es de repeti��o
#include<math.h>     // Biblioteca para calculos matematicos



 int main()  //Fun��o principal
 {

//------------------------------------------------------------------------------//
setlocale(LC_ALL,"portuguese");
//------------------------------------------------------------------------------//
// Fa�a um programa que calcule a �rea de um tri�ngulo ret�ngulo e a sua hipotenusa tendo como informa��o o
//comprimento dos catetos deste tri�ngulo, que devem ser informados pelo usu�rio //

float CatOp,CatAdj,Hipo,Area; // Declara��o das variaveis

printf("Digite o valor do cateto oposto: \n");
scanf("%f",&CatOp);

printf("Digite o valor do cateto adjascente:\n");
scanf("%f",&CatAdj);

Hipo=sqrt((CatAdj*CatAdj)+(CatOp*CatOp));

Area=(CatAdj*CatOp)/2;

printf("A hipotenusa �:%f e a Area �: %f\n",Hipo,Area);

system("pause");
}
