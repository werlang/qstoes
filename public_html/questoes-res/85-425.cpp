#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h> 

char mai(char l)
{
	if(l>='a' && l<='z')
	{
		return l-32;
	}
	else
	{
		return l;
	}
}
char min(char l)
{
	if(l>='A' && l<='Z')
	{
		return l+32;
	}
	else
	{
		return l;
	}
}
main()
{
    char res,letra;
    printf("digite um caracter:\n");
    scanf("%c",&letra);
    if(letra>='a' && letra<='z')
	{
		res=mai(letra);
	}
	else
	{
		res=min(letra);
	}
    printf("%c",res);
	
}
