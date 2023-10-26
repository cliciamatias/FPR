/*Quest�o 03:
Pede-se o desenvolvimento de uma fun��o recursiva que, dada uma matriz M de L linhas e C colunas, onde L e C s�o
constantes, e tr�s linhas L1, L2 e L3, altere os elementos de L3, de forma que cada um consista na soma dos elementos
de L1 e L2, conforme ilustrado no exemplo abaixo:*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define L 8
#define C 4

//prot�tipos das fun��es
void soma(int m[L][C], int l1, int l2, int l3, int col);
void exibirMatriz (int M[L][C]);

//main
void main ()
{
	int l1=1, l2=3, l3=6;
	int matriz[L][C] = {{1, 5, 9, 2},
	                    {0, 3, 4, 8}, //l1 0, 3, 4, 8
	                    {1, 1, 3, 7},
	                    {7, 9, 6, 5}, //l2 7, 9, 6, 5
	                    {1, 3, 2, 4},
	                    {8, 6, 8, 7},
	                    {9, 7, 2, 1}, //l3 7,12,10,13
	                    {4, 6, 7, 8}};

	//exibindo a matriz antes da chamada � fun��o
	exibirMatriz (matriz);
	
	//chamandao a fun��o
	soma(matriz,l1, l2, l3, 0);
	
	//exibindo a matriz ap�s a chamada � fun��o
	exibirMatriz (matriz);
}	
//implementa��o das fun��es
void soma(int m[L][C], int l1, int l2, int l3, int col)
{
	//verificando se a coluna (come�a com 0, para percorrer cada coluna da linha) � menor que a coluna da matriz (4)
	if(col < C) //percorrendo de 0 a 3 (colunas da matriz)
	{
		//linha de 'l3' recebendo soma de 'l1' e 'l2'
		m[l3][col] = m[l1][col] + m[l2][col];
		
		//chamando a fun��o recursiva, e 'col+1' "andando" com cada coluna da matriz 
		soma(m, l1, l2, l3, col+1);
	}
}
void exibirMatriz (int M[L][C])
{
	//declara��o de vari�veis
	int i, j;
	
	printf ("Elementos da matriz:\n\n");	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%3d ", M[i][j]);
		}
		
		printf ("\n");
	}
	printf ("\n\n");
}
