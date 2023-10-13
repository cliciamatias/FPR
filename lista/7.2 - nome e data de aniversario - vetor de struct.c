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
}
