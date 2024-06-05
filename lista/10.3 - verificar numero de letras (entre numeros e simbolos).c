/*Questão 03:
Desenvolver uma função que, dado um arquivo texto, verifique o 
número de letras existentes no mesmo (entendendo que no arquivo 
podem existir letras, algarismos e símbolos).*/
#include <stdio.h>
int numLetras(char nomeArq[]);
void main()
{
	char nomeArq[20] = "questao3.txt";
	int num = numLetras(nomeArq); //chamando a função
	
	if(numLetras != -1)
	{
		printf("\n\nNumero de letras existentes no arquivo: %d.", num);
	}
	else
	{
		printf("\n\nErro ao abrir o arquivo.");
	}
}
int numLetras(char nomeArq[])
{
	FILE* arq;
	char ch;
	int cont=0;
	
	arq = fopen(nomeArq, "r"); //abrindo o arquivo e lendo ele
	
	//verificando se o arquivo pode ser aberto
	if(!arq)
	{
		return -1; //se o arquivo nao abrir retornar -1
	}
	else
	{
		//enquanto nao chegar no fim do arquivo..
		while(fscanf(arq, "%c", &ch) != EOF)
		{
			//verificando se o caracter é apenas letra
			if((ch >= 'a') && (ch <= 'z'))
			{
				cont++; //se for letra, contar
			}
		}
		fclose(arq); //fechando o arquivo
		return cont; //retornando o resultado 
	}
}














