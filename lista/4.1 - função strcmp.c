/*/*Quest�o 01:
Suponha que n�o existissem as fun��es strlen,
strcpy, strcat e strcmp. Pede-se, ent�o, a
implementa��o de fun��es que tenham o
mesmo objetivo daquelas.*/

#include <stdio.h>
#include <string.h>
int funcaoStrcmp(char s1[], char s2[]);
void main()
{
	char s1[20], s2[20];
	int retorno;
	
	printf("Digite a primeira String: ");
	fflush(stdin);
	gets(s1);
	
	printf("Digite a segunda String: ");
	fflush(stdin);
	gets(s2);
	
	//chamando a fun��o STRCMP
	retorno = funcaoStrcmp(s1,s2);
	
	if(retorno == 0)
	{
		printf("\nAs strings sao iguais.\nRetorno: %d.",retorno);
	}
	else
	{
		if(retorno == -1)
		{
			printf("\nA string %s eh maior que a string %s.\nRetorno: %d.",s1,s2,retorno);
		}
		else
		{
			printf("\nA string %s eh menor que a string %s.\nRetorno: %d.",s2,s1,retorno);
		}
	}
}
//STRCMP - COMPARAR STRING ('s1'>'s2' = -1; 's1'=='s2' = 0; 's1'>'s2' = 1)
int funcaoStrcmp(char s1[], char s2[])
{
	int i;
	
	for(i=0;(s1[i]==s2[i])&&(s1[i])&&(s2[i]); i++)
	{
		if(s1[i] == s2[i])
		{
			return 0;
		}
		else
		{
			if(s1[i] > s2[i])
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
}

/*
	//STRCMP - COMPARAR STRING ('s1'>'s2' = -1; 's1'=='s2' = 0; 's1'>'s2' = 1)
	char s1[] = "Muito";
	char s2[] = "Bela";
	int resultado = strcmp(s1,s2);
	
	printf("O resultado da comparacao eh %d", resultado);
*/
