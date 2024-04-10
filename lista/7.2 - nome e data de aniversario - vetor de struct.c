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
}TData;

typedef struct
{
	char nome[20];
	TData dataNiver;
}TPessoa;

int quantNiver(TPessoa pessoa[], int tamanho, int m);
int verificarDatas(TData data, TData dataMenor, TData dataMaior);
void exibirPessoa(TPessoa pessoa[], int tamanho, TData d1, TData d2);

void main()
{
	TPessoa pessoa[TAM];
	int mes;
	
	int quant = quantNiver(pessoa, TAM, mes); //chamando a função com quantidade de aniversariantes no mes 'm'
	printf("Quantidade de pessoas que fazem aniversario no mes %d: %d.", mes, quant);
	
	//E COMO CHAMA A FUNÇÃO DE EXIBIR ANIVERSARIANTES ENTRE D1 E D2?????????????????????????????????
}

//- Determinar a quantidade de pessoas que fazem aniversário no mês M;
int quantNiver(TPessoa pessoa[], int tamanho, int m)
{
	int i, cont=0;
	
	for(i=0; i<tamanho; i++)
	{
		if(pessoa[i].dataNiver.mes == m)
		{
			cont++;
		}
	}
	return cont;	
}

int verificarDatas(TData data, TData dataMenor, TData dataMaior)
{
	//verificando se 'data' está entre os meses compreendidos pelo intervalo 
	//passado, porém não no mês da 'dataMenor' e nem da 'dataMaior'
	if ((data.mes > dataMenor.mes) && (data.mes < dataMaior.mes))
	{
		return 1;
	}

	//verificando se está no mês de 'dataMenor'. Além disso, o dia deve 
	//ser maior ou igual ao dia de 'dataMenor'
	if ((data.mes == dataMenor.mes) && (data.dia >= dataMenor.dia))
	{
		return 1;
	}
	
	//verificando se está no mês de 'dataMaior'. Além disso, o dia deve 
	//ser menor ou igual ao dia de 'dataMaior'
	if ((data.mes == dataMaior.mes) && (data.dia <= dataMaior.dia))
	{
		return 1;
	}

	return 0;
}
//- Exibir os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, ambas do tipo TData.
void exibirPessoa(TPessoa pessoa[], int tamanho, TData d1, TData d2);
{
	int i;
	
	for(i=0; i<tamanho; i++)
	{
		//verificando pessoas com datas entre d1 e d2
		if(verificarDatas(pessoa[i].dataNiver, d1, d2) == 1)
		{
			printf("\n%s", pessoa[i].nome); //exibindo todas pessoas que fazem aniversário entre as datas d1 e d2
		}
	}
	
}


//----------------------------------------------------------
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
/*
#include <stdio.h>
#include <string.h>
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

void dados(tipoNiver pessoa[], int tamanho);
int quantNiverMes(tipoNiver pessoa[], int tamanho, int m);
void pessoasEntreD1eD2(tipoNiver pessoa[], int tamanho, tipoData d1, tipoData d2);

void main()
{
    tipoNiver aniversariante[TAM];
    int m, quant;

    dados(aniversariante, TAM);

    printf("\n\nDigite o mes desejado: ");
    scanf("%d", &m);
    quant = quantNiverMes(aniversariante, TAM, m);
    printf("\n\nA quantidade de pessoas que fazem aniversario no mes %d: %d", m, quant);
	
	//declarando 'd1' e 'd2' com tipo 'tipoData'
    tipoData d1 = {1, 3};
    tipoData d2 = {31, 8};
	//exibindo nome de pessoa entre as datas
    printf("\n\nAniversariantes entre as datas %d/%d e %d/%d: \n", d1.dia, d1.mes, d2.dia, d2.mes);
    pessoasEntreD1eD2(aniversariante, TAM, d1, d2);
}
//lendo os dados de cada aniversariante
void dados(tipoNiver pessoa[], int tamanho)
{
    int i;
    for(i=0; i<tamanho; i++)
    {
        printf("\n\n-------Dados da pessoa %d:-------\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", pessoa[i].nome);

        printf("Digite o dia de aniversario: ");
        scanf("%d", &pessoa[i].data.dia);

        printf("Digite o mes de aniversario: ");
        scanf("%d", &pessoa[i].data.mes);
    }
}
//Determinando a quantidade de pessoas que fazem aniversário no mês 'M'
int quantNiverMes(tipoNiver pessoa[], int tamanho, int m)
{
    int i, cont = 0;
    //percorrendo aniversariantes
    for(i=0; i<tamanho; i++)
    {	
    	//verificando se o mês do aniversariante 'i' é igual ao mes escolhido e contando
        if(pessoa[i].data.mes == m)
        {
            cont++; 
        }
    }
    return cont;
}
//exibindo os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, ambas do tipo TData
void pessoasEntreD1eD2(tipoNiver pessoa[], int tamanho, tipoData d1, tipoData d2)
{
    int i;
    for(i=0; i<tamanho; i++)
    {
    	//verificando se a data do aniversariante está entre 'd1' e 'd2' e exibindo seu nome
        if((pessoa[i].data.mes > d1.mes && pessoa[i].data.mes < d2.mes) ||
        (pessoa[i].data.mes == d1.mes && pessoa[i].data.dia >= d1.dia) ||
        (pessoa[i].data.mes == d2.mes && pessoa[i].data.dia <= d2.dia))
        {
            printf("-------- %s --------\n", pessoa[i].nome);
        }
    }
}*/
