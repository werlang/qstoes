/**Escreva um programa que peça para o usuário inserir três números.
 No fim, escreva qual foi o maior e qual foi o menor.**/
 #include<stdio.h>
main(){
int n1,n2,n3;
    printf("digite o primeiro numero:\n");
    scanf("%i",&n1);
        printf("digite o segundo numero:\n");
        scanf("%i",&n2);
            printf("digite o terceiro numero:\n");
            scanf("%i",&n3);
///testando os maiores
if(n1>n2&&n1>n3){
    printf("o maior numero e %i\n",n1);
}
if(n2>n1&&n2>n3){
    printf("o maior numero e %i\n",n2);
}
if(n3>n1&&n3>n2){
    printf("o maior numero e %i\n",n3);
}
///testando os menores
if(n1<n2&&n1<n3){
    printf("o menor numero e %i\n",n1);
}
if(n2<n1&&n2<n3){
    printf("o menor numero e %i\n",n2);
}
if(n3<n1&&n3<n2){
    printf("o menor numero e %i\n",n3);
}
}
