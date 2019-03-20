#include<stdio.h>
#include<stdlib.h>
main(){
int num,cont[4],i,contmaior[4];
float med,e=0;
printf("\ndigite 5 numeros abixo:");
for(i=0;i<5;i++){
printf("\ndigite um numero:");
scanf("%d",&num);
cont[i]=num;
e +=num;
}
med = e/5;
for(i=0;i<5;i++){
if(cont[i]>med){
printf("\no numero: %d e maior que a media:",cont[i]);
printf("\n");
return(0);
}


}

}
