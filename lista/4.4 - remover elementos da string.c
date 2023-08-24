/*Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
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
	for(i=0; s[i]!='\0'; i++)
	{
		//verificando se na string há o caracter a ser removido
		if(s[i] == c)
		{
			//se encontrar o caracter, entra no for e percorre ele para remover a letra
			for(j=i; s[j]!='\0';j++)
			{
				//substtuindo o a letra pela ultima (andando com as letras)
				s[j] = s[j+1];
			}
			//decrementando o 'i' para q todas as letras escolhidas sejam removidas
			i--;
		}
	}	
}
