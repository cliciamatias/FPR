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
#include <stdlib.h> //função preencherMatriz
#include <time.h>
void preencherAleatorio(int lin, int col, int m[lin][col]);
void exibirMatriz(int lin, int col, int m[lin][col]);
void somaColuna(int lin, int col, int m[lin][col], int vetor[]);

void main()
{
	int i, linha=10, coluna=8;
	int matriz[linha][coluna], vetor[coluna];
	
	preencherAleatorio(linha,coluna,matriz); //preenchendo matriz de aleatórios
	exibirMatriz(linha,coluna,matriz); //exibindo matriz
	
	//chamando a função da soma de colunas
	somaColuna(linha,coluna,matriz, vetor);
	
	//exibindo vetor com a soma das colunas da matriz
	for(i=0; i<coluna; i++)
	{
		printf("%d ", vetor[i]);
	}
}
void somaColuna(int lin, int col, int m[lin][col], int vetor[])
{
	int i, j;
	
	//percorrendo as colunas da matriz
	for(j=0; j<col; j++)
	{
		//inicializando o vetor que será preenchido com o somatório das colunas
		vetor[j] = 0;
		//percorrendo as linhas da matriz
		for(i=0; i<lin; i++)
		{
			//vetor rcebendo soma de cada coluna da matriz
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
