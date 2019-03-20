#include<stdio.h>
main(){
float r,v,i;
char letra;///a=resistencia em evidencia,b=tensao em evidencia,c=corrente em evidencia
printf("escolha qual grandeza ira ficar em evidencia e informe as outras duas:\n a-fica em evidencia a resistencia\n b-fica em evidencia a tensao\n c-fica em evidencia a corrente\n");
scanf("%c",&letra);
    switch(letra){
    case 'a':
        printf("informe o valor da tensao:\n");
        scanf("%f",&v);
        printf("informe o valor da corrente:\n");
        scanf("%f",&i);
        r=v/i;
        printf("O valor da resistencia e %.1f",r);
        break;
    case 'b':
        printf("informe o valor da resistencia:\n");
        scanf("%f",&r);
        printf("informe o valor da corrente:\n");
        scanf("%f",&i);
        v=r*i;
        printf("O valor da tensao e %.1f",v);
        break;
    case 'c':
    printf("informe o valor da tensao:\n");
    scanf("%f",&v);
    printf("informe o valor da resistencia:\n");
    scanf("%f",&r);
    i=v/r;
    printf("O valor da corrente e %.1f",i);
    default:
        printf("opcao invalida");
}
}
