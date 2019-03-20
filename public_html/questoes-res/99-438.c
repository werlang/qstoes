#include<stdio.h>
#include<conio.h>
/*Escreva uma fun��o que receba um n�mero a ser inserido, o tamanho de um conjunto de n�meros e um ponteiro para esse conjunto.
A fun��o deve retornar 0 caso o conjunto n�o esteja ordenado.
Caso contr�rio, insira o n�mero informado por par�metro no conjunto, de maneira que o mesmo continue ordenado.
Caso a opera��o seja feita com sucesso, retorne 1.
Como o conjunto de n�meros estar� cheio, seu tamanho dever� se expandir a cada n�mero inserido (Dica: utilize um ponteiro de ponteiro).*/
int funcao(int num, int *tam, int **pt){
    //retornar 0 caso o conjunto n�o esteja ordenado.
    int k, kk;
    for(k=0 ; k < *tam-1 ; k++){
        if(*(*pt+k) > *(*pt+k+1)){
            return 0;
        }
    }
        //Caso contr�rio, insira o n�mero informado por par�metro no conjunto, de maneira que o mesmo continue ordenado. Caso a opera��o seja feita com sucesso, retorne 1.
        for(k=0 ; k < *tam ; k++){
            if(*(*pt+k) >= num){
                //*tam++ � BOMBOU

                *tam += 1;
                ////seu tamanho dever� se expandir a cada n�mero inserido
                *pt = (int*)realloc(*pt, sizeof(int)* *tam);
                //empurra array para frente, enquanto for maior...
                for(kk=*tam ; kk>k ; kk--){
                    *(*pt+kk) = *(*pt+kk-1);
                }
                //posi��o do ponteiro recebe numero
                *(*pt+k) = num;
                return 1;
            }
        }
}
void main(){
    int *vet = NULL;
    int tamanho=5;
    int k, meter, resp;
    printf("tamanho do array = ");
    scanf("%d", &tamanho);
    vet = (int*)malloc(sizeof(int)*tamanho);
    /*/
    *vet = 0;
    *(vet+1) = 1;
    *(vet+2) = 3;
    *(vet+3) = 5;
    *(vet+4) = 7;
    */
    for(k=0 ; k<tamanho ; k++){
        printf("\narray[%d]", k);
        scanf("%d", &*(vet+k));
    }
    printf("\ninserir no array = ");
    scanf("%d", &meter);
    resp = funcao(meter, &tamanho, &vet);
    printf("return = %d", resp);
    for(k=0 ; k<tamanho ; k++){
        printf("\n%d", vet[k]);
    }
    return 0;
}
