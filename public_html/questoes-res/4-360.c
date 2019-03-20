#include<stdio.h>

main(){
    float n1,n2,n3;
    printf("Informe a primeira nota: ");
    scanf("%f",&n1);
    printf("Informe a segunda nota: ");
    scanf("%f",&n2);
    printf("Informe a terceira nota: ");
    scanf("%f",&n3);

    float media;
    media = (n1+n2+n3)/3;

    printf("Media: %.2f\n",media);

    if (media<6){
        printf("Reprovado.");
        float rec;
        printf("Informe quanto tirou na recuperacao: ");
        scanf("%f",&rec);
        if (rec>=6){
            printf("Aprovado. Media final: %.2f",rec);
        }
        else{
            if (rec >= media){
                printf("Reprovado. Media final: %.2f",rec);
            }
            else{
                printf("Reprovado. Media final: %.2f",media);
            }
        }
    }
    else{
        printf("Aprovado. Media final: %.2f",media);
    }
}
