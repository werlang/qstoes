#include<stdio.h>

main(){
    int ent;
    printf("Informe o numero de entrevistados: ");
    scanf("%i",&ent);
    int idade;
    float salario;
    int i;
    int cont25=0, soma25=0;
    int cont26=0, soma26=0;
    int cont40=0, soma40=0;
    int desemp=0;
    for(i=1 ; i<=ent ; i++){
        printf("Informe sua idade: ");
        scanf("%i",&idade);
        printf("Informe o seu salario: ");
        scanf("%f",&salario);

        if (salario == 0)
            desemp++;
        else{
            if (idade <= 25){
                soma25+=salario; //soma = soma + salario
                cont25++;
            }
            if (idade >= 26 && idade <= 40){
                soma26+=salario; //soma = soma + salario
                cont26++;
            }
            if (idade > 40){
                soma40+=salario; //soma = soma + salario
                cont40++;
            }
        }
    }
    float media25,media26,media40;
    if (cont25>0){
        media25 = soma25/cont25;
        printf("Media salarial das pessoas de ate 25 anos: %.2f\n",media25);
    }
    if (cont26>0){
        media26 = soma26/cont26;
        printf("Media salarial das pessoas entre 26 e 40 anos: %.2f\n",media26);
    }
    if (cont40>0){
        media40 = soma40/cont40;
        printf("Media salarial das pessoas de mais de 40 anos: %.2f\n",media40);
    }

    float pdesemp = (float)desemp/ent*100;
    printf("%.2f%% das pessoas entrevistadas estao desempregadas\n",pdesemp);
}
