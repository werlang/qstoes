#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

main(){
    setlocale(LC_ALL,"portuguese");

    srand(time(NULL));
    printf("Informe três números");
    int n1,n2,n3;
    int i;
    int maior,menor,meio;
    scanf("%i %i %i",&n1,&n2,&n3);

    if (n1 == n2 || n1 == n3 || n2 == n3)
        printf("Existem valores repetidos");
    else{

        //maior
        if (n1 > n2 && n1 > n3)
            maior = n1;
        if (n2 > n1 && n2 > n3)
            maior = n2;
        if (n3 > n2 && n3 > n1)
            maior = n3;

        //menor
        if (n1 < n2 && n1 < n3)
            menor = n1;
        if (n2 < n1 && n2 < n3)
            menor = n2;
        if (n3 < n2 && n3 < n1)
            menor = n3;

        //meio
        if (maior != n1 && menor != n1)
            meio = n1;
        if (maior != n2 && menor != n2)
            meio = n2;
        if (maior != n3 && menor != n3)
            meio = n3;


        printf("Maior: %i\nMeio: %i\nMenor: %i",menor, meio, maior);

        int n,cont=0;
        for (i=0 ; i<5000 ; i++){
            n = rand()%(maior-menor+1)+menor;
            if (n > meio)
                cont++;
        }
        printf("\nForam sorteados %i números maiores que o do meio informado",cont);

    }
}
