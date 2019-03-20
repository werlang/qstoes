#include <stdio.h>
main(){

float vigas, vigamenor;
int i;
for(i=0; i<10; i++){
    printf("informe o valor das vigas %i: ",i+1);
    scanf ("%f",&vigas);
    while (vigas<0){
        printf ("valor invalido. Informe novamente: ");
        scanf ("%f",&vigas);
    }
    if (vigas==0){
        break;
        }

    if (vigas<vigamenor || i==0){
        vigamenor=vigas;
        }

}

printf ("a menor viga mede %.1f: ",vigamenor);




}
