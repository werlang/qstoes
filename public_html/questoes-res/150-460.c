#include <stdio.h>

main(){
    char opcao;
    printf("Escolha uma opcao:\na - Informar saldo\nb - Fazer emprestimo\nc - Quitar divida\n");
    scanf("%c",&opcao);
    if (opcao == 'a'){
        float valor;
        printf("Informe um valor: ");
        scanf("%f",&valor);
        printf("Saldo atualizado com sucesso.\n");
    }
    else if (opcao == 'b'){
        float emprestimo;
        int parcelas;
        printf("Informe o valor do emprestimo desejado: ");
        scanf("%f",&emprestimo);
        printf("Em quantas parcelas deseja pagar? ");
        scanf("%i",&parcelas);
        float juros = emprestimo * 5/100;
        float total = emprestimo + juros;
        float vparc = total/parcelas;
        printf("Valor de cada parcela: R$ %.2f\n",vparc);
    }
    else if (opcao == 'c'){
        float divida;
        int dias;
        printf("Informe o valor da divida: ");
        scanf("%f",&divida);
        printf("Quantos dias voce atrasou o pagamento? ");
        scanf("%i",&dias);
        float juros = (divida * 10/100) + (divida * dias/100);
        float total = divida + juros;
        printf("Voce deve pagar R$ %.2f para quitar a divida\n",total);
    }
}
