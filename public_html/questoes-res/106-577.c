#include<stdio.h>

main () {

    float cons,dist,combs,preco;

    printf("qual o consumo do seu altomovel Km/l: ");
    scanf("%f",&cons);
      printf("qual a distancia em Km: ");
    scanf("%f",&dist);
     printf("qual o valor do combustivel: ");
    scanf("%f",&combs);

    preco=((cons/dist)*combs);

    printf("voce ira gastar :%.2f",preco);


      }
