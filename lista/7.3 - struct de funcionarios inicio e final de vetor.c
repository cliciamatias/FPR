/*Quest�o 03:
Considere a exist�ncia de um vetor de structs
com quant posi��es, onde cada uma destas
armazena os seguintes dados sobre os
funcion�rios de uma empresa: matricula (int),
nome (string), g�nero (char) e sal�rio (float).
Pede-se uma fun��o que, dado um g�nero,
desloque todos os funcion�rios deste g�nero
para o in�cio do vetor (e, consequentemente, os
funcion�rios do outro g�nero ficar�o ao final do
conjunto).*/
#include <stdio.h>
#include <string.h>
#define TAM 5
typedef struct
{
	int matricula;
	char nome[30];
	char genero;
	float salario;
	
} tipoFunc;

void deslocarFunc(tipoFunc func[], int tamanho, char g);
void exibir(tipoFunc func[], int tamanho);
void main()
{
	tipoFunc funcionario[TAM];	
	char genero = 'm';
	//vetorOriginal = {0, 1, 2, 3, 4};
	// genero = 'f'
	//VetorGenero = {1, 2, 4, 0, 3};
				//	{11,12,14,10,13}
				
	//declarando os dados de cada funcion�rio
	funcionario[0].matricula = 10;
    strcpy(funcionario[0].nome, "Joao");
    funcionario[0].genero = 'm';
    funcionario[0].salario = 1200.90;
    
    funcionario[1].matricula = 11;
    strcpy(funcionario[1].nome, "Marcia");
    funcionario[1].genero = 'f';
    funcionario[1].salario = 1210.90;
    
    funcionario[2].matricula = 12;
    strcpy(funcionario[2].nome, "Anna");
    funcionario[2].genero = 'f';
    funcionario[2].salario = 1220.90;
    
    funcionario[3].matricula = 13;
    strcpy(funcionario[3].nome, "Pedro");
    funcionario[3].genero = 'm';
    funcionario[3].salario = 1230.90;
    
    funcionario[4].matricula = 14;
    strcpy(funcionario[4].nome, "Maria");
    funcionario[4].genero = 'f';
    funcionario[4].salario = 1240.90;
    
    printf("\nVetor ORIGINAL: ");
    exibir(funcionario,TAM);
    
    deslocarFunc(funcionario, TAM,genero);
    printf("\n\nVetor DESLOCADO: ");
    exibir(funcionario,TAM);
}
void deslocarFunc(tipoFunc func[], int tamanho, char g)
{
	int i, inicio=0;
	tipoFunc aux; //declarando a vari�vel auxiliar como tipoFuncionario pois os dados que ser�o passadas para ela � deste tipo
	
	//percorrendo vetor de funcion�rios
	for(i=0; i<tamanho; i++)
    {
    	//verificando se o funcion�rio � do genero desejado
        if(func[i].genero == g)
        {
            //trocando o funcion�rio de posi��o com o primeiro n�o deslocado
            aux = func[i];
            func[i] = func[inicio];
            func[inicio] = aux;
            inicio++;
        }
    }
}
//fun��o para exibir os nomes
void exibir(tipoFunc func[], int tamanho)
{
	int i;
	for(i=0; i<tamanho; i++)
	{
		printf("|%s| ", func[i].nome);	
	}
}
