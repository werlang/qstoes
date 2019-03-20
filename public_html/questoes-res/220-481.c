#include<stdio.h>

main(){
    int i,j,k;
    for (k=1 ; k<=18 ; k++){
        for (i=1 ; i<=18 ; i++){
            for (j=1 ; j<=18 ; j++){
                if (i+j+k == 20)
                    printf("%i-%i-%i\n",k,i,j);
            }
        }
    }
}
