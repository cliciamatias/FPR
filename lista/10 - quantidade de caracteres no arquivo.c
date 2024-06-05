/*Questão 01:
Desenvolver uma função que, dado um arquivo 
texto, verifique o número de caracteres no 
mesmo.*/
#include <stdio.h>
int quantCaracter(char nomeArq[]);
void main()
{
	char nomeArq[20];
	int quant;
	
	printf("Digite o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArq);
	
	quant = quantCaracter(nomeArq); //chamando a função
	
	//exibindo o resultado
	if(quant != -1)
	{
		printf("\n\nForam encontrados %d caracteres no arquivo %s", quant, nomeArq);
	}
	else
	{
		printf("\nErro na  abertura do arquivo %s.", nomeArq);
	}
}

int quantCaracter(char nomeArq[])
{
	FILE* arq; //1:criando uma variável do tipo FILE
	int cont=0;
	char caracter;
	
	arq = fopen(nomeArq, "r"); //tentando abrir o arquivo
	
	//verificando se houve erro ao abrir o arquivo
	if(!arq)
	{
		return -1; //se o arquivo não abrir, retornando -1
	}
	else
	{
		while(fscanf(arq, "%c", &caracter) != EOF) //lendo os caracteres enquanto nao chegar no final do arquivo
		{
			cont++; //contando os caracteres do arquivo
		}
		fclose(arq);
		return cont;
	}
	
}






// ------------------------------------------------------------------------
/*Questão 01:
Desenvolver uma função que, dado um arquivo 
texto, verifique o número de caracteres no 
mesmo.
#include<stdio.h>
void main()
{
    char nomeArq[30] = "questao1";
    int quant = quantCaracteres(nomeArq);
    
    printf("numero de caracteres no arquivo: %d", quant);
}
int quantCaracteres(char nomeArq[])
{
    int cont=0;
    char caracter;
    FILE* arquivo;
    
    arquivo = fopen(nomeArq, "r");
    if(arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo.");
    }
    else
    {
        while(fscanf(arquivo,"%c", &caracter) != EOF)
        {
            cont++;
        }
        fclose(arquivo);
    }
    return cont;
}*/


// -------------------------------------------------------------------
/*
#include <stdio.h>

int contar_caracteres(const char *nome_arquivo) {
    FILE *arquivo;
    int contador = 0;
    char caractere;

    // Abre o arquivo em modo de leitura
    arquivo = fopen(nome_arquivo, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'. Certifique-se de que o caminho está correto e você tem permissão para acessar o arquivo.\n", nome_arquivo);
        return -1;  // Retorna -1 em caso de erro
    }

    // Lê cada caractere do arquivo e incrementa o contador
    while ((caractere = fgetc(arquivo)) != EOF) {
        contador++;
    }

    // Fecha o arquivo
    fclose(arquivo);

    return contador;
}

int main() {
    const char *nome_do_arquivo = "exemplo.txt";  // Substitua pelo nome do seu arquivo
    int resultado = contar_caracteres(nome_do_arquivo);

    if (resultado != -1) {
        printf("O arquivo '%s' possui %d caracteres.\n", nome_do_arquivo, resultado);
    }

    return 0;
}
*/
