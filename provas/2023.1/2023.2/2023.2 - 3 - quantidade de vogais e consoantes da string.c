/*Quest�o 03 [2,5 pontos]:
Fazer uma fun��o que, dada uma string contendo
apenas letras e separadores (espa�os, v�rgulas, pontos,
etc.), crie um vetor de structs no qual cada posi��o
conter�: uma palavra da string, a quantidade de vogais
e a quantidade de consoantes nesta palavra.
Exemplo:
S = �FUNDAMENTOS DE PROGRAMACAO�

palavras - FUNDAMENTOS DE PROGRAMACAO
vogais -       4       1      5
consoantes -   7       1      6
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char palavra[50];
    int vogais;
    int consoantes;
} Palavra;

int ehVogal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int ehConsoante(char c) {
    return isalpha(c) && !ehVogal(c);
}

void contarVogaisEConsoantes(char* str, Palavra palavras[], int* numPalavras) {
	int i;
    char* token = strtok(str, " ");
    while (token != NULL) {
        strcpy(palavras[*numPalavras].palavra, token);
        palavras[*numPalavras].vogais = 0;
        palavras[*numPalavras].consoantes = 0;
        for ( i = 0; i < strlen(token); i++) {
            if (ehVogal(token[i])) {
                palavras[*numPalavras].vogais++;
            } else if (ehConsoante(token[i])) {
                palavras[*numPalavras].consoantes++;
            }
        }
        (*numPalavras)++;
        token = strtok(NULL, " ");
    }
}

int main() {
    char str[] = "FUNDAMENTOS DE PROGRAMACAO";
    Palavra palavras[50];
    int numPalavras = 0, i;

    contarVogaisEConsoantes(str, palavras, &numPalavras);

    for (i = 0; i < numPalavras; i++) {
        printf("Palavra: %s, Vogais: %d, Consoantes: %d\n", palavras[i].palavra, palavras[i].vogais, palavras[i].consoantes);
    }

    return 0;
}















/*
#include <stdio.h>
#include <string.h>
#define TAM 40
typedef struct
{
	char palavra[40]; 
	int vogal;
	int consoante;
} TPalavra;

// Fun��o para dividir a string em palavras e armazen�-las na estrutura
void quantidade(char s[], TPalavra string[])
{
	int i, j = 0, k = 0; //i � o �ndice para a string s, j � o �ndice para uma palavra, e k � o �ndice para o vetor de estruturas

    //percorrendo a string 's'
    for(i = 0; s[i] != '\0'; i++)
	{
        //verificando se h� espa�o, uma nova linha ou o fim da string, para separar a palavra
        if(s[i] == ' ' || s[i] == '\n' || s[i+1] == '\0')
		{
            //verificando se j > 0, para armazenar a palavra
            if(j > 0)
			{
				
                if(s[i+1] == '\0') // Verifica se o pr�ximo caractere na string s � o caractere nulo '\0', que indica o final da string
				{
				    string[k].palavra[j] = s[i]; // Se for verdade, isso significa que estamos no �ltimo caractere da �ltima palavra na string s. Portanto, ele adiciona esse �ltimo caractere � palavra atual na estrutura string[k]
				    j++; // Incrementa o �ndice j para a pr�xima posi��o na palavra
				}
                
                //adicionando um caractere nulo ao final da palavra e exibindo
                string[k].palavra[j] = '\0';
                printf("%s\n", string[k].palavra);
                
                //reiniciando j com 0 e incrementando k para a pr�xima palavra
                j = 0;
                k++;
            }
        } else
		{
            //se n�o � um espa�o ou uma nova linha, ent�o � um caractere de uma palavra, ent�o o adiciona � palavra atual
            string[k].palavra[j] = s[i];
            j++;
        }
    }
}

// Fun��o principal que define a string e chama a fun��o quantidade
void main()
{
	char s[TAM] = "fundamentos de programacao aqui"; // A string que queremos dividir em palavras
	TPalavra string[40]; // O vetor de estruturas para armazenar as palavras
	
	// Chamando a fun��o quantidade para dividir a string em palavras e armazen�-las na estrutura
	quantidade(s,string);
}*/
