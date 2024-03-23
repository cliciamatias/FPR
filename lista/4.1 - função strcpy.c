/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/
//STRCPY - COPIAR STRING DE S2 PARA S1
#include <stdio.h>
void funcaoStrcpy(char s1[], char s2[]);
void main()
{
	char s1[10] = "Linda";
	char s2[10] = "demais";
	
	funcaoStrcpy(s1, s2); //chamando a função
	
	printf("s1 = %s \ns2 = %s", s1, s2); //exibindo as strings, 's1'(original) e 's2'(cópia)
}
void funcaoStrcpy(char s1[], char s2[])
{
	int i, j;
	
	//percorrendo a string 's1'
	for(i=0; s1[i]; i++)
	{
		//percorrendo a string 's2'
		for(j=0; s2[j]; j++)
		{
			s1[j] = s2[j]; //'s1' recebendo a string de 's2'
		}
	}
	s1[j] = '\0'; //encerrando 's1' para evitar lixo de memória
}

/*
#include <stdio.h>
void funcaoStrcpy(char destino[], char origem[]);
void main()
{
	char origem[20], destino[20];
	
	printf("Digite uma string para ser copiada: ");
	fflush(stdin);
	gets(origem);
	
	//chamando a função STRCPY
	funcaoStrcpy(destino, origem);
	printf("\nString copiada: %s", destino);
}
//FUNÇÃO STRLEN - quantidade de letras
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
}*/
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
