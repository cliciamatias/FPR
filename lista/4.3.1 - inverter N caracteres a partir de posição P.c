/* FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Aula de 21/03/2024
   
   Strings:
   
   Exerc�cio 2: dada uma string s, implementar uma fun��o que inverta n 
   caracteres a partir da posi��o p.
   
   Observa��es:
   	- Caso p seja inv�lido, a fun��o dever� retornar 0;
   	- Caso n�o existam n caracteres a partir da posi��o p, a fun��o dever�
   	  inverter os caracteres da posi��o p � �ltima posi��o da string.
   	- Caso a invers�o seja poss�vel, o valor 1 ser� retornado.
*/
#include <stdio.h>
#include<string.h>
void main()		//algotirmo
{			//    012345678
	char s[20] = "algoritmo";
	int p=4, n=3;
	
	printf("A string: %s.\n\n", s);
	
	int retorno = inverter(s, p, n); //chamando a fun��o
	
	if(retorno == 0)
	{
		printf("A string '%s' eh invalida.", s);
	}
	else
	{
		printf("A string apos a inversao: %s.", s);
	}
}

int inverter(char s[], int p, int n)
{
	int i, j, tam = strlen(s), posicao;
	char aux;
	
	//verificando se 'p' � inv�lido, para retornar 0
	if((p < 0) || (p >= tam) || (n <= 0))
	{
		return 0;
	}
	
	//determinando a posi��o final da troca
	if (n+p-1 < tam-1)
	{
		posicao = n+p-1;
	}
	else
	{
		posicao = tam-1;
	}
	
	//percorrendo a string pra fazer a troca a partir de 'p' at� � �ltima posi��o com 'i' sendo o inicio e 'j' o final da troca
	for(i=p, j=posicao; i < j; i++, j--)
	{
		//fazendo a troca
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
		
	}
}
