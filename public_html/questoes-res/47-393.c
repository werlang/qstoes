#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
    srand(time(NULL));
    char l,ant;
    int a=0, e=0, i=0, o=0, u=0, aeb=0;

    while(a<100 || e<100 || i<100 || o<100 || u<100){
        ant = l;
        l = rand()%26+97;
        if (ant=='a' && l=='b')
            aeb++;
        if (l=='a')
            a++;
        if (l=='e')
            e++;
        if (l=='i')
            i++;
        if (l=='o')
            o++;
        if (l=='u')
            u++;

        printf("%c ",l);

    }
    printf("\n\na e b foram gerados consecutivamente %i vezes",aeb);
}
