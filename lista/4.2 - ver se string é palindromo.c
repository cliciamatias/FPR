/*Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.*/
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
	
	//percorendo a string até a sua matade, pois é espelhado se da direita ou esquerda forem os mesmos caracteres
	for(i=0; i<tamanho/2; i++)
	{
		//verificando se a string é a mesma de trás para frente
		if(s[i] != s[tamanho-i-1]) 
		{
           	return 0; //retornando '0' pois se os caracteres não forem iguais não é um palindromo
        }
	}
	return 1; //retornando 1, pois se saiu do for é palindromo
}
