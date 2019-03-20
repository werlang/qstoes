/**Crie uma função que receba por parâmetro o nome de uma pessoa cadastrada e a data atual, e
retorne a idade dessa pessoa. Caso a pessoa não esteja cadastrada, retorne 0.**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
    int dia,mes,ano;
};
/*************************************************************************************************************/
struct pessoa{
    char nome[50];
    int idade;
    struct data d_atl;
};
/*************************************************************************************************************/
struct pessoa p[50];
/*************************************************************************************************************/
int cadastro(char n[],int d,int m,int a,int t){
    int i,id=0;
    for(i=0;i<t;i++){
        if(strcmp(n,p[i].nome)==0){
            if( (d == p[i].d_atl.dia) && (m == p[i].d_atl.mes) && (a == p[i].d_atl.ano) )
               return p[i].idade;
        }
    }
    return 0;

}
/*************************************************************************************************************/
int main(){
    int i=0;char op;
    do{
       printf("Cadastro %i pessoa:\nNome:",i+1);
       gets(p[i].nome);
       printf("\nidade:");
       scanf("%i",&p[i].idade);
       printf("\nData Atual:");
       scanf("%i %i %i", &p[i].d_atl.dia, &p[i].d_atl.mes, &p[i].d_atl.ano);
       printf("\nDeseja cadastrar outra pessoa:(s)(n)\n");
       scanf(" %c",&op);
       printf("\n\n");
       i++;
       fflush(stdin);
       system("cls");
    }while(i<50 && op!='n');
/*************************************************************************************************************/
    struct pessoa n;
    printf("\nInforme um nome de busca:");
    gets(n.nome);
    printf("Informe uma data:");
    scanf("%i %i %i", &n.d_atl.dia, &n.d_atl.mes, &n.d_atl.ano);
/*************************************************************************************************************/
    int id=cadastro(n.nome,n.d_atl.dia,n.d_atl.mes, n.d_atl.ano,i);
    if(id == 0)
        printf("Pessoa nao cadastrada!!");
    else
        printf("\n idade %i",id);
/*************************************************************************************************************/
    return 0;
}
