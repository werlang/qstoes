#include<stdio.h>

main(){
    char l;
    int vogais=0;
    while(l!=13){
        l = getch();
        if ( (l>='a' && l<='z') || (l>='A' && l<='Z') || (l>='0' && l<='9'))
            printf("%c",l);
        if (l=='a' || l=='e' || l=='i' || l=='o' || l=='u' || l=='A' || l=='E' || l=='I' || l=='O' || l=='U')
            vogais++;
    }
    printf("\n%i caracteres informados sao vogais",vogais);
}
