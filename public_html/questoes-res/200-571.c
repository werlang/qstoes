#include<stdio.h>
#include<locale.h>

main(){
setlocale(LC_ALL, "portuguese");

int l1, l2, l3;
printf("Informe o Lado 1: ");
scanf("%i", &l1);

printf("Informe o Lado 2: ");
scanf("%i",&l2);

printf("Informe o Lado 3: ");
scanf("%i", &l3);

if ( l1 ==0 || l2 == 0 || l3 ==0){
    printf("Valores informados não podem formar um triângulo");

}else{
if ((l1+l2>l3) ||(l1+l3>l2)|| (l3+l2>l1)){
    printf("As medidas informadas formam um triângulo! \n");
}
if (l1 == l2 && l2 == l3){
    printf("Equilatero \n");
}
if (( l1 == l2) && (l1 != l3) || (l1==l3 && l1!= l2)){

    printf("Isósceles \n");

} else{
if (l1 != l2 && l2 != l3){
    printf("Escaleno\n");
}
}
}
}





