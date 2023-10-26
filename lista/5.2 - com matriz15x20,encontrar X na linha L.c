/*QUEST�O 02: 
Desenvolver uma fun��o que, dada uma matriz 
M15�20, determine se um n�mero X se encontra 
na linha L da matriz.*/
#include <stdio.h>
int encontrarXnaLinha(int lin, int col, int m[lin][col], int l, int x);
void preencherMatriz(int lin, int col, int matriz[lin][col]);
void main()
{
	int linha=15, coluna=20,numLinha, numX, retorno;
    int matriz[linha][coluna];
    
    //chamando a fun��o com a matriz preenchida
    preencherMatriz(linha, coluna, matriz);
	    
    //lendos o numero da linha e o valor a ser encontrado
    printf("\nDigite a linha (0 a 14): ");
    scanf("%d", &numLinha);
    printf("\nDigite o numero X a ser encontrado na linha %d: ", numLinha);
    scanf("%d", &numX);
    
    //chamando a fun��o
	retorno= encontrarXnaLinha(linha,coluna,matriz,numLinha,numX);
	
	//exibindo resultados do retorno da fun��o
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
        	//verificando se na linha escolhida h� o numero X a ser encontrado
            if(m[l][j]==x)
            {
            	//retornando 1, pois h� X na linha 
                return 1;
            }
        }
    }
    //retornando 0, pois se saiu do for, n�o h� o numero X na linha escolhida
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
        	//matriz recebendo os valores de 'num', come�ando por 1
            matriz[i][j]=num;
            num++; //incrementando num para ser uma matriz com valores crescentes
            //exibindo a matriz
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}
