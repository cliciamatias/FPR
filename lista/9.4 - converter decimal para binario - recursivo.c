/*Quest�o 04:
Fazer uma fun��o recursiva que, dado um
n�mero inteiro N, exiba o mesmo na base 2
(bin�ria).*/
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
