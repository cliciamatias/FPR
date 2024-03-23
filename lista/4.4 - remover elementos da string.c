/*Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
#include <stdio.h>
void remover(char s[], char c);
void main()
{
	char s[20] = "rabanada";
	char c = 'a';
	
	printf("String antes da remocao de %c: %s\n\n", c, s);
	remover(s, c); // chamando a funcao
	printf("String depois da remocao de %c: %s", c, s);
	
}
void remover(char s[], char c)
{
	int i, j;
	//percorrendo a string
	for(i=0; s[i]; i++)
	{
		//encontrando o caracter a ser removido
		if(s[i] == c)
		{
			//percorrendo a string sem o caracter
			for(j=i; s[j]; j++)
			{
				s[j] = s[j+1]; //'andando' com os caracteres
			}
			//i--;  //nao entendi o porque do i--, pois sem ele funciona normalmente
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
/*Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
/*
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
*/
