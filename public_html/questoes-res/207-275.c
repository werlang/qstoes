/*Escreva um programa que peça para o usuário digitar um palavra e
 então mostre se essa palavra é válida (composta somente por letras maiúsculas
  e minúsculas).
Então mostre na tela o número de caracteres que não são válidos.*/
main()
{
    char letra;
    int invalidos=0;
    do
    {
        letra=getche();
        if(letra != 13)
        {
            if(letra>'Z' || letra<'A')
            {
                if(letra>'z' || letra<'a')
                    invalidos++;
            }

        }
    }while(letra!=13);
    if(invalidos==0)
        printf("eh valida");
    else
        printf("%i caracteres invalidos",invalidos);
}
