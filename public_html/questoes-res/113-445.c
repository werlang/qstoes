#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct pessoas{
    char nome[100];
    char genero;
    int idade;
};
struct pessoas *cadastro;

int carrega(){
    int tam=0;
    FILE *arq = fopen("dados","rb");
    if (arq==NULL){
        cadastro = (struct pessoas*)malloc(sizeof(struct pessoas)*(tam+1));
        return 0;
    }
    while(!feof(arq)){
        cadastro = (struct pessoas*)realloc(cadastro,sizeof(struct pessoas)*(tam+1));
        if (fread(cadastro+tam, sizeof(struct pessoas), 1, arq)){
            if (ferror(arq))
                return 0;
            tam++;
        }
    }
    fclose(arq);
    return tam;
}

void escreve(int t){
    FILE *arq = fopen("dados","wb");
    fwrite(cadastro,sizeof(struct pessoas),t,arq);
    fclose(arq);
}

int cadastra(int t){
    cadastro = (struct pessoas*)realloc(cadastro,sizeof(struct pessoas)*(t+1));
    printf("Informe o nome: ");
    gets(cadastro[t].nome);
    printf("Informe o genero: ");
    cadastro[t].genero = getche();
    printf("\nInforme a idade: ");
    scanf("%i",&cadastro[t].idade);
    fflush(stdin);
    printf("\nCadastro efetuado.");
    getch();
    return t+1;
}

void consulta(int t){
    printf("Informe um nome: ");
    char nome[100];
    gets(nome);
    int i;
    for (i=0 ; i<t ; i++){
        if (strcmp(cadastro[i].nome,nome)==0){
            printf("Nome: %s\nGenero: %c\nIdade: %i\n",cadastro[i].nome,cadastro[i].genero,cadastro[i].idade);
            break;
        }
    }
    if (i==t)
        printf("Pessoa nao encontrada");
    getch();
}

int deleta(int t){
    printf("Informe um nome: ");
    char nome[100];
    gets(nome);
    int i,j;
    for (i=0 ; i<t ; i++){
        if (strcmp(cadastro[i].nome,nome)==0){
            for(j=i ; j<t-1 ; j++)
                cadastro[j] = cadastro[j+1];
            break;
        }
    }
    if (i==t){
        printf("Pessoa nao encontrada");
        getch();
        return t;
    }
    cadastro = (struct pessoas*)realloc(cadastro,sizeof(struct pessoas)*t);
    return t-1;
}

void listar(int t){
    int i;
    for (i=0 ; i<t ; i++){
        printf("Nome: %s\nGenero: %c\nIdade: %i\n\n",cadastro[i].nome,cadastro[i].genero,cadastro[i].idade);
    }
    getch();
}

main(){
    int tamanho = carrega();
    //logica
    char op;
    while (op!='5'){
        system("cls");
        printf("Informe uma opcao:\n1 - Cadastrar\n2 - Consultar\n3 - Remover\n4 - Listar cadastrados\n5 - Sair");
        op = getch();
        printf("\n");
        switch(op){
        case '1':
            tamanho = cadastra(tamanho);
            break;
        case '2':
            consulta(tamanho);
            break;
        case '3':
            tamanho = deleta(tamanho);
            break;
        case '4':
            listar(tamanho);
            break;
        }
    }
    escreve(tamanho);
}
