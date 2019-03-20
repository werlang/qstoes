#include<stdio.h>

main(){
    int a,b,c,d,e;
    printf("ALUNO 1: ");
    scanf("%d",&a);
    printf("ALUNO 2: ");
    scanf("%d",&b);
    printf("ALUNO 3: ");
    scanf("%d",&c);
    printf("ALUNO 4: ");
    scanf("%d",&d);
    printf("ALUNO 5: ");
    scanf("%d",&e);
    float soma,media;
    soma=a+b+c+d+e;
    media=soma/5;
    printf("%.1f",media);
    }
