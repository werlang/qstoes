#include<stdio.h>

main(){
    int idade;
    float salario;
    char resp;
    int idademaior, idademenor, idaderica;
    int cont=0;
    float salariovelho, salarionovo, maiorsalario;

    while(resp != 'n'){
        printf("Informe o salario: ");
        scanf("%f",&salario);
        printf("Informe a idade: ");
        scanf("%i",&idade);
        cont++;

        if (idade > idademaior || cont==1){
            idademaior = idade;
            salariovelho = salario;
        }
        if (idade < idademenor || cont==1){
            idademenor = idade;
            salarionovo = salario;
        }
        if (salario > maiorsalario || cont==1){
            idaderica = idade;
            maiorsalario = salario;
        }

        printf("Deseja informar outra? (s/n): ");
        resp = getche();
        printf("\n");
    }

    printf("Salario da mais idosa: R$%.2f\n",salariovelho);
    printf("Salario da mais jovem: R$%.2f\n",salarionovo);
    printf("Idade da pessoa mais rica: %i",idaderica);

}
