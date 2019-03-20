/**Elabore um programa que pergunte quantas avaliações foram realizadas com uma turma,
e o número de alunos desta turma. Então calcule e mostre a média das notas da turma.**/
#include<stdio.h>

main(){
    int i, q, avaliacao, alunos, nota, soma=0, contador=0;
    float media=0;
    printf("Informe quantas avaliacoes foi realizadas: \n");
    scanf("%i",&avaliacao);
    printf("Informe quantos alunos tem na turma: \n");
    scanf("%i",&alunos);
    q=alunos*avaliacao;
    for(i=1;i<=q;i++){
        printf(" nota avalicao: \n");
        scanf("%i",&nota);
        if(nota>=0){
            soma=soma+nota;
            contador++;
        }
    media=(float)soma/contador;
    }
    printf(" A media da turma e %.1f",media);
}
