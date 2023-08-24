/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/
#include <stdio.h>
#include <string.h>
void strConcatenar (char string1[], char string2[]);
int strTamanho (char s[]);

void main ()
{
	char s1[30], s2[30];
		
	//leitura das strings
	printf ("Entre com a primeira string: ");
	fflush (stdin);
	gets (s1);
	
	printf ("\nEntre com a segunda string: ");
	fflush (stdin);
	gets (s2);
	
	//chamando a função
	strConcatenar (s1, s2);
	
	//exibindo as duas strings depois da concatenação
	printf ("\nExibindo as duas strings depois da concatenacao:");
	printf ("\ns1: %s", s1);
	printf ("\ns2: %s", s2);
}
void strConcatenar (char string1[], char string2[])
{
	int i, j;
	
	//percorrendo a string2
	for (i=strTamanho(string1),j=0;string2[j];i++,j++)
	{
		string1[i] = string2[j];
	}
	
	//finalizando a string1
	string1[i] = '\0';
}
int strTamanho (char s[])
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo toda a string
	for (i=0;s[i]/*!='\0'*/;i++);
	//{
		//cont++;
	//}
	
	//retornando o resultado
	return i;//cont;
}
/*
//STRCAT - CONCATENAR(UNIR) STRINGS
	char s1[] = "Muito ";
	char s2[] = "Bela";
	
	printf("%s", strcat(s1,s2));
*/
