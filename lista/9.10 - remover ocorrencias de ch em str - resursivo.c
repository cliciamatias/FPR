/*Quest�o 10:
Implementar uma fun��o recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorr�ncias de ch,
retornando o total de remo��es realizadas.*/
#include <stdio.h>
#include <string.h>
int removeCaractereRecursivo(char str[], char ch, int i);
void main()
{
    char str[] = "banana";
    char ch = 'a';
    int totalRemovido = removeCaractereRecursivo(str, ch, 0); //chamando a fun��o

    printf("Total de remocoes: %d\n", totalRemovido); //exibindo o resultado
}
int removeCaractereRecursivo(char str[], char ch, int i)
{
	//verificando se a string � vazia
    if(str[i] == '\0')
	{
        return 0; //caso base: a string est� vazia.
    } 
	else 
	{
		//verificando se a string tem o caracter escolhido
        if(str[i] == ch)
		{
			//chamando a fun��o recursiva somando de 1 para contar as remo��es
            return 1 + removeCaractereRecursivo(str, ch, i+1);
        } 
		else 
		{ 
            return removeCaractereRecursivo(str + 1, ch, i);
        }
    }
}
