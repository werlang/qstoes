#include<stdio.h>
#include<string.h>

struct terreno {
    char proprietario[100];
    float valor;
    float comp, larg;
};

void cadastra(struct terreno lote[], int t){
    int i;
    for (i=0 ; i<t ; i++){
        printf("Nome do proprietario: ");
        fflush(stdin);
        gets(lote[i].proprietario);
        printf("Comprimento do terreno: ");
        scanf("%f",&lote[i].comp);
        printf("Largura do terreno: ");
        scanf("%f",&lote[i].larg);
        printf("Valor do terreno: ");
        scanf("%f",&lote[i].valor);
    }

}

int custo_beneficio(struct terreno lote[], int t){
    float area, vmq, menorvmq;
    int i, menori;
    for (i=0 ; i<t ; i++){
        area = lote[i].comp * lote[i].larg;
        vmq = lote[i].valor / area;
        if (i==0 || vmq < menorvmq){
            menorvmq = vmq;
            menori = i;
        }
    }
    return menori;
}

main(){
    int t;
    printf("Quantos terrenos possui este lote? ");
    scanf("%i", &t);
    struct terreno lote[t];
    cadastra(lote, t);
    int i = custo_beneficio(lote, t);
    printf("Terreno com melhor custo-beneficio:\n");
    printf("Proprietario: %s\n",lote[i].proprietario);
    printf("Dimensoes: %.1fx%.1f\n",lote[i].comp, lote[i].larg);
    printf("Valor: R$ %.2f\n",lote[i].valor);

}




