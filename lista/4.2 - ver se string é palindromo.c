/*Quest�o 02:
Dada uma string s, desenvolver uma fun��o
que determine se s � ou n�o um pal�ndromo.
Observa��o: uma string s ser� um pal�ndromo
quando seus caracteres formarem a mesma
sequ�ncia, independente se s � percorrida da
esquerda para direita ou vice-versa.*/
#include <stdio.h>
#include <string.h>
int palindromo(char s[]);
void main()
{
	char s[30] = "OSSO"; //EH palindromo
	int retorno = palindromo(s); //chamando a fun��o
	
	//verificando o retorno e exibindo o resultado
	if(retorno == 1)
	{
		printf("(%s) EH palindromo.", s);
		
	}
	else
	{
		printf("(%s) NAO eh palindromo.", s);
	}
}
int palindromo(char s[])
{
	int i;
	int tamanho = strlen(s);
	
	//percorrendo a string 's'
	for(i=0; s[i]; i++)
	{
		//verificando se o ultimo caracter � igual ao primeiro e assim por diante
		if(s[i] == s[tamanho-1])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}


/*
#include <stdio.h>
#include <string.h>
int palindromo(char s[]);
void main()
{
	char string[30];
	int retorno;
	
	printf("Digite uma string: ");
	fflush(stdin);
	gets(string);
	
	retorno = palindromo(string);	
	
	if(retorno == 1)
	{
		printf("\nEsta string eh palindromo.");
	}
	else
	{
		printf("\nEsta string NAO eh palindromo.");
	}
}
int palindromo(char s[])
{
	int i, tamanho=strlen(s);
	
	//percorendo a string at� a sua matade, pois � espelhado se da direita ou esquerda forem os mesmos caracteres
	for(i=0; i<tamanho/2; i++)
	{
		//verificando se a string � a mesma de tr�s para frente
		if(s[i] != s[tamanho-i-1]) 
		{
           	return 0; //retornando '0' pois se os caracteres n�o forem iguais n�o � um palindromo
        }
	}
	return 1; //retornando 1, pois se saiu do for � palindromo
}*/
