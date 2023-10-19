/*Quest�o 09:
Desenvolver uma fun��o recursiva que, dado
um vetor V com quant n�meros inteiros,
determine se seus elementos est�o dispostos
de maneira a representar uma progress�o
aritm�tica.*/
#include <stdio.h>
int vetorPA(int v[], int i, int q);
void main()
{
	int vetor[5] = {1, 5, 9, 13, 17}; //a1=1 ; razao=4
	int q=4;
	
	//verificando o retorno da fun��o, se o vetor � uma PA, com o vetor, a posi��o come�ando com 0 e 'q' a raz�o da PA
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
	//verificando se o elemento ap�s o anterior � igual � razao, pois ser� uma PA
	if((v[i+1] - v[i]) == q)
	{	
		vetorPA(v, i+1, q); //chamando a fun��o recursiva com o vetor, 'i+1' para verificar cada posi��o e 'q' a raz�o constante
		return 1; // retornando 1, pois � um vetor de PA
	}
	else
	{
		return 0; //retornando 0, pois n�o eh um vetor de PA
	}
}
