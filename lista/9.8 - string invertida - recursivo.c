/*Quest�o 08:
Desenvolver uma fun��o recursiva que, dada
uma string, exiba-a invertida.*/
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
		//invertendo os caracateres atrav�s do 'tamanho-1'
		invertido(s, tamanho-1);
	}
}
