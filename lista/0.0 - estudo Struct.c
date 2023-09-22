#include <stdio.h>
#include <string.h> //para usar a fun��o strcpy
#define TAM 30
//definindo o tipo de dados struct
struct tipoPessoa
{
	char nome[TAM];
	int idade;
	float altura;
	
};
//redefinindo o struct para apenas tipoPessoa, para poder ser utilizado no c�digo
typedef struct tipoPessoa tipoPessoa;
	
void main()
{
	//criando e inicializando a vari�vel do tipo 'tipoPesso', que vai poder receber valores de char, int e float, como definnido na struct
	tipoPessoa dados = {"teste", 0, 0.0}; //'tipoPessoa' � o tipo e 'dados' a vari�vel;
	
	//exibindo os valores iniciais da vari�vel 'dados'
	printf("Dados iniciais:\n");
	printf("Nome: %s \n", dados.nome);
	printf("Idade: %d \n", dados.idade);
	printf("Altura: %.2f \n", dados.altura);
	
	//alterando o conte�do de cada campo manualmente
	strcpy(dados.nome, "novo");
	dados.idade = 21;
	dados.altura = 1.66;
	
	printf("\nDados alterados manualmente:\n");
	printf("Nome: %s \n", dados.nome);
	printf("Idade: %d \n", dados.idade);
	printf("Altura: %.2f \n", dados.altura);
	
	//alterando o conte�do de cada campo atrav�s da solicita��o
	printf("\nDigite o nome: ");
	fflush(stdin);
	gets(dados.nome);
	
	printf("Digite a idade: ");
	scanf("%d", &dados.idade);
	
	printf("Digite a altura: ");
	scanf("%f", &dados.altura);
	
	//exibindo os valores alterados sendo inseridos pelo usu�rio
	printf("\nDados alterados pelo usuario:\n");
	printf("Nome: %s \n", dados.nome);
	printf("Idade: %d \n", dados.idade);
	printf("Altura: %.2f \n", dados.altura);
}
