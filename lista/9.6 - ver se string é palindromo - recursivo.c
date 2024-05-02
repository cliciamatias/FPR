/*Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/
#include <stdio.h>
#include <string.h>
int recursivo(char s[], int inicio, int tamanho);
void main()
{
	char s[10] = "osso";
	int i=0, j=strlen(s);
	int retorno = recursivo(s, i, j-1);
	
	if(retorno == 1)
	{
		printf("\n'%s' eh palindromo.", s);
	}
	else
	{
		printf("\n'%s' nao eh palindromo.", s);
	}
}
int recursivo(char s[], int inicio, int tamanho)
{
	if(inicio >= tamanho) // CASO BASE - verificando se o 'inicio' é maior ou igual 'tamanho' da string 's' para rtornar que é palindromo
	{
		return 1;
	}
	if(s[inicio] == s[tamanho]) //CASO GERAL - verificando se o incio e o fim da string sao iguais, pois na chamada da função 'incio+' e 'tamanho-1'
	{
		recursivo(s, inicio+1, tamanho-1); //chamando a função recursiva
	}
	else
	{
		return 0; //quando os caracteres espelhados de 's' forem diferentes não eh palindromo
	}
}




// --------------------------------------------------------------------------------------------------------------
/*Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/
/*
#include <stdio.h>
#include <string.h>
int stringPalindromo(char s[], int inicio, int fim);
void main()
{
	char string[30] ="osso";
	int tamanho, retorno;
	
	tamanho = strlen(string); //contando o quantidade de caracteres da string
	//chamando a função
	retorno = stringPalindromo(string, 0, tamanho-1); //chamando a função com a string, seu inicio e seu fim
	
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
	//se o inicio da string for igual ao fim, verificar se é palíndromo
	if(s[inicio] == s[fim])
	{
		//somando o inicio e subtraindo o fim para ver se os caracteres "espelhados" de cada lado são iguais, pois será palíndromo
		stringPalindromo(s, inicio+1, fim-1);
	}
	else
	{
		return 0; //retornando 0, pois não é palíndromo
	}
} */
