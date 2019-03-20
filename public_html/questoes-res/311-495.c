/**Escreva um programa que peça para o usuário informar um número N,
então peça para ele informar outros N números. Mostre na tela qual o
maior ímpar digitado, bem como o menor par.**/
#include<stdio.h>

main(){
    int i, n, q, pp=0, pi=0, maior=0, menor=0;///pp=primeiro par e pi primeiro impar
    printf("Informe quantos numeros quer usar: \n");
    scanf("%i",&q);
    for(i=1;i<=q;i++){
        printf("Informe o valor %i: \n",i);
        scanf("%i",&n);
        if(n%2==0){
            if(pp==0){
                menor=n;
                pp=2;
            }
            else{
                if(n<menor){
                    menor=n;
                }
            }
        }
        else{
            if(n%2!=0){
                if(pi==0){
                    maior=n;
                    pi=2;
                }
                else{
                    if(n>maior){
                    maior=n;
                    }
                }
            }
        }
    }
    printf("numero menor par: %i\n",menor);
    printf("numero maior impar: %i\n",maior);
}
