/*Questão 02:
Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
? Determinar a quantidade de pessoas que
fazem aniversário no mês M;
? Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.*/
#include <stdio.h>
#define TAM 3

typedef struct
{
	int dia;
	int mes;
} tipoData;

typedef struct
{
	char nome[30];
	tipoData data;
} tipoNiver;

void dados(tipoNiver pessoa[], tipoData diaMes[], int tamanho);
int quantNiverMes(tipoNiver pessoa[], int tamanho, int m);
void pessoasEntreD1eD2(tipoData data[], tipoNiver pessoa[], int tamanho, int d1, int d2);

void main()
{
	tipoNiver aniversariante[TAM];
	tipoData diaMes[TAM];
	int m, d1, d2, quant;
	
	dados(aniversariante, diaMes, TAM);
	
	printf("\n\nDigite o mes desejado: ");
	scanf("%d", &m);
	
	printf("Digite o valor de D1: ");
	scanf("%d", &d1);
	printf("Digite o valor de D2: ");
	scanf("%d", &d2);
	
	quant = quantNiverMes(aniversariante, TAM, m);
	printf("\n\nA quantidade de pessoas que fazem aniversario no mes %d: %d", m, quant);
	pessoasEntreD1eD2(diaMes, aniversariante, TAM, d1, d2);
}
//não pede, mas prefiro solicitar cada dado
void dados(tipoNiver pessoa[], tipoData diaMes[], int tamanho)
{
	int i;
	for(i=0; i<tamanho; i++)
	{
		printf("\n\n-------Dados da pessoa %d:-------\n", i+1);
		printf("Digite o nome: ");
		fflush(stdin);
		gets(pessoa[i].nome);
		
		printf("Digite o dia: ");
		scanf("%d", &diaMes[i].dia);
		
		printf("Digite o mes: ");
		scanf("%d", &diaMes[i].mes);
	}
}
int quantNiverMes(tipoNiver pessoa[], int tamanho, int m)
{
	int i, cont=0;
	//percorrendo o vetor de 'aniversariante'
	for(i=0; i<tamanho; i++)
	{
		//verificando se há aniversariantes no mes escolhido 'm'
		if(pessoa[i].data.mes == m)
		{
			//contando quantidade de pessoas que fazem aniversário no mês M
			cont++;
		}
	}
	return cont;
}
void pessoasEntreD1eD2(tipoData data[], tipoNiver pessoa[], int tamanho, int d1, int d2)
{
	int i;
	
	printf("\n\nAniversariantes entre os dias %d e %d: \n", d1, d2);
	for(i=0; i<tamanho; i++)
	{
		if((data[i].dia >= d1) && (data[i].dia <= d2))
		{
			printf("===== %s ====\n", pessoa[i].nome);
		}
	}
}
