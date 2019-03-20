#include<stdio.h>


main() {
    int i,num,impar=0,par=0;
    for(i=0;i<=5;i++){
        printf("Informe o valor de %i:",i+1);
        scanf("%i",&num);
        if(num%2==0){
            par++;
        }
        else{
            impar++;
        }
    }
    printf(" Par: %i",par);
    printf(" Impar: %i\n",impar);





}
