#include <stdio.h>;
#include <stdlib.h>;

int C,x;
float r;
 calcula(){
    printf("Selecione a converção:\n - F(fahrenheit)(1);\n - K(kelvin)(2);\n");
    scanf("%i",&x);
    switch(x){
        case 1:
            r = 9/5*(C+32);
            printf("O resultado e: %f F.\n",r);
        break;
        case 2:
            r = C+273;
            printf("O resultado e: %f K.\n",r);
        break;
        default:
            x = 0;
            system("cls");
            printf("Voce escolheu uma opcao invalida.\n");
            calcula();
        break;
    }
}
main(){
    printf("Digite um valor em graus C(celcios).\n");
    scanf("%i",&C);
    calcula();
    system("pause");
}
