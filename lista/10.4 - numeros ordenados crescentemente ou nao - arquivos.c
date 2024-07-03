/* Questão 04:
   Desenvolver uma função que, dado um arquivo texto contendo 
   números, determine se estes encontram-se ordenados crescentemente.*/
#include <stdio.h>
#include <limits.h>
int ordemCrescente(char nome[]);
void main()
{
	char nomeArq[20] = "questao04.txt";
	
	int retorno = ordemCrescente(nomeArq);//chamando a funcão
	
	if(retorno == -1)
	{
		printf("\nErro ao abrir o arquivo.");
	}
	else
	{
		if(retorno == 0)
		{
			printf("\nNAO estao ordenados crescentemente");
		}
		else
		{
			printf("\nEstao ordenados crescentemente");
		}
	}
}
int ordemCrescente(char nome[])
{
	int num, anterior = INT_MIN;
	FILE* arq;
	arq = fopen(nome, "r"); //abrindo o arquivo
	
	//verificando se o arquivo pode ser aberto
	if(!arq)
	{
		return -1;
	}
	else
	{
		//enquanto nao chegar no final do arquivo..
		while(fscanf(arq, "%d", &num) != EOF)
		{
			//verificar se os numeros do arquivo estão ordenados crescentemente
			if(num < anterior)
			{
				fclose(arq); //fechando o arquivo e retornando 0, pois não está ordenado crescentemente
				return 0;
			}
			anterior = num; //atualizando o valor de 'anterior'
		}
		fclose(arq); //fechando o arquivo e retornando 1, pois está ordenado crescentemente
	}
}











