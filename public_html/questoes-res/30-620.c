#include<stdio.h>
#include<stdlib.h>
    main (){
        srand (time(NULL));
        int n , i;
        for (i=0 ; i<100 ; i++){
        n = rand () %(100-10+1)+10;


        printf("%i ",n);

        }
    }
