/*Quest�o 01 [2,5 pontos]:
Considerando a exist�ncia de uma matriz de inteiros M, de ordem N (ou seja, o n� de linhas e o n� de colunas s�o iguais
a N), onde N � uma constante, desenvolver uma fun��o que retorne 1 se a seguinte regra for atendida por M (caso
contr�rio, o valor 0 dever� ser retornado):
? A soma dos elementos da diagonal principal deve ser igual � soma dos elementos que est�o acima desta
diagonal, assim como � soma dos elementos abaixo da diagonal.
Exemplo 1:
Para a seguinte matriz, a fun��o retornar� 1:
6 3 1 2 6
1 3 5 4 2
3 4 4 2 2
5 9 1 9 3
4 0 2 1 8

Exemplo 2:
Para a seguinte matriz, a fun��o retornar� 0:
1 8 5 9 4
2 5 4 6 5
4 1 2 3 6
4 5 5 8 7
4 2 5 6 9*/
#include <stdio.h>
#define N 5
int somaDiagonal(int matriz[N][N]);
void exibir(int m[N][N]);
void main()
{
	int retorno;
	int matriz[N][N] = {{6, 3, 1, 2, 6},
						{1, 3, 5, 4, 2},
						{3, 4, 4, 2, 2},
						{5, 9, 1, 9, 3},
						{4, 0, 2, 1, 8}};
	exibir(matriz); //exibindo a matriz original
	
	//chamando a fun��o
	retorno = somaDiagonal(matriz);
	
	//verificando retorno e exibindo o resultado
	if(retorno == 1)
	{
		printf("\nSoma dos elementos OK.");
	}
	else
	{
		printf("\nNao atende ao requisito.");
	}
}
int somaDiagonal(int matriz[N][N])
{
	int i, j, somaDiagonal=0, somaCima=0, somaBaixo=0;
	
	//percorrendo as linhas da matriz
	for(i=0; i<N; i++)
	{
		//percorrendo as colunas da matriz
		for(j=0; j<N; j++)
		{
			//verificando os elementos da diagonal, para somar
			if(i == j)
			{
				//somando os elementos da diagonal principal
				somaDiagonal += matriz[i][j];
			}
			else
			{
				if(i > j)
				{
					//somando os elementos da parte de cima da matriz
					somaCima += matriz[i][j];
				}
				else
				{
					somaBaixo += matriz[i][j];
				}
			}
		}
	}
	//verificando se a soma dos elementos de acima e abaixo da diagonal � igual � diagonal principal
	if((somaCima == somaDiagonal) && (somaBaixo == somaDiagonal))
	{
		return 1; //retornando 1 pois atende ao requisito
	}
	else
	{
		return 0; //retornando 0 pois nao atende
	}
}
void exibir(int m[N][N])
{
	int i, j;
	
	printf("Matriz ORIGINAL: \n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
