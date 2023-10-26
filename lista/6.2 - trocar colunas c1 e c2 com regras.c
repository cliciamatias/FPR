/*Quest�o 02:
Dada uma matriz MLxC, onde L e C s�o constantes, desenvolver uma fun��o que �troque� os elementos de duas colunas
c1 e c2, respeitadas as seguintes regras:
a. A troca s� ser� poss�vel se as colunas c1 e c2 existirem na matriz. Caso existam, a troca ser� realizada e o valor 1
retornado pela fun��o; por outro lado, 0 ser� retornado se uma ou as duas colunas forem inv�lidas;
b. Ap�s a troca, a coluna c2 conter� exatamente os elementos originais da coluna c1, na mesma ordem. Por�m, os
valores da coluna c1 ser�o os originais da c2, na ordem inversa.*/
#include <stdio.h>
#define L 6
#define C 5
void preencherAleatorio(int m[L][C]);
void exibirMatriz(int m[L][C]);
int trocarColunas(int m[L][C], int c1, int c2);
void main()
{
	int matriz[L][C], c1, c2, retorno;
	
	printf("Matriz ORIGINAL: \n");
	preencherAleatorio(matriz);
	exibirMatriz(matriz);
	
	printf("Digite a coluna c1 para trocar os elementos: ");
	scanf("%d", &c1);
	
	printf("Digite a coluna c2 para trocar os elementos: ");
	scanf("%d", &c2);
	
	//chamando a fun��o
	retorno = trocarColunas(matriz, c1, c2);
	if(retorno == 1)
	{
		printf("\nMatriz TROCADA: \n");
		exibirMatriz(matriz);
	}
	else
	{
		printf("\nColunas invalidas!");
	}
}
int trocarColunas(int m[L][C], int c1, int c2)
{
	int i, colAux;
	
	//verificando se as colunas escolhodas s�o v�lidas
	if((c1>=0 && c1<C) && (c2>=0 && c2<C))
	{
		//percorrendo as linhas da matriz
		for(i=0; i<L; i++)
		{
			//trocando os elementos das colunas (da coluna 1 para a coluna 2)
			colAux = m[i][c1];
			m[i][c1] = m[i][c2];
			m[i][c2] = colAux;
		}
		//invertendo at� a metade da coluna, para que a parte inferior fique em cima e a superior em baixo
		for(i=0; i<L/2; i++)
		{
			//invetendo os elementos da coluna c1(antigo c2)
			colAux = m[i][c1];
			m[i][c1] = m[L-1-i][c1]; //c1 recebendo o inverso de seus elementos(atrav�s das linhas)
			m[L-1-i][c1] = colAux; //efetuando a invers�o
		}
		return 1; //� valido a troca
	}
	else
	{
		return 0; //n�o � v�lido a troca
	}
}
void preencherAleatorio(int m[L][C])
{
	int i, j;
	
	srand(time(NULL));
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			m[i][j] = rand()%5;
		}
	}
}
void exibirMatriz(int m[L][C])
{
	int i, j;
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			printf("|%d| ", m[i][j]);
		}
		printf("\n");
	}
}
