/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/
#include <stdio.h>
#include <string.h>
int funcaoStrlen(char nome[]);
void main()
{
	char nome[20];
	int strlen;
	
	printf("Digite um nome: ");
	fflush(stdin);
	gets(nome);
	
	//chamando a função STRLEN
	strlen = funcaoStrlen(nome);
	printf("\nO nome %s possui %d letras.", nome, strlen);
}
//FUNÇÃO STRLEN - quantidade de letras
int funcaoStrlen(char nome[])
{
	int i, cont=0;
	
	for(i=0; nome[i]!='\0'; i++)
	{
		cont++;
	}
	return cont;
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
//_____________________________________________________________________________________

	//STRLEN - LER NOME E QUANTIDADE DE LETRAS
	char nome[] = "Linda";
	int tamanho = strlen(nome);
	
	printf("O %s tem %d letras.", nome, tamanho);
//_____________________________________________________________________________________	

	//STRCMP - COMPARAR STRING ('s1'>'s2' = -1; 's1'=='s2' = 0; 's1'>'s2' = 1)
	char s1[] = "Muito";
	char s2[] = "Bela";
	int resultado = strcmp(s1,s2);
	
	printf("O resultado da comparacao eh %d", resultado);
//______________________________________________________________________________________

	//STRCAT - CONCATENAR(UNIR) STRINGS
	char s1[] = "Muito ";
	char s2[] = "Bela";
	
	printf("%s", strcat(s1,s2));
	
//_____________________________________________________________________________________
	//STRUPR/STRLWR - LETRAS MAIUSCULA E MINUSCULA
	char nome[] = "Linda";
	char sobrenome[] = "Bonita";

	printf("%s %s", strupr(nome), strlwr(sobrenome));
	
}
*/
