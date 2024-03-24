/*QUESTÃO 02: 
Desenvolver uma função que, dada uma matriz 
M15×20, determine se um número X se encontra 
na linha L da matriz.*/
#include <stdio.h>
void preencherAleatorio(int lin, int col, int m[lin][col]);
int encontrarXnaLinha(int lin, int col, int m[lin][col], int numX, int numLin);
void main()
{
	int lin=15, col=20, numX=2, numLin=4;
	int m[lin][col];
	
	preencherAleatorio(lin,col,m);
	int retorno = encontrarXnaLinha(lin,col,m, numX, numLin); //chamando a função com a matriz
	
	//exibindo resultados do retorno da função
	if(retorno == 1)
	{
		printf("Ha o numero %d na linha %d", numX, numLin);
	}
	else 
    {
	    printf("NAO ha o numero %d na linha %d", numX, numLin);
    }
}

int encontrarXnaLinha(int lin, int col, int m[lin][col], int numX, int numLin)
{
	int j;
	
	//percorrendo apenas as colunas, pois o numero da linha já temos
	for(j=0; j<col; j++)
	{
		//verificando se na linhaX da matriz há o numero X
		if(m[numLin][j] == numX)
		{
			return 1; //reotrnando 1 pois encontrou
		}
	}
	return 0; //retornando 0 pois não foi encontrado
}
//função para gerar uma matriz aleatorimente
void preencherAleatorio(int lin, int col, int m[lin][col])
{
	int i, j;
	srand(time(NULL));
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			m[i][j] = rand()%5;
			printf(" |%d|", m[i][j]);
		}
		printf("\n");
	}
}





























/*QUESTÃO 02: 
Desenvolver uma função que, dada uma matriz 
M15×20, determine se um número X se encontra 
na linha L da matriz.*/
/*
#include <stdio.h>
int encontrarXnaLinha(int lin, int col, int m[lin][col], int l, int x);
void preencherMatriz(int lin, int col, int matriz[lin][col]);
void main()
{
	int linha=15, coluna=20,numLinha, numX, retorno;
    int matriz[linha][coluna];
    
    //chamando a função com a matriz preenchida
    preencherMatriz(linha, coluna, matriz);
	    
    //lendos o numero da linha e o valor a ser encontrado
    printf("\nDigite a linha (0 a 14): ");
    scanf("%d", &numLinha);
    printf("\nDigite o numero X a ser encontrado na linha %d: ", numLinha);
    scanf("%d", &numX);
    
    //chamando a função
	retorno= encontrarXnaLinha(linha,coluna,matriz,numLinha,numX);
	
	//exibindo resultados do retorno da função
	if(retorno == 1)
	{
		printf("Ha este nunero na linha");
	}
	else 
    {
	    printf("NAO ha esta numero na linha");
    }
}   
int encontrarXnaLinha(int lin, int col, int m[lin][col], int l, int x)
{
    int i,j;
    
    //percorrendo a linha escolhida
    for(i=0; i<l; i++)
    {
    	//percorrendo as colunas desta linha
        for(j=0; j<col; j++)
        {
        	//verificando se na linha escolhida há o numero X a ser encontrado
            if(m[l][j]==x)
            {
            	//retornando 1, pois há X na linha 
                return 1;
            }
        }
    }
    //retornando 0, pois se saiu do for, não há o numero X na linha escolhida
    return 0;
}
void preencherMatriz(int lin, int col, int matriz[lin][col])
{
	int i, j, num=1;
	//preenchendo a matriz com valores crescentes
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
        	//matriz recebendo os valores de 'num', começando por 1
            matriz[i][j]=num;
            num++; //incrementando num para ser uma matriz com valores crescentes
            //exibindo a matriz
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}*/
