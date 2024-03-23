/*Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.*/
#include <stdio.h>
#include <string.h>

int palindromo(char s[]);
void main()
{
        char s[20] = "ala"; //EH palindromo
        int retorno = palindromo(s); //chamando a função

        //verificando o retorno e exibindo o resultado
        if(retorno == 1)
        {
                printf("'%s' EH palindromo.", s);
        }
        else
        {
                printf("'%s' NAO eh palindromo.", s);
        }
}
int palindromo(char s[])
{
        int i, j;

		//começando 'i' com o incio da string e 'j' com o seu final e comparando cada letra até o seu meio (i<j)
        for(i=0, j=strlen(s)-1; i<j; i++,j--)
        {
            //verificando se o ultimo caracter é igual ao primeiro e assim por diante
            if(s[i] != s[j])
            {
				return 0; //retornando '0' pois se os caracteres não forem iguais não é um palindromo
            }
        }return 1; //retornando '1' pois eh palindromo
        
        
        //-------------OUTRO MÉTODO QUE TAMBÉM FUNCIONA-----------------
        
        //percorrendo a string 's'
    	/*for(i=0; s[i]; i++)
        {
                //verificando se o ultimo caracter é igual ao primeiro e assim por diante
                if(s[i] != s[tamanho-i-1])
                {
                        return 0; //retornando '0' pois se os caracteres não forem iguais não é um palindromo
                }
        }
        return 1;*/ //retornando 1, pois se saiu do for é palindromo
}
/*
#include <stdio.h>
#include <string.h>
int palindromo(char s[]);
void main()
{
        char s[20] = "osso";
        int retorno = palindromo(s); //chmando a funcao
        
        if(retorno == 1)
        {
                printf("'%s' eh palindromo.\n", s);
        }
        else
        {
                printf("'%s' nao eh palindromo.", s);
        }
}
int palindromo(char s[])
{
        int i, tamanho=strlen(s);
        
        //percorendo a string até a sua matade, pois é espelhado se da direita ou esquerda forem os mesmos caracteres
        for(i=0; i<tamanho/2; i++)
        {
                //verificando se a string é a mesma de trás para frente
                if(s[i] != s[tamanho-i-1]) 
                {
                   return 0; //retornando '0' pois se os caracteres não forem iguais não é um palindromo
        }
        }
        return 1; //retornando 1, pois se saiu do for é palindromo
}
*/
