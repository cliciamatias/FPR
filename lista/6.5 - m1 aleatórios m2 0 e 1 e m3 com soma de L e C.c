/*Questão 05:
Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10, com as seguintes características:
a. M1: matriz contendo números inteiros quaisquer;
b. M2: matriz contendo apenas os valores 0 ou 1.
Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10, cujos elementos são
definidos da seguinte forma:
M2ij = 0 --> M3ij = M1ij
M2ij = 1 --> M3ij = soma dos elementos da linha i com os da coluna j da matriz.*/
#include <stdio.h>
void preencherM1(int n, int m1[n][n]);
void preencherM2(int n, int m2[n][n]);
void matrizM3(int n, int m1[n][n], int m2[n][n], int m3[n][n]);
void exibir(int n, int m[n][n]);
void main()
{
	int n=5;
	int m1[n][n], m2[n][n], m3[n][n]; 
	
	printf("Matriz M1:\n");
	preencherM1(n, m1);
	exibir(n, m1);
	
	printf("\nMatriz M2:\n");
	preencherM2(n, m2);
	exibir(n, m2);
	
	printf("\nMatriz M3:\n");
	matrizM3(n, m1, m2, m3);
	exibir(n, m3);
}

void matrizM3(int n, int m1[n][n], int m2[n][n], int m3[n][n])
{
	int i, j, k, soma;
	
	//percorrendo a matriz
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{ 
			//M2ij = 0 --> M3ij = M1ij
			if(m2[i][j] == 0)
			{
				m3[i][j] = m1[i][j]; //se o elemento de 'm2' for 0, m3 receberá elementos de 's1'
			}
			//M2ij = 1 --> M3ij = soma dos elementos da linha i com os da coluna j da matriz
			if(m2[i][j] == 1)
			{
				soma = 0; //zerando a soma para renovar a cada repetição
				for(k=0; k<n; k++)
				{
		 			//somando os elementos das linhas e colunas da matriz 
					soma += m1[i][k];
					soma += m1[k][j];	
				}
				soma -= m1[i][j]; //decrementando os um dos valores da matriz principal somados duas vezes anteriormente
				m3[i][j] = soma; // quando 'm2' for 1, a posição em 'm3' receberá a soma dos elementos de 'm1'
			}
		}
	}	
}
void preencherM1(int n, int m1[n][n])
{
	int i, j;
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			m1[i][j] = rand()%6;
		}
	}
}
void preencherM2(int n, int m2[n][n])
{
	int i, j;
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			m2[i][j] = rand()%2;
		}
	}
}
void exibir(int n, int m[n][n])
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("|%d|", m[i][j]);
		}
		printf("\n");
	}
}




//---------------------------------------------------------------------------------------------------------------
/*Questão 05:
Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10, com as seguintes características:
a. M1: matriz contendo números inteiros quaisquer;
b. M2: matriz contendo apenas os valores 0 ou 1.
Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10, cujos elementos são
definidos da seguinte forma:
M2ij = 0 --> M3ij = M1ij
M2ij = 1 --> M3ij = soma dos elementos da linha i com os da coluna j da matriz.*/
/*
#include <stdio.h>
#include <time.h>
#define L 5
#define C 5
void preencherAleatorioM1(int m[L][C]);
void preencherAleatorioM2(int m[L][C]);
void exibirMatriz(int m[L][C]);
int somaLinhaColuna(int m[L][C], int linha, int coluna);
void gerarM3(int m1[L][C], int m2[L][C], int m3[L][C]);
void main()
{
	int matriz1[L][C], matriz2[L][C], matriz3[L][C];
	
	printf("Matriz m1: \n");
	preencherAleatorioM1(matriz1);
	exibirMatriz(matriz1);
	
	printf("Matriz m2: \n");
	preencherAleatorioM2(matriz2);
	exibirMatriz(matriz2);
	
	printf("Matriz m3: \n");
	gerarM3(matriz1, matriz2, matriz3);
	exibirMatriz(matriz3);
	
}
void gerarM3(int m1[L][C], int m2[L][C], int m3[L][C])
{
	int i, j;
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			//verificando se o elemento de m2 é '0' e atribuindo em m3 o elemento de m1
			if(m2[i][j] == 0)
			{
				m3[i][j] = m1[i][j];
			}
			else
			{
				//caso contrário, m3 recebe a soma das linhas e colunas de m1
				m3[i][j] = somaLinhaColuna(m1,i,j); //chamando a função com resultado 
			}
		}
	}
}
int somaLinhaColuna(int m[L][C], int linha, int coluna)
{
	int i, j, soma=0;
	
	//somando os elementos da linha
	for(j=0; j<C; j++)
	{
		soma += m[linha][j];
	}
	//somando os elementos da coluna
	for(i=0; i<L; i++)
	{
		soma += m[i][coluna];
	}
	return soma; //retornando o resultado
}
void preencherAleatorioM1(int m[L][C])
{
	int i, j;
	
	srand(time(NULL));
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			m[i][j] = rand()%5;
		}
	}
}
void preencherAleatorioM2(int m[L][C])
{
	int i, j;
	
	srand(time(NULL));
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			m[i][j] = rand()%2;
		}
	}
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
	printf("\n");
}*/
