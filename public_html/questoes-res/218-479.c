/**Dado um n�mero N como entrada,
escreva um programa que mostre na tela os N primeiros
n�meros da sequ�ncia de Fibonacci.**/
#include<stdio.h>

main(){
  /// Declara��o de vari�veis.
  int a, b, resultado, i, n;
  a = 0;
  b = 1;
  printf("Digite um numero: ");
  scanf("%i", &n);
  printf("Serie de Fibonacci:\n");
  printf("%i\n", b);
  /// Com a estrutura de controle for() gero a sequ�ncia.
  for(i = 0; i < n; i++){
    resultado = a + b;
    a = b;
    b = resultado;
    printf("%i\n", resultado);
  }
}
