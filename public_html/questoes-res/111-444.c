#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pessoa{
    char nome[50];
    char nascimento[11];
    char endereco[100];
    char email[100];
};

int string_to_idade(char str[]){
    char sdia[3], smes[3], sano[5];
    strncpy(sdia, str, 2);
    sdia[2] = '\0';
    strncpy(smes, str+3, 2);
    smes[2] = '\0';
    strcpy(sano, str+6);
    int dia, mes, ano;
    dia = atoi(sdia);
    mes = atoi(smes);
    ano = atoi(sano);

    int anof = 2017 - ano;
    if (mes < 8)
        anof--;
    else if (mes == 8){
        if (dia <= 1)
            anof--;
    }
    return anof;
}

main(){
    struct pessoa cadastro[1000];
    char op;
    int t=0;
    do{
        system("cls");
        printf("1 - Cadastrar usuario\n2 - Procurar usuario\n3 - Sair do programa\nInforme uma opcao: ");
        op = getch();

        if (op == '1'){
            printf("\n\nInforme o nome: ");
            gets(cadastro[t].nome);
            printf("Data de nascimento (dd/mm/aaaa): ");
            gets(cadastro[t].nascimento);
            while(cadastro[t].nascimento[2] != '/' || cadastro[t].nascimento[5] != '/'){
                printf("Data invalida. Informe novamente: ");
                gets(cadastro[t].nascimento);
            }

            printf("Informe o endereco: ");
            gets(cadastro[t].endereco);
            printf("Informe o email: ");
            gets(cadastro[t].email);
            while (strstr(cadastro[t].email,"@")==NULL){
                printf("Email invalido. Informe novamente: ");
                gets(cadastro[t].email);
            }
            t++;
            printf("Pessoa cadastrada...\n");
            getch();
        }
        else if (op == '2'){
            printf("\n\nPelo que deseja buscar?\n1 - Nome\n2 - Idade\n3 - Email ");
            op = getch();
            char busca[100];
            if (op == '1'){
                printf("\n\nInforme o nome para busca: ");
                gets(busca);
                int i, cont=0;
                for (i=0 ; i<t ; i++){
                    if (strstr(cadastro[i].nome,busca) != NULL){
                        printf("Nome: %s\n",cadastro[i].nome);
                        printf("Data de nascimento: %s\n",cadastro[i].nascimento);
                        printf("Endereco: %s\n",cadastro[i].endereco);
                        printf("Email: %s\n\n",cadastro[i].email);
                        cont++;
                    }
                }
                if (cont==0)
                    printf("Nenhuma ocorrencia encontrada");
            }
            else if (op == '3'){
                printf("\n\nInforme o email para busca: ");
                gets(busca);
                int i, cont=0;
                for (i=0 ; i<t ; i++){
                    if (strcmp(cadastro[i].email,busca) == 0){
                        printf("Nome: %s\n",cadastro[i].nome);
                        printf("Data de nascimento: %s\n",cadastro[i].nascimento);
                        printf("Endereco: %s\n",cadastro[i].endereco);
                        printf("Email: %s\n\n",cadastro[i].email);
                        cont++;
                    }
                }
                if (cont==0)
                    printf("Nenhuma ocorrencia encontrada");
            }
            else if (op == '2'){
                int idade, cidade;
                printf("\n\nInforme uma idade: ");
                scanf("%i",&idade);
                fflush(stdin);
                printf("\n\nDeseja buscar:\n1 - Pelo menos a idade informada\n2 - Ate a idade informada\n3 - Exatamente a idade informada\n");
                op = getch();
                if (op == '1'){
                    int i, cont=0;
                    for (i=0 ; i<t ; i++){
                        cidade = string_to_idade(cadastro[i].nascimento);
                        if (cidade >= idade){
                            printf("Nome: %s\n",cadastro[i].nome);
                            printf("Data de nascimento: %s\n",cadastro[i].nascimento);
                            printf("Endereco: %s\n",cadastro[i].endereco);
                            printf("Email: %s\n\n",cadastro[i].email);
                            cont++;
                        }
                    }
                    if (cont==0)
                        printf("Nenhuma ocorrencia encontrada");
                }
                if (op == '2'){
                    int i, cont=0;
                    for (i=0 ; i<t ; i++){
                        cidade = string_to_idade(cadastro[i].nascimento);
                        if (cidade <= idade){
                            printf("Nome: %s\n",cadastro[i].nome);
                            printf("Data de nascimento: %s\n",cadastro[i].nascimento);
                            printf("Endereco: %s\n",cadastro[i].endereco);
                            printf("Email: %s\n\n",cadastro[i].email);
                            cont++;
                        }
                    }
                    if (cont==0)
                        printf("Nenhuma ocorrencia encontrada");
                }
                if (op == '3'){
                    int i, cont=0;
                    for (i=0 ; i<t ; i++){
                        cidade = string_to_idade(cadastro[i].nascimento);
                        if (cidade == idade){
                            printf("Nome: %s\n",cadastro[i].nome);
                            printf("Data de nascimento: %s\n",cadastro[i].nascimento);
                            printf("Endereco: %s\n",cadastro[i].endereco);
                            printf("Email: %s\n\n",cadastro[i].email);
                            cont++;
                        }
                    }
                    if (cont==0)
                        printf("Nenhuma ocorrencia encontrada");
                }
                getch();
                op = 9;
            }
        }
    }while(op != '3');
}
