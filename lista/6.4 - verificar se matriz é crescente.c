/*Questão 04:
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que verifique se os elementos da matriz estão
ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento será maior ou igual
àquele da mesma linha, porém da coluna anterior – caso exista);
b. O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior (caso exista).
Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função; caso contrário, 0.*/
#include <stdio.h>
#define L 5
#define C 6
int matrizCrescente(int matriz[L][C]);
void exibirMatriz(int m[L][C]);
void main()
{
	int retorno;
	int matriz[L][C] = {{11,12,13,14,15,16},
						{17,18,19,20,21,22},
						{23,24,25,26,27,28},
						{29,30,31,32,33,34},
						{35,36,37,38,39,40}};	
	exibirMatriz(matriz);
	
	//chamando a função
	retorno = matrizCrescente(matriz);
	//exibindo o respectivo resultado
	if(retorno == 1)
	{
		printf("\nMatriz eh crescente!!");
	}
	else
	{
		printf("\nMatriz NAO eh crescente!!");
	}
}
int matrizCrescente(int m[L][C])
{
	int i, j;
	
	for(i=0; i<L; i++)
	{
		for(j=1; j<C; j++)
		{
			//se 2° elemento da coluna(m[i][1]) for menor que o anterior, não é crescente
			if(m[i][j] < m[i][j-1])
			{
				return 0; //a matriz não é crescente
			}
			//verificando se o elemento da 1° coluna é menor que o último da linha anterior, pois não será crescente
			if(m[i][0] < m[i-1][C-1])
			{
				return 0; //a matriz não é crescente
			}
		}
	}
	return 1; //a matriz é crescente 
}
void exibirMatriz(int m[L][C])
{
	int i, j;
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			printf("|%d| ", m[i][j]);
		}
		printf("\n");
	}
}
