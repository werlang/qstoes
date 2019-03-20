/**Escreva um programa que peça para o usuário digitar caracteres até que o ENTER seja pressionado.
Mostrar na tela somente os caracteres que forem letras maiúsculas, minúsculas, números, ou espaço.**/
#include<stdio.h>
#include<stdlib.h>

main(){
    char letra;
    int cont=0,cont2=0,cont3=0,cont4=0;
    while(letra!=13){
        letra=getch();
        if(letra>='a' && letra<='z'){
            cont++;
            printf("%c",letra);
        }
        if(letra>='A' && letra<='Z'){
            cont2++;
            printf("%c",letra);
        }
        if(letra>='0' && letra<='9'){
            cont3++;
            printf("%c",letra);
        }
        if(letra==32){
            cont4++;
            printf("' '");
        }
    }
    printf("%i letra minuscula\n %i letra maiuscula\n %i numero de numero\n %i numero de espaco",cont,cont2,cont3,cont4);
}
