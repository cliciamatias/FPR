/*Quest�o 05:
Pede-se a implementa��o de uma fun��o
recursiva que exiba os n primeiros termos de
uma PG (Progress�o Geom�trica), onde a1 � o
seu primeiro termo e q a raz�o.
Observa��o: uma PG consiste em uma
sequ�ncia de valores, iniciadas pelo valor a1. Os
demais elementos s�o definidos como o
anterior multiplicado pela raz�o.*/
#include <stdio.h>
void exibirPG(int a1, int q, int n);
void main()
{
	int n=10, a1=3, q=3;
	exibirPG(a1, q, n);
}
void exibirPG(int a1, int q, int n)
{
	//se a quantidade de termos for maior que 0, exibir e executar a fun��o
	if(n > 0)
	{
		//exibindo o atual termo da PG
		printf("%d ", a1);
		//chamada recursiva da fun��o com o pr�ximo termo e 'n-1'
		exibirPG(a1*q, q, n-1);
	}
}
