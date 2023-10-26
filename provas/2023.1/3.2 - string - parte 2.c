/*Questão 03 [2,5 pontos]:
Dadas duas strings s1 e s2, implementar uma função que crie duas outras strings – s3 e s4 – com as seguintes
características:
? s3: conterá todos os caracteres de s1 que também estão em s2;
? s4: conterá todos os caracteres de s1 que não estão em s2.
Exemplo:
s1: “PROGRAMACAO” s3: “ROGRAMAAO”
s2: “ALGORITMOS” s4: “PC”*/
#include <stdio.h>
void criar(char s1[], char s2[], char s3[], char s4[]);
void main()
{
	char s1[20] = "programacao";
	char s2[20] = "algoritmos";
	char s3[20];
	char s4[20];
	
	//chamando a função
	criar(s1,s2,s3,s4);
	//exibindo o resultado
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	printf("s4: %s\n", s4);
	
}
void criar(char s1[], char s2[], char s3[], char s4[])
{
	int i, j, encontrou, p3=0, p4=0;
	
	//percorrendo 's1'
	for(i=0; s1[i]; i++)
	{
		encontrou=0;
		//percorrendo 's2' para verificar se há elemento igual em 's1'
		for(j=0; s2[j]; j++)
		{
			//verificando os caracteres de 's1' que também estão em 's2'
			if(s1[i] == s2[j])
			{
				encontrou=1;
			}
		}
		//verificando se foi encontrado caracteres iguais em 's1' e 's2'
		if(encontrou == 1)
		{
			//'s3' recebendo caracteres de 's1' que também existem em 's2', incrementando a posição 'p3'
			s3[p3++] = s1[i];
		}
		//se não for encontrado...
		else
		{	
			//...'s4' recebe todos os caracteres de 's1' que não estão em 's2', incrementando a posição 'p4'
			s4[p4++]=s1[i];
		}
	}
	//encerrando as strings
	s3[i] = '\0';
	s4[i] = '\0';
}
