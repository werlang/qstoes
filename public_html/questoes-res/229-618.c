#include<stdio.h>

main(){
    int d1,d2,d3;

    for (d1=1 ; d1<=6 ; d1++){
        for (d2=1 ; d2<=6 ; d2++){
            for (d3=1 ; d3<=6 ; d3++){
                printf("%i-%i-%i  ",d1,d2,d3);
            }
        }
    }
}
