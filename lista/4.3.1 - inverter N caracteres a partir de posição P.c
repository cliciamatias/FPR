/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 21/03/2024
   
   Strings:
   
   Exercício 2: dada uma string s, implementar uma função que inverta n 
   caracteres a partir da posição p.
   
   Observações:
   	- Caso p seja inválido, a função deverá retornar 0;
   	- Caso não existam n caracteres a partir da posição p, a função deverá
   	  inverter os caracteres da posição p à última posição da string.
   	- Caso a inversão seja possível, o valor 1 será retornado.
*/
#include <stdio.h>
#include<string.h>
void main()		//algotirmo
{			//    012345678
	char s[20] = "algoritmo";
	int p=4, n=3;
	
	printf("A string: %s.\n\n", s);
	
	int retorno = inverter(s, p, n); //chamando a função
	
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
	
	//verificando se 'p' é inválido, para retornar 0
	if((p < 0) || (p >= tam) || (n <= 0))
	{
		return 0;
	}
	
	//determinando a posição final da troca
	if (n+p-1 < tam-1)
	{
		posicao = n+p-1;
	}
	else
	{
		posicao = tam-1;
	}
	
	//percorrendo a string pra fazer a troca a partir de 'p' até à última posição com 'i' sendo o inicio e 'j' o final da troca
	for(i=p, j=posicao; i < j; i++, j--)
	{
		//fazendo a troca
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
		
	}
}
