/* FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Aula de 21/03/2024
   
   Strings:
   
   Exerc�cio 3: desenvolver uma fun��o que remova todas as ocorr�ncias de um
   determinado caracter de uma string s.
   
   Observa��o: retornar o n�mero de remo��es realizadas.
*/
//importa��o de bibliotecas
#include <stdio.h>

//Prot�tipos das fun��es
int removerCaracteres (char s[], char letra);

//main
void main ()
{
	//declara��o de vari�veis
	char s[20], letra;
	int ret;
	
	//lendo uma string para s
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (s);
	
	//Obtendo o caracter a ser removido
	printf ("\nEntre com o caracter a ser removido: ");
	fflush (stdin);
	scanf ("%c", &letra);
	
	//chamando a fun��o
	ret = removerCaracteres (s, letra);
	
	//testando o retorno e exibindo a mensagem
	if (ret == 0)
	{
		printf ("\nNenhuma remocao realizada!\n", s);
	}
	else
	{
		printf ("\nForam feitas '%d' remocoes do caracter '%c'!\n", ret, letra);
		printf ("Novo conteudo da string: %s\n", s);
	}
}
//implementa��o das fun��es
int removerCaracteres (char s[], char letra)
{
	int i, j, cont=0;
	
	//percorrendo a string 
	for(i=0; s[i]; i++)
	{
		//verificando se h� a letra na string para remover
		if(s[i] == letra)
		{
			//removendo as letras e "andando os caracteres"
			for(j=i; s[j]; j++)
			{
				s[j] = s[j+1];
			}
			cont++; //contando a quantidade de letras a serem removidas na string
		}
	}
	return cont; //retornando quantidade de letras removidas
}
