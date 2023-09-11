/*Questão 01:
Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o no de linhas e o no de colunas são iguais a
N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
o valor 0 deverá ser retornado):
- A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
diagonal, assim como à soma dos elementos abaixo da diagonal.*/
#include <stdio.h>
#define N 5
void exibirMatriz(int m[N][N]);

void main()
{
	int retorno;
	int matriz[N][N] = {{6, 3, 1, 2, 6},
						{1, 3, 5, 4, 2},
						{3, 4, 4, 2, 2},
						{5, 9, 1, 9, 3},
						{4, 0, 2, 1, 8}};
	//chamando função para exibir a matriz					
	exibirMatriz(matriz);
	
	//chamando a função com retorno
	retorno = somaElementos(matriz);
	if(retorno == 1)
	{
		printf("\nSoma dos elementos IGUAIS.");
	}
	else
	{
		printf("\nSoma dos elementos DIFERENTES.");
	}
	
}

int somaElementos(int m[N][N])
{
	int i, j, somaDiagonal=0, somaCima=0, somaBaixo=0;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i == j)
			{
				//somando os elementos que estão na diagonal principal
				somaDiagonal += m[i][j];
			}
			else
			{
				if(i > j)
				{
					//somando o elementos que estão acima da diagonal principal
					somaCima += m[i][j];
				}
				else
				{
					//somando o elementos que estão abaixo da diagonal principal
					somaBaixo += m[i][j];
				}
			}
		}
	}
	//verificando se a soma de cada uma sao iguais
	if((somaDiagonal == somaCima) && (somaDiagonal == somaBaixo))
	{
		return 1; //retornando 1, pois a soma dos elementos de todos são iguais
	}
	else
	{
		return 0; //retornando 0, pois a soma dos elementos de todos NÃO são iguais
	}
}

void exibirMatriz(int m[N][N])
{
	int i, j;
	
	printf("Matriz ORIGINAL: \n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("|%d| ", m[i][j]);
		}
		printf("\n");
	}
}
