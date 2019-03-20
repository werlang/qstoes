#include<stdio.h>

main(){
    int port,mat,hist,bio;
    printf("Quantas questoes acertou de portugues? ");
    scanf("%i",&port);
    printf("Quantas questoes acertou de matematica? ");
    scanf("%i",&mat);
    printf("Quantas questoes acertou de historia? ");
    scanf("%i",&hist);
    printf("Quantas questoes acertou de biologia? ");
    scanf("%i",&bio);

    int red;
    printf("Informe a nota da redacao: ");
    scanf("%i",&red);

    int pesored,pesoport,pesomat,pesobio,pesohist;
    printf("Quantos pontos vale a redacao? ");
    scanf("%i",&pesored);
    printf("Quantos pontos vale cada questao de portugues? ");
    scanf("%i",&pesoport);
    printf("Quantos pontos vale cada questao de matematica? ");
    scanf("%i",&pesomat);
    printf("Quantos pontos vale cada questao de historia? ");
    scanf("%i",&pesohist);
    printf("Quantos pontos vale cada questao de biologia? ");
    scanf("%i",&pesobio);

    if (port == 0 || mat == 0 || hist == 0 || bio == 0)
        printf("Desclassificado");
    else{
        if (red/pesored*100 < 50)
            printf("Desclassificado");
        else{
            int notaport = port*pesoport;
            int notamat = mat*pesomat;
            int notahist = hist*pesohist;
            int notabio = bio*pesobio;
            int notafinal = notaport+notamat+notahist+notabio+red;
            printf("Nota final: %i",notafinal);
        }
    }
}
