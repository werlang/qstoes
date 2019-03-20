/**Escreva um programa que peça para o usuário inserir a idade e salário de diversas pessoas.
A cada nova pessoa inserida, o programa deve perguntar se deseja inserir
uma outra pessoa (reposta 's' ou 'n').Quando o usuário não quiser mais inserir pessoas,
o programa deverá mostrar o salário da pessoa mais idosa e da mais jovem,
bem como quantos anos possui a pessoa com o maior salário.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    char opcao;
    int idade,idoso=0,id=0;
    int jovem;
    float salario,valor;
    float maior_salar=0,saljov=0;
    while(opcao!='n'){
        system("cls");
        printf("\nInforme a idade do individuo: \n");
        scanf("%i",&idade);
        printf("Informe o salario do individuo: \n");
        scanf("%f",&salario);
        printf("\nVoce deseja inserir outra pessoa:\n s-Sim\n n-Nao\n");
        opcao=getche();
        if(idade>idoso){
            idoso=idade;
            valor=salario;
        }
        if(salario>maior_salar){
            maior_salar=salario;
            id=idade;
        }
        if(idade<jovem){
            jovem=idade;
            saljov=salario;
        }
    }
    printf("\n%i anos e o mais idoso o salario e R$%.2f\n",idoso,valor);
    printf("\n%i anos e o mais jovem o salario e R$%.2f\n",jovem,saljov);
    printf("\nA idade %i anos recebe o maior salario deR$%.2f\n",id,maior_salar);
}
