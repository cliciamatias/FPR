/*Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.*/
#include <stdio.h>
#include <string.h>
void recursivo(char s1[], int tamanho);
void main()
{
	char s1[10] = "ok";
	int tamanho = strlen(s1);
	recursivo(s1, tamanho-1);
}
void recursivo(char s1[], int tamanho)
{
	if(s1[tamanho])
	{
		printf("%c", s1[tamanho]);
		recursivo(s1, tamanho-1);
	}
}


// ------------------------------------------------------------------------------------

/*Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.*/
/*
#include <stdio.h>
#include <string.h>

void invertido(char s[], int tamanho);
void main()
{
	char string[30] = "amor"; // roma
	int tamanho = strlen(string);
	
	invertido(string, tamanho-1);
}
void invertido(char s[], int tamanho)
{
	//verificando a string inteira (s[tamanho] != '\0')
	if(s[tamanho])
	{
		//exibindo a string invertida
		printf("%c", s[tamanho]);
		//invertendo os caracateres através do 'tamanho-1'
		invertido(s, tamanho-1);
	}
}
*/
