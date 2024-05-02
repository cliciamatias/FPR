/*Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).*/
#include <stdio.h>
void recursivo(int n);
void main()
{
	int n=6;
	
	recursivo(n);
}
void recursivo(int n)
{
	if(n > 0) //CASO BASE - 'n' ser um valor maior que 0
	{
		recursivo(n/2); //dividindo 'n' por 2, para depois exibir o seu resto (binário)
		printf("%d", n%2); //exibindo o valor binário
	}
}


// -----------------------------------------------------------------------------------------------------------
/*Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).*/
/*
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
}*/
