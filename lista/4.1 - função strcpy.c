/*Quest�o 01:
Suponha que n�o existissem as fun��es strlen,
strcpy, strcat e strcmp. Pede-se, ent�o, a
implementa��o de fun��es que tenham o
mesmo objetivo daquelas.*/
#include <stdio.h>
#include <string.h>
void funcaoStrcpy(char destino[], char origem[]);
void main()
{
	char origem[20], destino[20];
	
	printf("Digite uma string para ser copiada: ");
	fflush(stdin);
	gets(origem);
	
	//chamando a fun��o STRCPY
	funcaoStrcpy(destino, origem);
	printf("\nString copiada: %s", destino);
}
//FUN��O STRLEN - quantidade de letras
void funcaoStrcpy(char destino[], char origem[])
{
	int i;
	
	i=0;
	while(origem[i] != '\0')
	{
		destino[i] = origem[i];
		i++;
	}
	destino[i] = '\0';
}
/*
#include <stdio.h>
#include <string.h>
void main()
{
	//STRCPY - COPIAR STRING DE S2 PARA S1
	char s1[10]="oi", s2[10]="ola mundo";
	strcpy(s1,s2);
	
	printf("%s", s1);
}
*/
