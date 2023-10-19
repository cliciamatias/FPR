/*Questão 09:
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.*/
#include <stdio.h>
int vetorPA(int v[], int i, int q);
void main()
{
	int vetor[5] = {1, 5, 9, 13, 17}; //a1=1 ; razao=4
	int q=4;
	
	//verificando o retorno da função, se o vetor é uma PA, com o vetor, a posição começando com 0 e 'q' a razão da PA
	if(vetorPA(vetor, 0, q) == 1)
	{
		printf("Eh uma PA");
	}
	else
	{
		printf("Nao eh uma PA");
	}
}
int vetorPA(int v[], int i, int q)
{
	//verificando se o elemento após o anterior é igual à razao, pois será uma PA
	if((v[i+1] - v[i]) == q)
	{	
		vetorPA(v, i+1, q); //chamando a função recursiva com o vetor, 'i+1' para verificar cada posição e 'q' a razão constante
		return 1; // retornando 1, pois é um vetor de PA
	}
	else
	{
		return 0; //retornando 0, pois não eh um vetor de PA
	}
}
