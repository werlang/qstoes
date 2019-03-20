#include <stdio.h>
main(){
int num,i,cont,j;
do{
    cont=0;
    printf ("informe um numero primo: ");
    scanf ("%i",&num);
    for (i=1; i<=num; i++ ){
      if (num%i==0)
        cont++;
      //printf ("numero primo");
        }
}while (cont!=2);
for  (i=1; i<=num; i++){
    for (j=1; j<=num; j++){
        if (i+j==num){
           printf ("as combinacoes sao: %i + %i\n",i,j);
        }
    }
}

}
