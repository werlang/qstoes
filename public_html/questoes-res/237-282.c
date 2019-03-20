/**Elabore um programa que realize um levantamento do grau de escolaridade de pessoas.
O programa deve pedir para o usuário informar com que idade uma pessoa concluiu o ensino
fundamental, médio e superior. A idade 0 deverá ser informada caso alguma destas etapas
não tenha ainda sido concluída pela pessoa sendo cadastrada. Caso uma etapa não tenha sido
concluída, o programa não deverá perguntar sobre as próximas. Entre o cadastro de cada pessoa,
o usuário deverá ser perguntado se deseja cadastrar uma próxima pessoa. Ao fim, para cada grau
de escolaridade, mostre qual a média de idade das pessoas que concluíram esta determinada etapa.**/
#include<stdio.h>

main(){
    int idade,idade2,idade3;
    int fund=0,med=0,sup=0;
    int somfu=0,somed=0,somsup=0;
    char opcao;
    while(opcao!='n'){
        do{
           printf("Informe a idade que voce concluiu o ensino fundamental: \n");
           scanf("%i",&idade);
           if(idade>0){
                fund++;
                somfu=somfu+idade;
           }
           if(idade!=0){
                printf("Informe a idade que voce concluiu o ensino medio: \n");
                scanf("%i",&idade);
                if(idade>0){
                    med++;
                    somed=somed+idade;
                }
                if(idade!=0){
                    printf("Informe a idade que voce concluiu o ensino superior: \n");
                    scanf("%i",&idade);
                    if(idade>0){
                        sup++;
                        somsup=somsup+idade;
                    }
                    printf("\nDigite (s)se deseja cadastrar outra pesso e (n) se nao deseja\n");
                    opcao=getche();
                }
           }
        }while(idade!=0 && opcao!='n');
        printf("\nDigite (s)se deseja cadastrar outra pesso e (n) se nao deseja\n");
        opcao=getche();
    }
    int media1=somfu/fund;
    int media2=somed/med;
    int media3=somsup/sup;
    if(opcao=='n'){
        if(media1>0){
            printf(" \n A media das pessoas que concluiram o ensino fundamental foi de %i\n",media1);
        }
        if(media2>0){
            printf("A media das pessoas que concluiram o ensino medio foi de %i\n",media2);
        }
        if(media3>0){
            printf("A media das pessoas que concluiram o ensino superior foi de %i",media3);
        }
    }
}
