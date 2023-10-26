/*Questão 02 [2,5 pontos]:
Desenvolver uma função recursiva que, dada uma
string s, altere-a de forma que as letras fiquem em
seu início e os demais caracteres ao final, como nos
exemplos a seguir:
Exemplo 1:
Inicialmente: X*7D2SFH1
Ao final: XHFDS27*1

Exemplo 2:
Inicialmente: 1SUG47EFG
Ao final: GSUGFE741
Nota:
Para testar se determinado caracter de uma
string s é uma letra, pode-se utilizar a
seguinte expressão:
if ((toupper(s[i]) >= ‘A’) && (toupper(s[i]) <= ‘Z’))*/
#include <stdio.h>
#include <string.h>
void recursiva(char s[], int i, int inicio, int fim)
{
	char aux;
	
	if(inicio >= fim)
	{
		return;
	}
	if((s[i] >= 'a') && (s[i] <= 'z')) //caso base: ser letra
	{
		printf("%c ", s[inicio]);
		aux = s[inicio];
		s[inicio] = inicio;
		s[fim] = aux;
		i++;
		fim--;
	}
}
void main()
{
	char s[30] = ";de!89oisd";
	int tam = strlen(s);
	recursiva(s, 0, 0, tam-1);
}
