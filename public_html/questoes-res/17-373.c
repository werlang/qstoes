/**Escreva um programa que pe�a para o usu�rio informar 10 n�meros.
 Mostrar ent�o na tela o maior e o menor valor.**/
 #include<stdio.h>

 main(){
    int i, n, maior=0, menor=0;
    for(i=1;i<=10;i++){
        printf("Informe o valor %i: ",i);
        scanf("%i",&n);
        if(i==1){
            maior=n;
            menor=n;
        }
        else if(n>maior)
            maior=n;
        else if(n<menor)
            menor=n;
    }
    printf("numero maior: %i\n",maior);
    printf("numero menor: %i",menor);
 }
