#include<stdio.h>
#include<string.h>

char antigo[100], rico[100];

void calcula(){
    int i;
    char nome[100];
    int idade, maioridade;
    float salario, maiorsalario;
    for (i=0 ; i<2 ; i++){
        printf("Informe o nome do funcionario: ");
        fflush(stdin);
        gets(nome);
        printf("Informe a idade do funcionario: ");
        scanf("%i",&idade);
        printf("Informe o salario do funcionario: ");
        scanf("%f",&salario);
        if (i==0 || idade > maioridade){
            maioridade = idade;
            strcpy(antigo, nome);
        }
        if (i==0 || salario > maiorsalario){
            maiorsalario = salario;
            strcpy(rico, nome);
        }
    }
}

int main(){
    calcula();
    printf("Nome da pessoa com maior idade: %s\n",antigo);
    printf("Nome da pessoa com maior salario: %s\n",rico);
    return 0;
}
