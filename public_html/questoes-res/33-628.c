//Escreva um programa que peça para o usuário informar três números, então gere 5000
//números aleatórios entre o maior e o menor informado pelo usuário. Ao fim, mostre na tela quantos números são maiores que o número intermediário informado.


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    main(){

        int n1, n2, n3, maior, menor, meio, i, n, cont=0;
        printf("Informe um numero: ");
        scanf("%i",&n1);
        printf("Informe um numero: ");
        scanf("%i",&n2);
        printf("Informe um numero: ");
        scanf("%i",&n3);


        if (n1 > n2 && n1 > n3)
            maior = n1;
        if (n2 > n1 && n2 > n3)
            maior = n2;
        if (n3 > n2 && n3 > n1)
            maior = n3;


        if(n1 < n2 && n1 < n3)
            menor = n1;
        if(n2 < n1 && n2 < n3)
            menor = n2;
        if(n3 < n1 && n3 < n2)
            menor = n3;


        if(n1 != maior && n1 != menor)
            meio = n1;
        if(n2 != maior && n2 != menor)
            meio = n2;
        if(n3 != maior && n3 != menor)
            meio = n3;

        printf("Maior numero: %i\nMeio: %i\nMenor numero: %i ", maior, meio, menor);
         srand(time(NULL));
        for(i=0 ; i<5000 ; i++){
                //printf("%i",n);
                n = rand()%(maior-menor+1)+menor;
                if( n > meio)
                    cont++;
        }
        printf("\nMaiores que o intermediario: %i",cont);
    }



