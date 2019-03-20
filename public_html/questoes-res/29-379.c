#include<stdio.h>
#include<conio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");

    int i,j, nmultas;
    char letra, letramaior;
    float valor, valormaior, soma;

    for(i=1 ; i<=5 ; i++){
        printf("Informe a letra inicial do nome: ");
        scanf(" %c",&letra);

        printf("Informe o número de multas deste motorista: ");
        scanf("%i",&nmultas);

        soma = 0;
        for (j=1 ; j<=nmultas ; j++){
            printf("Informe o valor da multa %i do motorista %i: ",j,i);
            scanf("%f",&valor);
            soma += valor; //soma = soma + valor;
        }
        if (soma > valormaior || i==1){
            valormaior = soma;
            letramaior = letra;
        }
    }
    printf("A letra do nome do motorista que mais gastou: %c", letramaior);
}
