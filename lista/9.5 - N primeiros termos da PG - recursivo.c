/*Questão 05:
Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.
Observação: uma PG consiste em uma
sequência de valores, iniciadas pelo valor a1. Os
demais elementos são definidos como o
anterior multiplicado pela razão.*/
#include <stdio.h>
void exibirPG(int a1, int q, int n);
void main()
{
	int n=10, a1=3, q=3;
	exibirPG(a1, q, n);
}
void exibirPG(int a1, int q, int n)
{
	//se a quantidade de termos for maior que 0, exibir e executar a função
	if(n > 0)
	{
		//exibindo o atual termo da PG
		printf("%d ", a1);
		//chamada recursiva da função com o próximo termo e 'n-1'
		exibirPG(a1*q, q, n-1);
	}
}
