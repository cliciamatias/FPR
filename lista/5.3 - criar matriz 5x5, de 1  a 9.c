/*QUESTÃO 03:
Desenvolver uma função que gere a seguinte
matriz M5x5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9*/
#include <stdio.h>
void gerarMatriz(int lin, int col, int m[lin][col]);
void main()
{
	int lin=5, col=5;
	int m[lin][col];
	
	gerarMatriz(lin, col, m); //chamando a função
}
void gerarMatriz(int lin, int col, int m[lin][col])
{
	int i, j;
	
	//percorrendo as linhas da matriz, começando por 1 e indo até o 5
	for(i=1; i<=lin; i++)
	{
		//percorrendo as colunas da matriz, da primeira posição (0) à ultimma (5)
		for(j=0; j<col; j++)
		{
			//preenchendo a matriz com a soma de 'j' com 'i', pois ambos sao incrementados e um começa com 0 e outro com 1, 
			//fazendo com que retorno a matiz solicitada
			m[i][j] = j+i;
			printf(" %d", m[i][j]); //exibindo a matriz
		}
		printf("\n");
	}
}



























/*QUESTÃO 03:
Desenvolver uma função que gere a seguinte
matriz M5x5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9*/
/*
#include <stdio.h>
void matriz5x5(int lin, int col, int m[lin][col]);
void main()
{
	int linha=5, coluna=5;
	int matriz[linha][coluna];
	
	//chamando a função
	matriz5x5(linha,coluna,matriz);
}
void matriz5x5(int lin, int col, int m[lin][col])
{
	int i, j, cont=1;
	
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			//matriz percorrendo cada linha 'i'(1 a 5), com j+contador sendo somado de 1 em 1 cada coluna
			m[i][j] = j+cont;
			printf("%d ", m[i][j]);
		}
		//contando, para montar a matriz crescentemente
		cont++;
		printf("\n");
	}
}
*/
