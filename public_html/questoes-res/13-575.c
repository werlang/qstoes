#include<stdio.h>
 main(){
      int a, b, adi, sub, mult;
    float div;

      printf("Informe o valor de A: ");
      scanf("%i",&a);
      printf("Informe o valor de B: ");
      scanf("%i",&b);

      adi = a+b;
      printf("%i + %i = %i\n", a, b, adi);

      sub = a-b;
      printf("%i - %i = %i\n", a, b, sub);

      mult = a*b;
      printf("%i * %i = %i\n", a, b, mult);

      div = (float)a/b;
      printf("%i / %i = %f\n", a, b, div);
 }
