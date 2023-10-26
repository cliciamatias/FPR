/*QUESTÃO 01:
Faça uma função que, dada uma matriz M8×5 de
reais, gere a matriz Mt, sua transposta.*/
#include <stdio.h>
void transposta(float m[8][5], float mT[5][8]);
void main()
{
	int i, j;
	float mT[5][8];
	float m[8][5] =	{{1.0, 2.0, 3.0, 4.0, 5.0},
				     	{6.0, 7.0, 8.0, 9.0, 10.0},
				     	{11.0, 12.0, 13.0, 14.0, 15.0},
				     	{16.0, 17.0, 18.0, 19.0, 20.0},
				     	{21.0, 22.0, 23.0, 24.0, 25.0},
				     	{26.0, 27.0, 28.0, 29.0, 30.0},
				    	{31.0, 32.0, 33.0, 34.0, 35.0},
				    	{36.0, 37.0, 38.0, 39.0, 40.0}};
	
	printf("Matriz original:\n");	
	
	for(i=0; i<8; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%.0f ", m[i][j]);
		}
		printf("\n");
	}
	
	transposta(m, mT);
	printf("\n\nMatriz transposta:\n");
	for(i=0; i<5; i++)
	{
		for(j=0; j<8; j++)
		{
			printf("%.0f ", mT[i][j]);
		}
		printf("\n");
	}    	
}
void transposta(float m[8][5], float mT[5][8])
{
	int i, j;
	
	//percorrendo as linhas da matriz
	for(i=0; i<8; i++)
	{
		//percorrendo as colunas da matriz
		for(j=0; j<5; j++)
		{
			//atribindo a transposta na matriz (inverso das linhas e colunas)
			mT[j][i] = m[i][j];
		}
	}
}


/*
#include <stdio.h>
void matrizTransposta(float matriz[8][5], float matrizT[5][8]);
void main()
{
	int i, j;
	float matrizT[5][8];
	float matriz[8][5]={{1.0, 2.0, 3.0, 4.0, 5.0},
				        {6.0, 7.0, 8.0, 9.0, 10.0},
				        {11.0, 12.0, 13.0, 14.0, 15.0},
				        {16.0, 17.0, 18.0, 19.0, 20.0},
				        {21.0, 22.0, 23.0, 24.0, 25.0},
				        {26.0, 27.0, 28.0, 29.0, 30.0},
				        {31.0, 32.0, 33.0, 34.0, 35.0},
				        {36.0, 37.0, 38.0, 39.0, 40.0}};
				        
	printf("Matriz ORIGINAL: \n");
	for(i=0; i<8; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%.0f ", matriz[i][j]);
		}
		printf("\n");
	}
	//chamando a função
	matrizTransposta(matriz, matrizT);
	
	printf("\n\nMatriz TRANSPOSTA: \n");
	for(i=0; i<5; i++)
	{
		for(j=0; j<8; j++)
		{
			printf("%.0f ", matrizT[i][j]);
		}
		printf("\n");
	}
}
void matrizTransposta(float matriz[8][5], float matrizT[5][8])
{
	int i, j;
	
	//percorrendo as colunas
	for(i=0; i<8; i++)
	{
		//percorrendo as linhas
		for(j=0; j<5; j++)
		{
			//matriz transposta recebendo o inverso das posicoes de linhas e colunas
			matrizT[j][i] = matriz[i][j];
		}
	}
}
*/
