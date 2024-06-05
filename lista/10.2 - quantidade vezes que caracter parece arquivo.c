/* Questão 02:
   Desenvolver uma função que, dado um arquivo texto, verifique o 
   número de vezes que um determinado caracter aparece no arquivo.*/
#include <stdio.h>
int quantCaracterAparece(char nomeArq[], char c);
void main()
{
	char nomeArq[20];
	char caracter = 'a';
	int quantAparece = quantCaracterAparece(nomeArq, caracter); //chamando a função
	
	printf("Nome do arquivo: ");
	fflush(stdin);
	gets(nomeArq);
	
	if(quantAparece != -1)
	{
		printf("\n\nO caracter '%c' aparece %d vezes no arquivo.", caracter, quantAparece);
	}
	else
	{
		printf("\n\nErro ao abrir o arquivo.");
	}
}
int quantCaracterAparece(char nomeArq[], char c)
{
	FILE* arq; //declarando o arquivo
	char ch;
	int cont=0;
	
	arq = fopen(nomeArq, "r"); //abrindo o arquivo
	
	//verificando se o arquivo pôde ser aberto
	if(!arq)
	{
		return -1; // se tiver erro, retornar -1
	}
	else
	{
		while(fscanf(arq, "%c", &ch) != EOF) //lendo os caracateres do arquivo
		{
			//verificando se há o caracter no arquivo
			if(ch == c)
			{
				cont++; //contando a qauntidade de caracteres 'c' no arquivo
			}
		}
		fclose(arq); //fechando o arquivo
		return cont; //retornando a quantidade de vezes que o caracter aparece
	}
}
