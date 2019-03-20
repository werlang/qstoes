#include<stdio.h>
#include<string.h>

main(){
    char p[10][100];
    int i;
    for (i=0 ; i<10 ; i++){
        printf("Informe uma string (%i/10): ",i+1);
        gets(p[i]);
    }
    int troca;
    char aux[100];
    do{
        troca = 0;
        for (i=0 ; i<9 ; i++){
            if (strlen(p[i]) > strlen(p[i+1])){
                strcpy(aux,p[i]);
                strcpy(p[i],p[i+1]);
                strcpy(p[i+1],aux);
                troca = 1;
            }
        }
    }while(troca!=0);
    printf("\nStrings ordenadas:\n");
    for (i=0 ; i<10 ; i++){
        printf("%s\n",p[i]);
    }

}
