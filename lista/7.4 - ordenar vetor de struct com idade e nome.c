/*Questão 04:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
Observação: o vetor será considerado ordenado se
estiver organizado crescentemente em função da
idade. Porém, no caso de pessoas com a mesma
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
	pessoa[2].idade = 20;  // mesma idade de Maria, mas Joao vem antes (J < M), então o vetor NÃO ESTÁ ORDENADO
	
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
	//percorrendo o vetor de pessoas até 'tamanho-1' para não chegar a um "lixo de memória"
	for(i=0; i<tamanho-1; i++)
	{
		//veriricando se a posição seguinte é menor que a anterior, pois não será crescente
		if(pessoa[i+1].idade < pessoa[i].idade)
		{
			return 0; //retornando 0 para idades não crescentes
		}
		
		//verificando se as idades são iguais, para comparar por nomes
		if(pessoa[i+1].idade == pessoa[i].idade)
		{
			//verificando se nome está em ordem decrescente e retornando 0
			if(strcmp(pessoa[i].nome, pessoa[i+1].nome) > 0)
			{
				return 0;
			}
		}
	}
	//retornando 1, pois se saiu da repetição é porque está ordenado crescentemente
	return 1;
}
