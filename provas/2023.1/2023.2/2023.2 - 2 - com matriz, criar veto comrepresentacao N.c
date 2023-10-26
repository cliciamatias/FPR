/*Questão 02 [2,5 pontos]:
Dada uma matriz M de inteiros (de apenas um
algarismo), com x linhas e y colunas, desenvolver uma
função que crie um vetor V de x posições contendo, em
cada posição, as “representações numéricas” de cada
linha de M, como ilustrado no exemplo abaixo:
M = {1, 5, 9},
	{4, 2, 7},
	{4, 8, 8},
	{2, 5, 1},
	{7, 1, 1}};
V = |159| |427| |488| |251| |711|

verificar os valores da primeira coluna e multiplocar por 100
verificar os valores da segunda coluna e multiplocar por 10
e a ultima coluna será a unidade do vetor

*/
#include <stdio.h>
void numerica(int lin, int col, int m[lin][col], int v[]);
void main()
{
	int v[5], i;
	int lin=5, col=3;
	int m[5][3]= 	 {{1, 5, 9},
					  {4, 2, 7},
					  {4, 8, 8},
					  {2, 5, 1},
				      {7, 1, 1}};
	
	numerica(lin, col, m, v);
	for(i=0; i<5; i++)
	{
		printf("|%d| ", v[i]);
	}
}
void numerica(int lin, int col, int m[lin][col], int v[])
{
	int i, j;
	
	for(i=0; i<lin; i++) 
	{
		v[i] = 0; //inicializando o vetor
		for(j=0; j<col; j++)
		{
			v[i] = v[i] * 10 + m[i][j];
		}
       // v[i] = m[i][0] * 100 + m[i][1] * 10 + m[i][2]; (apenas casos com coluna igual a 3)
    }
}

