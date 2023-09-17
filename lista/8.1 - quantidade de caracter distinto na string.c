/*Questão 01:
Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.*/
#include <stdio.h>
#define QUANT 30
int caracterDistinto(char s[]);
void main()
{
	char string[QUANT];
	printf("Digite uma string: ");
	gets(string);
	
	//chamando o resultado da função
	printf("A quantidade de caracteres distintos em '%s': %d", string, caracterDistinto(string));
}
int caracterDistinto(char s[])
{
	int i, j, cont=0;
	
	//percorrendo a string
	for(i=0; s[i]; i++)
	{
		//percorrendo as posições da string
		for(j=0; j<i; j++)
		{
			//se encontrar uma caracter igual, pausa, pois não é distinto
			if(s[i] == s[j])
			{
				break;
			}
		}
		//se houver caracter igual, contar
		if(i == j)
		{
			cont++;
		}
	}
	return cont; //retornando a quantidade de caracteres distintos
}
