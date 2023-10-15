/*Questão 03:
Desenvolver uma função, em C, que, dada uma
string s e dada uma posição p desta string, crie duas
novas strings: s1 com os caracteres de s das
posições 0 a p-1; e s2 com os caracteres de s da
posição p à última.
Nota: Caso p seja uma posição inválida, a função
deverá retornar o valor 0; caso contrário,
procederá com a criação das duas strings e
retornará o valor 1.*/
#include <stdio.h>
#include <string.h>
void main()			// |s1|p|s2 |
{					// 012345678
	char string[30] = "algoritmo";
	char s1[30];   //algo
	char s2[30];   //ritmo
	int p = 4;
	
	criarS1eS2(string,s1,s2,p);
	
	printf("s: %s\n", string);
	printf("s1: %s\n", s1);
	printf("s2: %s", s2);
}
int criarS1eS2(char s[], char s1[], char s2[], int p)
{
	int i, j, tamanho = strlen(s);
	//verificando se a posição 'p' é menor que 0 ou maior que o tamanho da string, pois será inválida
	if((p < 0) || (p > tamanho))
	{
		return 0; //retornando 0 pois a posição é inválida
	}
	else
	{
		//percorrendo 's' para passar caracteres de 's' para 's1'
		for(i=0; i < p; i++)
		{
			//atribuindo caracteres da direita de 's' para 's1'
			s1[i] = s[i];
		}
		s1[i] = '\0'; //encerrando 's1'
		
		for(j=0; i<tamanho; j++, i++)
		{
			//atribuindo caracteres da esquerda de 's' para 's1'
			s2[j] = s[i];
		}
		s2[i-p] = '\0'; //encerrando 's2'
	}
}
