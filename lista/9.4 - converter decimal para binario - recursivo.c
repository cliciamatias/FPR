/*Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).*/
#include <stdio.h>
void exibirBinario(int n);
void main()
{
	int n=5;
	
	printf("\n%d em binario: ", n);
	exibirBinario(n);
}
void exibirBinario(int n)
{
	if(n > 0)
	{
		exibirBinario(n/2);
		printf("%d", n%2);
	}
}
