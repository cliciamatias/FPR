/*Quest�o 02:
Implementar uma fun��o que, dadas duas
strings s1 e s2, crie uma nova string � s3 �
contendo todos os caracteres de s1 que n�o
estejam em s2.
Nota: em s3, n�o devem existir caracteres
repetidos.*/
#include <stdio.h>
#define QUANT 20
void caracterS3(char s1[], char s2[], char s3[]);
void main()
{
	char string1[QUANT] = "nova";
	char string2[QUANT] = "palavra";
	char string3[QUANT]; //no
	
	printf("\ns1: %s", string1);
	printf("\ns2: %s", string2);
	//chamando a fun��o
	caracterS3(string1, string2, string3);
	printf("\ns3: %s", string3);
}
void caracterS3(char s1[], char s2[], char s3[])
{
	int i, j, encontrou;
	int p=0; //posi��es de 's3'
	
	//inicializando 's3' vazia
	s3[0] = '\0';
	
	//percorrendo a string 1
	for(i=0; s1[i]; i++)
	{
		encontrou = 0; //'encontrou' para indicar se o caractere foi encontrado em 's2'
		//percorrendo as posi��es da string 2
		for(j=0; s2[j]; j++)
		{
			//se o elemento de s1 � igual ao de s2(na posi��o j, comparando �s letras de s1[i])
			if(s1[i] == s2[j])
			{
				encontrou = 1;
			}
		}
		//caracteres de 's1' n�o for encontrado em 's2', passar caracteres de 's1' para 's3'
		if(!encontrou)
		{
			s3[p++] = s1[i];
		}
	}
	//encerrando 's3' com o caractere nulo
    s3[p] = '\0';
}
