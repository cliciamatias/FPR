/*Questão 10:
Implementar uma função recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorrências de ch,
retornando o total de remoções realizadas.*/
#include <stdio.h>
#include <string.h>
int removeCaractereRecursivo(char str[], char ch, int i);
void main()
{
    char str[] = "banana";
    char ch = 'a';
    int totalRemovido = removeCaractereRecursivo(str, ch, 0); //chamando a função

    printf("Total de remocoes: %d\n", totalRemovido); //exibindo o resultado
}
int removeCaractereRecursivo(char str[], char ch, int i)
{
	//verificando se a string é vazia
    if(str[i] == '\0')
	{
        return 0; //caso base: a string está vazia.
    } 
	else 
	{
		//verificando se a string tem o caracter escolhido
        if(str[i] == ch)
		{
			//chamando a função recursiva somando de 1 para contar as remoções
            return 1 + removeCaractereRecursivo(str, ch, i+1);
        } 
		else 
		{ 
            return removeCaractereRecursivo(str + 1, ch, i);
        }
    }
}
