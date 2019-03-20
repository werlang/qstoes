#include<stdio.h>

main(){
    float n1a1, n2a1, n1a2, n2a2;
    printf("Aluno 1:\n");
    printf("Informe a primeira nota: ");
    scanf("%f",&n1a1);
    printf("Informe a segunda nota: ");
    scanf("%f",&n2a1);

    printf("Aluno 2:\n");
    printf("Informe a primeira nota: ");
    scanf("%f",&n1a2);
    printf("Informe a segunda nota: ");
    scanf("%f",&n2a2);


    float media1, media2;
    media1 = (n1a1+n2a1)/2;
    media2 = (n1a2+n2a2)/2;

    if (media1 > media2){
        printf("Aluno 1 tirou %.1f e obteve a maior media",media1);
    }
    else{
        printf("Aluno 2 tirou %.1f e obteve a maior media",media2);
    }
}
