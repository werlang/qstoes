#include<stdio.h>
#include<string.h>

char toupper(char c){
    if (c >= 'a' && c <= 'z')
        return c-32;
    else
        return c;
}
char tolower(char c){
    if (c >= 'A' && c <= 'Z')
        return c+32;
    else
        return c;
}

int main(){
    char frase[100];
    printf("Informe uma frase:\n");
    gets(frase);

    int i;
    frase[0] = toupper(frase[0]);
    for (i=1 ; i<strlen(frase);i++){
        if (frase[i-1] == ' ')
            frase[i] = toupper(frase[i]);
        else
            frase[i] = tolower(frase[i]);
    }

    printf("\nFrase formatada:\n%s\n",frase);
    return 0;
}
