#include<stdio.h>

/*Pe�a para o usu�rio informar 10 caracteres. Ent�o mostrar quantos deles s�o vogais.*/

main(){
    int i, vogal=0;
    char letra;

    for(i=0; i<10; i++){
        printf("Informe uma letra: ");
        scanf(" %c",&letra);

        if((letra=='a'||letra=='A')||(letra=='e'||letra=='E')||(letra=='i'||letra=='I')||(letra=='o'||letra=='O')||(letra=='u'||letra=='U')){
           vogal++;

        }
    }
    printf("Dos carateres informados %i sao vogais.",vogal);
}
