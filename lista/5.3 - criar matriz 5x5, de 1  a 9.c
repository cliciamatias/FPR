/*QUESTÃO 03:
Desenvolver uma função que gere a seguinte
matriz M5x5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9*/
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
