#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main(){
	srand(time(NULL));
	int n,i;
	for(i=0;i<25;i++){
		n=rand()%91+10;
		printf("%i  ",n);
	}
}
