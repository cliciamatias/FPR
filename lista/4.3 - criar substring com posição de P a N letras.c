/*Quest�o 03:
Desenvolver uma fun��o que, dada uma string s, 
crie uma substring que inicie na posi��o p de
s e contenha n caracteres.
Observa��es: 
i) se p e/ou n forem inv�lidos, a substring ser� vazia; 
ii) se s n�o possuir n caracteres al�m de p, 
a substring a ser criada come�ar� em p e terminar� no final de s.*/
#include <stdio.h>
#include <string.h>
int substring(char s[], int p, int n);
void main()
{
	char s[30] = "algoritmo"; //substring = 'gori'
	int p=2, n=5;
	
	substring(s, p, n); //chamando a fun��o
}
int substring(char s[], int p, int n)
{
	int i, tamanho = strlen(s);
	//verificando se a string � inv�lida
	if((p < 0) || (p > tamanho) && (n < 0) || (n > tamanho))
	{
		s = 0; //'p' e/ou 'n' inv�lidos, ent�o string vazia
	}
	else
	{
		//percorrendo a string 's' come�ando com 'p' e termiando em 'n', caso 'n' seja maior que 's', ser� exibido a string at� o fim
		for(i=p; i<=n; i++)
		{
			printf("%c", s[i]); //exibinod a substring
		}
	}
}



/*#include<stdio.h>
#include<string.h>
void substring(char s[], int p, int num);
void main()
{                    //01234567
	char string[30];
	int posicao, caracteres;
	
	printf("Digite uma string: ");
	fflush(stdin);
	gets(string);
	
	printf("Digite a primeira posicao da string: ");
	scanf("%d", &posicao);
	
	printf("Digite a quantidade de caracteres da string: ");
	scanf("%d", &caracteres);
	
	substring(string, posicao, caracteres);
}
void substring(char s[], int p, int num)
{
	int i, tamanho=strlen(s);
	
/*	if((p < 0)||(p > tamanho))
	{
		s = 0;
	}
	else
	{
		if((num < 0)||(num > tamanho))
		{
			s = 0;
		}
	}
*/	
/*	i=p;
	while(i<=num+1)
	{	//exibindo a substring
		printf("%c", s[i]);
		i++;
	}
}*/
