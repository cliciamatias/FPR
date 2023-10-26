/*Questão 03 [2,5 pontos]:
Fazer uma função que, dada uma string contendo
apenas letras e separadores (espaços, vírgulas, pontos,
etc.), crie um vetor de structs no qual cada posição
conterá: uma palavra da string, a quantidade de vogais
e a quantidade de consoantes nesta palavra.
Exemplo:
S = “FUNDAMENTOS DE PROGRAMACAO”

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

// Função para dividir a string em palavras e armazená-las na estrutura
void quantidade(char s[], TPalavra string[])
{
	int i, j = 0, k = 0; //i é o índice para a string s, j é o índice para uma palavra, e k é o índice para o vetor de estruturas

    //percorrendo a string 's'
    for(i = 0; s[i] != '\0'; i++)
	{
        //verificando se há espaço, uma nova linha ou o fim da string, para separar a palavra
        if(s[i] == ' ' || s[i] == '\n' || s[i+1] == '\0')
		{
            //verificando se j > 0, para armazenar a palavra
            if(j > 0)
			{
				
                if(s[i+1] == '\0') // Verifica se o próximo caractere na string s é o caractere nulo '\0', que indica o final da string
				{
				    string[k].palavra[j] = s[i]; // Se for verdade, isso significa que estamos no último caractere da última palavra na string s. Portanto, ele adiciona esse último caractere à palavra atual na estrutura string[k]
				    j++; // Incrementa o índice j para a próxima posição na palavra
				}
                
                //adicionando um caractere nulo ao final da palavra e exibindo
                string[k].palavra[j] = '\0';
                printf("%s\n", string[k].palavra);
                
                //reiniciando j com 0 e incrementando k para a próxima palavra
                j = 0;
                k++;
            }
        } else
		{
            //se não é um espaço ou uma nova linha, então é um caractere de uma palavra, então o adiciona à palavra atual
            string[k].palavra[j] = s[i];
            j++;
        }
    }
}

// Função principal que define a string e chama a função quantidade
void main()
{
	char s[TAM] = "fundamentos de programacao aqui"; // A string que queremos dividir em palavras
	TPalavra string[40]; // O vetor de estruturas para armazenar as palavras
	
	// Chamando a função quantidade para dividir a string em palavras e armazená-las na estrutura
	quantidade(s,string);
}*/
