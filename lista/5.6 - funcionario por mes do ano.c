/*QUESTÃO 06:
Considere uma loja que mantém em uma
matriz o total vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas
(10 funcionários). Pede-se o desenvolvimento
de uma função para cada item abaixo:
a. Calcular o total vendido durante o ano;
b. Dado um mês fornecido pelo usuário, 
determinar o total vendido nesse mês;
c. Dado um funcionário fornecido pelo usuário, 
determinar o total vendido por ele durante o ano;
d. Determinar o mês com maior índice de vendas;
e. Determinar o funcionário que menos vendeu durante o ano.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherAleatorio(int lin, int col, int m[lin][col]);
void exibirMatriz(int lin, int col, int m[lin][col]);
int totalVendaAno(int lin, int col, int matriz[lin][col]);
int totalVendaMes(int lin, int col, int matriz[lin][col], int mes);
int totalFuncAno(int lin, int col, int matriz[lin][col], int func);
int indiceMaiorVendaMes(int lin, int col, int m[lin][col]);
int funcMenorVenda(int lin, int col, int m[lin][col]);

void main()
{
	int linha=12, coluna=10;
	int matriz[linha][coluna];
	int totalVendidoAno, mes, totalVendidoMes, funcionario, totalFunc;
	int maiorMes, menorVenda;
	
	//exibindo a matriz de vendas ao ano
	preencherAleatorio(linha,coluna,matriz);
	exibirMatriz(linha,coluna,matriz);
	
	totalVendidoAno = totalVendaAno(linha,coluna,matriz);
	printf("\nTotal vendido durante o ano: %d.", totalVendidoAno);
	
	printf("\n\nDigite um mes para verificar o total de vendas: ");
	scanf("%d", &mes);
	
	totalVendidoMes = totalVendaMes(linha,coluna,matriz,mes);
	printf("  ===> Total vendido no mes %d: %d.",mes, totalVendidoMes);
	
	printf("\n\nDigite a coluna(funcionario) que deseja verificar as vendas: ");
	scanf("%d", &funcionario);
	
	totalFunc = totalFuncAno(linha,coluna,matriz, funcionario);
	printf("  ===> Total vendido pelo funcionario %d: %d.\n\n",funcionario, totalFunc);
	
    maiorMes = indiceMaiorVendaMes(linha,coluna,matriz); //exibindo numeros ????
	printf("\n\nO mes com maior indice de vendas: %d.", maiorMes);
	
	menorVenda = funcMenorVenda(linha,coluna,matriz);
	printf("\n\nO funcionário que menos vendeu durante o ano: %d.", menorVenda);
}
//Determinar o funcionário que menos vendeu durante o ano
int funcMenorVenda(int lin, int col, int m[lin][col])
{
    int j, total, menor=99, menorFunc=99;
    
    for(j=0; j<col; j++)
    {
    	total = totalFuncAno(lin,col,m,j+1);
    	if(total < menor)
    	{
    		menor = total;
    		menorFunc = j+1;
    	}
    }
    return menorFunc;
}
//função que determina o mês com maior índice de vendas
int indiceMaiorVendaMes(int lin, int col, int m[lin][col])
{
    int i, maior=0, total, maiorMes=0;
    
    //percorrendo as linhas (mês)
    for(i=0; i<lin; i++)
    {
        total = totalVendaMes(lin,col,m, i+1);
        if(total > maior)
        {
            maior = total; 
            maiorMes = i+1;
        }
    }
    return maiorMes;
}
//dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano
int totalFuncAno(int lin, int col, int matriz[lin][col], int func)
{
	int i, total=0;
	
    func--; //transformando o nunero de funcionários de 0 a 9 para 1 a 10
	for(i=0; i<lin; i++)
	{
		//somando todas os valores da coluna(funcionário) escolhido
		total += matriz[i][func];
		printf("|%d| ", matriz[i][func]);
	}
	return total;
}
//Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês
int totalVendaMes(int lin, int col, int matriz[lin][col], int mes)
{
	int j, total=0;
    
	mes--;//convertendo mes de 0 a 11 para 1 a 10
	//percorrendo as colunas da matriz
	for(j=0; j<col; j++)
	{
		//somando todos os valores da linha escolhida(mes)
		total += matriz[mes][j];
		//exibindo a linha (mês) da matriz escolhido pelo usuário
		printf("|%d| ", matriz[mes][j]);
	}
	return total;
}
//Calcular o total vendido durante o ano
int totalVendaAno(int lin, int col, int matriz[lin][col])
{
	int i, j, total=0;
	
	//percorrendo as linhas da matiz
	for(i=0; i<lin; i++)
	{
		//percorrendo as colunas da matriz
		for(j=0; j<col; j++)
		{
			//somando todos os valores da matriz
			total += matriz[i][j];
		}
	}
	return total;
}
void preencherAleatorio(int lin, int col, int m[lin][col])
{
	int i, j;
	
	srand(time(NULL));
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			m[i][j] = rand()%5;
		}
	}
}
void exibirMatriz(int lin, int col, int m[lin][col])
{
	int i, j;
	
	printf("Matriz ORIGINAL: \n");
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("|%d| ", m[i][j]);
		}
		printf("\n");
	}
}
