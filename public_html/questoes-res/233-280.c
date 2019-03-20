/**Escreva um programa que sirva para mostrar quanto o usuário gastou de combustível
após um longo trecho de viagem. Peça para o usuário informar qual o consumo médio de
seu carro (em Km/l). Então pergunte para o usuário qual a distância de cada trecho
percorrido, bem como quanto custou o combustível usado para percorrer o respectivo trecho.
O programa deve parar de pedir novas informações quando o usuário digitar 0 para a distância
ou para o preço. Ao fim, mostre quanto o usuário gastou no total da viagem.
Exemplo:
Comsumo do automóvel: 11 km/l
Trecho 1: 250 km; R$ 2,85
Trecho 2: 132 km; R$ 2,89
Trecho 3: 54 km; R$ 2,99
Trecho 4: 0  64,77+34,68+14,67
Resposta: O usuário gastou 114,13 R$ **/
#include<stdio.h>

main(){
    float preco,consumo,km,gasto=0;
    int i=1;
    printf("Informe o consumo medio de seu carro: \n");
    scanf("%f",&consumo);
    while(km!=0 && preco!=0){
        printf("Qual a distancia a ser percorrida no trecho %i: \n",i);
        scanf("%f",&km);
        printf("Informe o preco do combustivel: \n");
        scanf("%f",&preco);
        i++;
        if(i==1){
            gasto=gasto+(km/consumo)*preco;
        }
        else{
            gasto=gasto+(km/consumo)*preco;
        }
    }
    printf("O usuario gastou R$%.2f",gasto);
}
