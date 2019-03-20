#include<stdio.h>
main(){
    char letra;
    int i, tamanho, maior, letraA, cont=0;
    for (i=0 ; i<5 ; i++){
        printf("Informe o nome da %ia pessoa: ",i+1);
        tamanho = 0;
        letraA = 0;
        do{
            letra = getche();
            tamanho++;
            if (letra == 'a' || letra == 'A')
                letraA++;
        }while (letra != 13);
        if (tamanho > maior || i==0)
            maior = tamanho;
        if (letraA == 0)
            cont++;

        printf("\n");
    }
    printf("\nO maior nome possui %i letras.",maior-1);
    printf("\n%i nomes nao possuem a letra A.\n",cont);
}
