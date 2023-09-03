/*QUESTÃO 02: 
Desenvolver uma função que, dada uma matriz 
M15×20, determine se um número X se encontra 
na linha L da matriz.*/
#include <stdio.h>
int encontrarXnaLinha(int lin, int col, int m[lin][col], int l, int x);
void main()
{
	int i, j, num=1, linha=15, coluna=20,numLinha, numX, retorno;
    int matriz[linha][coluna];
    
    //preenchendo a matriz com valores crescentes
    for(i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            matriz[i][j]=num;
            num++;
            //exibindo a matriz
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
    //lendos o numero da linha e o valor a ser encontrado
    printf("\nDigite a linha: ");
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
    
    for(i=0; i<lin; i++)
    {
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
