/*Quest�o 03:
Desenvolver uma fun��o recursiva que exiba
todos os m�ltiplos do n�mero N, inferiores ou
iguais ao valor V.*/
#include <stdio.h>
void exibirMultiplos(int n, int v, int i);
void main()
{
    int n, v;

    printf("Digite o n�mero N: ");
    scanf("%d", &n);

    printf("Digite o valor V: ");
    scanf("%d", &v);

    printf("\nMultiplos de %d inferiores ou iguais a %d:\n", n, v);
    exibirMultiplos(n, v, 0); //'i' s�o os multiplos, come�ando por 0
}
void exibirMultiplos(int n, int v, int i) 
{
	//verificando se o multiplo � menor ou igual a 'v'
    if(i <= v)
	{
		//verificando os multiplos de 'n'
        if(i % n == 0)
		{
			//exibindo o resultado
            printf("%d ", i);
        }
        exibirMultiplos(n, v, i + 1); //enquanto o multiplo de 'n' for <= 'v', soma 'i' com 1 para verificar se cada numero at� 'v' � multiplo
    }
}
