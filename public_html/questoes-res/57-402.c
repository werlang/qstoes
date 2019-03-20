#include<stdio.h>
#include<conio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");
    char fr1[50], fr2[50]; //duas frases
    char l; //caractere que guarda a ultima letra digitada
    int t1=0,t2=0; //tamanhos das duas frases

    /*
    começa a pedir caracteres até que digite enter ou ultrapasse o tamanho 50
    daí vai jogando os caracteres dentro do vetor, e incrementando o tamanho
    */
    printf("Informe a primeira frase:\n");
    do{
        l = getche();
        fr1[t1] = l;
        t1++;
    }while (l!=13 && t1<50);

    //mesma coisa
    printf("\n\nInforme a segunda frase:\n");
    do{
        l = getche();
        fr2[t2] = l;
        t2++;
    }while(l!=13 && t2<50);

    char rep[50]; //vetor das repetidas
    /*
    tr = tamanho das repetidas
    i,j = indice dos vetores fr1 e fr2 que irão ser varridos
    k = indice do vetor rep a ser varrido
    */
    int tr=0, i, j, k;
    int jatem; //serve para guardar se uma latra já consta (1) ou não (0) dentro do vetor rep
    for (i=0 ; i<t1 ; i++){ //varre fr1
        for (j=0 ; j<t2 ; j++){ //para cada letra de fr1, varre todas de fr2
            /*
            se a letra analisada por fr1 for igual a letra analisada por fr2
            e o caractere analisado não for nem o espaço nem o enter...
            daí tem que varrer o vetor das repetidas verificando se essa letre já tinha sido inserida antes ou não.
            */
            if (fr1[i] == fr2[j] && fr1[i] != ' ' && fr1[i] != 13){
                jatem = 0; //zera o jatem para indicar que estamos começando uma nova varredura do vetor das repetidas
                for (k=0 ; k<tr ; k++){ //varre o vetor das repetidas,
                    if (rep[k] == fr1[i])//se essa letra já tinha sido contabilizada como repetida
                        jatem = 1; //já que a letra já está dentro do vetor
                }
                /*
                este esquema do jatem precisa ser feito, pois só sabemos se uma letra está presente ou não no vetor
                depois de varrer sua última posição. daí então verificamos o conteudo de jatem, e se for zero,
                é porque não entrou no if ali de cima nenhuma vez, logo, não está presente no vetor ainda.
                */
                if (jatem == 0){ //se não encontrou...
                    rep[tr] = fr1[i]; //insere a letra no vetor
                    tr++;//e incrementa o tamanho
                }
            }
        }
    }

    printf("\n\nEstão presentes em ambas as frases os seguintes caracteres:\n");
    for (i=0 ; i<tr ; i++) //varre o vetor das repetidas, mostrando todas as letras.
        printf("%c ",rep[i]);

    getch();
}
