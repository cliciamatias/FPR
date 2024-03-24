/*QUESTÃO 04:
Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica.*/
#include <stdio.h>
void preencherMatriz(int lc, int m[lc][lc]);
void main()
{
	int lc=6, retorno;
	int m[lc][lc];
	
	preencherMatriz(lc,m); //exibindo a matriz
	retorno = simetrica(lc,m); //chamando a função que verifica se é simétrica ou não
	
	if(retorno == 1)
	{
		printf("\nEh uma matriz simetrica.");
	}					
	else
	{
		printf("\nNAO eh uma matriz simetrica.");
	}
}

int simetrica(int lc, int m[lc][lc])
{
	int i, j;
	
	//percorrendo as linhas da matriz
	for(i=0; i<lc; i++)
	{
		//percorrendo as colunas da matriz
		for(j=0; j<lc; j++)
		{
			//verificando se seus opostos sao diferentes, pois se houver algum já não será simétrica
			if(m[i][j] != m[j][i])
			{
				return 0; //a matriz não é simétrica
			}
		}
	}
	return 1; //a matriz é simétrica
}

void preencherMatriz(int lc, int m[lc][lc])
{
	int i, j;
	srand(time(NULL));
	for(i=0; i<lc; i++)
	{
		for(j=0; j<lc; j++)
		{
			m[i][j] = rand()%9;
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}



//------------------------------------------------------------------
/*QUESTÃO 04:
Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica.*/
/*
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
	
	//chamando a função
	retorno = matrizSimetrica(n,matriz);
	
	//verificando o retorno da função
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
			//verificando se elementos 'espelhados'(inverso de linhas e colunas) da matriz são difetentes
			if(m[i][j] != m[j][i])
			{
				return 0;  //retornando 0, pois há elemento diferentes no espelhamento da matriz
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
}*/
