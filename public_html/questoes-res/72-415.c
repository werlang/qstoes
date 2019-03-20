#include<stdio.h>
#include<string.h>

main(){
    char palavras[10][50];
    int i;
    for (i=0 ; i<10 ; i++){
        printf("Informe a palavra %i: ",i+1);
        gets(palavras[i]);
    }
    int rep, j, naorep=0;
    for (i=0 ; i<10 ; i++){
        rep=0;
        for (j=0 ; j<10 ; j++){
            if ( strcmp(palavras[i],palavras[j])==0)
                rep++;
        }
        if (rep==1)
            naorep++;
    }
    printf("\n%i palavras nao foram repetidas.",naorep);

}
