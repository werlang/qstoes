/*Escreva um programa que pe�a para o usu�rio digitar um palavra e
 ent�o mostre se essa palavra � v�lida (composta somente por letras mai�sculas
  e min�sculas).
Ent�o mostre na tela o n�mero de caracteres que n�o s�o v�lidos.*/
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
