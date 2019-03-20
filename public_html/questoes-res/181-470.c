#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct disciplinas{
    char nome[20];
    int n_aval;
    float peso_aval[10];
};

struct alunos{
    char nome[20];
    int disciplina;
    float nota[10];
};

main(){
    struct disciplinas disc[30];
    struct alunos aluno[30];
    int op, d=0, a=0, i, j;
    char bAluno[20];
    float soma=0, media;

    while(op!=4){
        printf("Escolha uma opção do menu:\n1 = cadastrar disciplina\n2 = cadastrar aluno\n3 = Consultar aluno\n4 = Sair\n");
        scanf("%i",&op);
        fflush(stdin);

        switch(op){
        case 1:
            printf("Nome da disciplina: ");
            gets(disc[d].nome);
            fflush(stdin);

            printf("Numero de avaliacoes: ");
            scanf("%i", &disc[d].n_aval);
            fflush(stdin);

            for(i=0;i<disc[d].n_aval;i++){
                printf("Peso avaliacao %i: ",i+1);
                scanf("%f",&disc[d].peso_aval[i]);
                fflush(stdin);
            }

            printf("#### Disciplina cadastrada ####\n");
            d++;
            break;

        case 2:
            printf("Nome do aluno: ");
            gets(aluno[a].nome);
            fflush(stdin);

            printf("Disciplina: ");
            scanf("%i",&aluno[a].disciplina);
            fflush(stdin);
            printf("%s\n",disc[aluno[a].disciplina].nome);

            for(i=0;i<disc[aluno[a].disciplina].n_aval;i++){
                printf("Avaliacao %i: ",i+1);
                scanf("%f",&aluno[a].nota[i]);
                fflush(stdin);
            }

            printf("#### Aluno cadastrado ####\n");
            a++;
            break;

        case 3:
            printf("Digite o nome do aluno que deseja consultar: ");
            gets(bAluno);
            fflush(stdin);

            for(i=0;i<a;i++){
                if(strcmp(bAluno,aluno[i].nome)==0){
                    printf("\nDisciplina: %s",disc[aluno[i].disciplina].nome);
                    for(j=0;j<disc[aluno[a].disciplina].n_aval;j++){
                        printf("\nAvaliacao %i: %.1f",i+1,aluno[i].nota[j]);
                        soma+=aluno[i].nota[j] * disc[aluno[i].disciplina].peso_aval[j];
                    }
                    media=soma/10;
                }
            }
            if(soma==0){
                printf("\nAluno não encontrado\n");
            }else{
                printf("\nNota Final: %.1f\n",media);
                soma=0;
            }
            break;

        case 4:
            printf("\nPrograma finalizado!");
            break;

        default:
            break;
        }
    }
}
