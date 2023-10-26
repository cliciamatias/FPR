/*Questão 01 [2,5 pontos]:
Implementar uma função que, dadas duas strings s1 e
s2, determine se s2 possui (retornando 1) ou não
(retornando 0) os mesmos caracteres de s1, na mesma
quantidade, mesmo que embaralhados.*/
#include <stdio.h>
#include <string.h>
int mesmoCaracter(char s1[], char s2[]);
void main()
{
	char s1[20] = "casaco"; // c=2 ; a=2 ; s=1 ; o=1
	char s2[20] = "casaca"; // c=2 ; a=3 ; s=1
	int retorno = mesmoCaracter(s1, s2); //chamando a função
	
	//verificando o retorno e exibindo o resultado
	if(retorno == 1)
	{
		printf("\n(%s) POSSUI os mesmos caracteres de (%s).", s2, s1);
	}
	else
	{
		printf("\n(%s) NAO possui os mesmos caracteres de (%s).", s2, s1);
	}	
}
int mesmoCaracter(char s1[], char s2[])
{
	int i, j, somaS1=0, somaS2=0;
	
	//percorrendo 's1'
	for(i=0; s1[i]; i++)
	{
		//somando o valor de cada caracter de 's1', de acordo com a tabela ASCII (cada caracter tem um valor inteiro)
		somaS1 += (int)s1[i];
	}
	//percorrendo 's2'
	for(j=0; s2[j]; j++)
	{
		//somando o valor de cada caracter de 's2', de acordo com a tabela ASCII (cada caracter tem um valor inteiro)
		somaS2 += (int)s2[j];
	}
	//verificando se a soma dos caracteres de 's1' é igual à de 's2', pois assim ambos terão caracteres na mesma frequência(quantidade)
	if(somaS1 == somaS2)
	{
		return 1; //retornando 1 pois 's2' possui os mesmos caracteres de 's1'
	}
	else
	{
		return 0; //retornando 0 pois não possuem os mesmos caracteres
	}
}
