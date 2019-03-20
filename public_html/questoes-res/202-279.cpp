#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	int i=0,letra=0,contA=0,contE=0,contI=0,contO=0,contU=0,contResto=0;
	
	srand(time(NULL));
	
	for(i=1;i<=1000;i++){
	
	
	letra=rand()%26+97;
	
	printf("\n %i-%c ",i,letra);
	
	if(letra=='a'){
		contA+=1;
	}else if(letra=='e'){
		contE+=1;
	}else if(letra=='i'){
		contI+=1;
	}else if(letra=='o'){
		contO+=1;
	}else if(letra=='u'){
		contU+=1;
	}else{
		contResto+=1;
	}
  }
  printf("\nTotal Vogal a: %i",contA);
  printf("\nTotal Vogal e: %i",contE);
  printf("\nTotal Vogal i: %i",contI);
  printf("\nTotal Vogal o: %i",contO);
  printf("\nTotal Vogal u: %i",contU);
  printf("\nTotal Resto  : %i",contResto);
  printf("\nFor: %i",i);
  
  system("pause");
}

