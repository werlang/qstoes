/**Elabore um programa que sorteie e mostre na tela 1000 caracteres de 'a' até 'z'. (ASCII a=97, z=122). Após, mostre na tela
 quantas vogais foram geradas, e qual foi a vogal mais comum desta sequência.**/
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 main(){
    srand(time(NULL));
    int contvogais=0,min,max,j,n,contA=0,contE=0,contI=0,contO=0,contU=0;
    char opcao,a,e,i,o,u;

    min='a';
    max='z';
    for(j=0; j<25; j++){
        n=rand()%(min-max+1)+min;
        printf(" %c\n",n);
        if(n=='a'){
            contvogais++;
            contA++;
            a=n;

        }
        if(n=='e'){
            contvogais++;
            contE++;
            e=n;
        }
        if(n=='i'){
            contvogais++;
            contI++;
            i=n;
        }
        if(n=='o'){
            contvogais++;
            contO++;
            o=n;
        }
        if(n=='u'){
            contvogais++;
            contU++;
            u=n;
        }
    }
    printf("Foram geradas %i vogais\n",contvogais);

    if(contA>contE && contA>contI && contA>contO && contA>contU){
        printf("A vogal mais comum desta sequencia eh a vogal [%c]-repetida por 3 %i vezes\n",a,contA);
    }

    else if(contE>contA && contE>contI && contE>contO && contE>contU){
        printf("A vogal mais comum desta sequencia eh a vogal [%c]-repetida por %i vezes\n",e,contE);
    }

    else if(contI>contA && contI>contE && contI>contO && contI>contU){
        printf("A vogal mais comum desta sequencia eh a vogal [%c]-repetida por %i vezes\n",i,contI);
    }

    else if(contO>contA && contO>contE && contO>contI && contO>contU){
        printf("A vogal mais comum desta sequencia eh a vogal [%c]-repetida por %i vezes\n",o,contO);
    }

    else if(contU>contA && contU>contE && contU>contI && contU>contO){
        printf("A vogal mais comum desta sequencia eh a vogal [%c]-repetida por %i vezes\n",u,contU);
    }
 }
