/*Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
#include <stdio.h>
#include <string.h>
void remover(char s[], char caracter);
void main()
{
	char s[30] = "algoritmo"; //algritm
	char caracter = 'o';
	
	printf("String original: %s.", s);
	//chamando a função
	remover(s,caracter);
	//exibindo o resultado
	printf("\nString sem '%c' : %s.", caracter, s);
}
void remover(char s[], char caracter)
{
	int i, j;
	//percorrendo a string 's'
	for(i=0; s[i]; i++)
	{
		//verificando se a string tem o caracter
		if(s[i] == caracter)
		{
			//percorrendo a string 
			for(j=i; s[j]; j++)
			{
				//andando com os caracteres substituindo o caracter pelo posterior
				s[j] = s[j+1];
			}
			//decrementando o 'i' para q todas as letras escolhidas sejam removidas
			i--;
		}
	}
}
/*
#include <stdio.h>
#include <string.h>
void removerCaracter(char s[], char c);
void main()
{
	char string[30], caracter;
	
	printf("\n\nDigite uma string: ");
	fflush(stdin);
	gets(string);

	//lendo caracter da string que será removido
	printf("\n\nDigite o caracter a ser removido: ");
	fflush(stdin);
	scanf("%c", &caracter);
	//chamando a função
	removerCaracter(string,caracter);
	printf("\n\nString com caracter removido: %s", string);
}
void removerCaracter(char s[], char c)
{
	int i, j;
	//percorrendo a string
	for(i=0; s[i]; i++)
	{
		//verificando se na string há o caracter a ser removido
		if(s[i] == c)
		{
			//se encontrar o caracter, entra no for e percorre ele para remover a letra
			for(j=i; s[j];j++)
			{
				//substtuindo a letra pela posterior (andando com as letras)
				s[j] = s[j+1];
			}
			//decrementando o 'i' para q todas as letras escolhidas sejam removidas
			i--;
		}
	}	
}
*/
