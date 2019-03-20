#include<stdio.h>

main()  {

    int n1,n2,n3;
    float recup;

    printf("informe a nota 1: ");
    scanf("%i",&n1);
    printf("informe a nota 2: ");
    scanf("%i",&n2);
    printf("informe a nota 3: ");
    scanf("%i",&n3);

    float media=(n1+n2+n3)/3;

    if(media>60){
        printf(" Aprovado com a nota:%.1f",media);
    }

    if(media<60){
        printf("informe a nota da recuperacao: ");
        scanf("%f",&recup);
        if(recup>60){
            printf("Aprovado com media: %.1f\n",recup);

        }
        else if(recup<60){
            printf("Reprovado com media: %.1f\n",recup);
        }

    }





}
