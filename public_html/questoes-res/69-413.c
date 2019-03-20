#include<stdio.h>
#include<conio.h>
#include<string.h>

main(){
	char frase[100],rep[50];
	int contrep=0,i,j,tam,igual=0,jatem=0;
	
	printf("Digite uma frase: ");
	gets(frase);
	tam=strlen(frase);
	
	for (i=0 ; i<tam ; i++){
		igual=0;
		if (frase[i]!=' '){
			for (j=i+1 ; j<tam ; j++){
				if (frase[i]==frase[j])
					igual++;
			}
			if (igual!=0){
				jatem=0;
				for (j=0 ; j<contrep ; j++){
					if (rep[j]==frase[i]){
						jatem++;
					}
				}
				if (jatem==0){
					rep[contrep]=frase[i];
					contrep++;
				}
			}
		}
	}
	printf("%i",contrep);
	
	
}
