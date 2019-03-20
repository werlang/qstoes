#include<stdio.h>

main(){
    int d, m, a;
    printf("Informe um numero correspondente ao dia do mes: \n");
    scanf("%i",&d);
    printf("Informe um numero correspondente ao mes do ano: \n");
    scanf("%i",&m);
    printf("Informe um numero correspondente ao ano: \n");
    scanf("%i",&a);
        switch (m){
            case 1:
                printf("Charqueadas, %i de janeiro de %i",d,a);
                break;
            case 2:
                printf("Charqueadas, %i de fevereiro de %i",d,a);
                break;
            case 3:
                printf("Charqueadas, %i de marco de %i",d,a);
                break;
            case 4:
                printf("Charqueadas, %i de abril de %i",d,a);
                break;
            case 5:
                printf("Charqueadas, %i de maio de %i",d,a);
                break;
            case 6:
                printf("Charqueadas, %i de junho de %i",d,a);
                break;
            case 7:
                printf("Charqueadas, %i de julho de %i",d,a);
                break;
            case 8:
                printf("Charqueadas, %i de agosto de %i",d,a);
                break;
            case 9:
                printf("Charqueadas, %i de setembro de %i",d,a);
                break;
            case 10:
                printf("Charqueadas, %i de outubro de %i",d,a);
                break;
            case 11:
                printf("Charqueadas, %i de novembro de %i",d,a);
                break;
            case 12:
                printf("Charqueadas, %i de dezembro de %i",d,a);
                break;
            default:
                printf(" Mes invalido");
        }
}
