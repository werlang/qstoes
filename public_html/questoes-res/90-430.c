#include<stdio.h>
#include<string.h>

main(){
    char frase[1000], aux[1000], busca[100], subst[100];
    char *p, *q;
    printf("Informe uma frase: ");
    gets(frase);
    printf("Informe a string de busca: ");
    gets(busca);
    printf("Informe a string para substituir: ");
    gets(subst);
    strcpy(aux, frase);
    p = strstr(frase, busca);
    q = strstr(aux, busca);
    while(p!= NULL){
        strcpy(p, subst);
        p += strlen(subst);
        q += strlen(busca);
        strcpy(p, q);
        p = strstr(p, busca);
        q = strstr(q, busca);
    }
    printf("String final:\n%s\n",frase);
}
