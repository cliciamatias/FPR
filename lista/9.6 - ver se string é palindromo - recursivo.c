/*Quest�o 06:
Dada uma string s, desenvolver uma fun��o
recursiva que determine se s � ou n�o um
pal�ndromo.*/
#include <stdio.h>
#include <string.h>
int stringPalindromo(char s[], int inicio, int fim);
void main()
{
	char string[30] ="osso";
	int tamanho, retorno;
	
	tamanho = strlen(string); //contando o quantidade de caracteres da string
	//chamando a fun��o
	retorno = stringPalindromo(string, 0, tamanho-1); //chamando a fun��o com a string, seu inicio e seu fim
	
	if(retorno == 0)
	{
		printf("%s: nao eh palindromo", string);
	}
	else
	{
		printf("%s: eh palindromo", string);
	}
}
int stringPalindromo(char s[], int inicio, int fim)
{
	if(inicio >= fim)
	{
		return 1;
	}
	//se o inicio da string for igual ao fim, verificar se � pal�ndromo
	if(s[inicio] == s[fim])
	{
		//somando o inicio e subtraindo o fim para ver se os caracteres "espelhados" de cada lado s�o iguais, pois ser� pal�ndromo
		stringPalindromo(s, inicio+1, fim-1);
	}
	else
	{
		return 0; //retornando 0, pois n�o � pal�ndromo
	}
}
