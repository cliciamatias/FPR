/*Quest�o 04:
Considere a exist�ncia de um vetor de structs
com quant posi��es, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), g�nero (char) e
idade (int). Pede-se uma fun��o que determine
se os elementos deste vetor est�o ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contr�rio.
Observa��o: o vetor ser� considerado ordenado se
estiver organizado crescentemente em fun��o da
idade. Por�m, no caso de pessoas com a mesma
idade, estas devem estar ordenadas crescentemente
pelo nome.*/
#include <stdio.h>
#include <string.h>
#define TAM 5
typedef struct
{
	char nome[30];
	char genero;
	int idade;
	
} tipoPessoas;

int ordenado(tipoPessoas pessoa[], int tamanho);
void main()
{
	tipoPessoas pessoa[TAM];
	int retorno;
	
	strcpy(pessoa[0].nome, "Anna");
	pessoa[0].genero = 'f';
	pessoa[0].idade = 19;
	
	strcpy(pessoa[1].nome, "Maria");
	pessoa[1].genero = 'f';
	pessoa[1].idade = 20;
	
	strcpy(pessoa[2].nome, "Joao");
	pessoa[2].genero = 'm';
	pessoa[2].idade = 20;  // mesma idade de Maria, mas Joao vem antes (J < M), ent�o o vetor N�O EST� ORDENADO
	
	strcpy(pessoa[3].nome, "Pedro");
	pessoa[3].genero = 'm';
	pessoa[3].idade = 22;
	
	strcpy(pessoa[4].nome, "Marcia");
	pessoa[4].genero = 'f';
	pessoa[4].idade = 23;
	
	retorno = ordenado(pessoa, TAM);
	if(retorno == 1)
	{
		printf("\nVetor ORDENADO!");
	}
	else
	{
		printf("\nVetor NAO ORDENADO!");
	}
}

int ordenado(tipoPessoas pessoa[], int tamanho)
{
	int i;
	//percorrendo o vetor de pessoas at� 'tamanho-1' para n�o chegar a um "lixo de mem�ria"
	for(i=0; i<tamanho-1; i++)
	{
		//veriricando se a posi��o seguinte � menor que a anterior, pois n�o ser� crescente
		if(pessoa[i+1].idade < pessoa[i].idade)
		{
			return 0; //retornando 0 para idades n�o crescentes
		}
		
		//verificando se as idades s�o iguais, para comparar por nomes
		if(pessoa[i+1].idade == pessoa[i].idade)
		{
			//verificando se nome est� em ordem decrescente e retornando 0
			if(strcmp(pessoa[i].nome, pessoa[i+1].nome) > 0)
			{
				return 0;
			}
		}
	}
	//retornando 1, pois se saiu da repeti��o � porque est� ordenado crescentemente
	return 1;
}
