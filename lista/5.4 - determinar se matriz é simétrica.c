/*QUEST�O 04:
Fazer uma fun��o que, dada uma matriz M6�6,
determine se ela � sim�trica.*/
#include <stdio.h>
int matrizSimetrica(int n, int m[n][n]);
void exibir(int n, int m[n][n]);
void main()
{
	int n=3, retorno;
	int matriz[3][3]={{1,2,3},
					  {2,4,5},	
					  {3,5,6}};
	//exibindo a matriz
	exibir(n, matriz);	
	
	//chamando a fun��o
	retorno = matrizSimetrica(n,matriz);
	
	//verificando o retorno da fun��o
	if(retorno == 1)
	{
		printf("\nEssa matriz EH simetrica.");
	}
	else
	{
		printf("\nEssa matriz NAO EH simetrica.");
	}
}
int matrizSimetrica(int n, int m[n][n])
{
	int i, j;
	
	//percorrendo as linhas da matriz
	for(i=0; i<n; i++)
	{
		//percorrendo as colunas da matriz
		for(j=0; j<n; j++)
		{
			//verificando se elementos 'espelhados'(inverso de linhas e colunas) da matriz s�o difetentes
			if(m[i][j] != m[j][i])
			{
				return 0;  //retornando 0, pois h� elemento diferentes no espelhamento da matriz
			}
		}
	}
	return 1;
}
void exibir(int n, int m[n][n])
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}	
}
