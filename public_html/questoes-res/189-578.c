#include<stdio.h>

main() {
      float base,altura;

    printf("informe o valor do cateto altura: ");
    scanf("%f",&altura);
    printf("informe o valor do cateto base: ");
    scanf("%f",&base);

    float area=(altura*base)/2;
    float hipo=(sqrt(pow(altura,2)+pow(base,2)));


    printf(" A area do triagulo e:%.1f\n",area);
    printf(" A hipotenuza e: %.1f\n",base);





}
