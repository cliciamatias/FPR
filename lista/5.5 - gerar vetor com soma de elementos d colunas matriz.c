/*QUESTÃO 05:
Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherAleatorio(int lin, int col, int m[lin][col]);
void exibirMatriz(int lin, int col, int m[lin][col]);
void somaColuna(int lin, int col, int m[lin][col], int vetor[]);

void main()
{
	int i, linha=4, coluna=8;
	int matriz[linha][coluna], vetor[coluna];
	
	preencherAleatorio(linha,coluna,matriz);
	exibirMatriz(linha,coluna,matriz);
	somaColuna(linha,coluna,matriz, vetor);
	//printf("Vetor: ");
	for(i=0; i<coluna; i++)
	{
		printf("|%d| ", vetor[i]);
	}
}
void somaColuna(int lin, int col, int m[lin][col], int vetor[])
{
	int i, j;
	
	for(j=0; j<col; j++)
	{
		vetor[j] = 0;
		for(i=0; i<lin; i++)
		{
			vetor[j] += m[i][j];	
		}
	}
}
void preencherAleatorio(int lin, int col, int m[lin][col])
{
	int i, j;
	
	srand(time(NULL));
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			m[i][j] = rand()%5;
		}
	}
}
void exibirMatriz(int lin, int col, int m[lin][col])
{
	int i, j;
	
	printf("Matriz ORIGINAL: \n");
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
