#include <stdio.h> 
#define TAM 3
//definindo o tipo de dados struct
struct tipoPessoa
{
	char nome[50];
	int idade;
	float altura;
	
};
//redefinindo o struct para apenas tipoPessoa, para poder ser utilizado no código
typedef struct tipoPessoa tipoPessoa;
	
void main()
{
	tipoPessoa lista[TAM]; //criando vetor com os dados da struct
	int i;
	
	//percorrendo o vetor para ler dados
	for(i=0; i<TAM; i++)
	{
		//lendo dados de cada pessoa
		printf("\n\nDados da pessoa %d:\n", i+1); //"i+1" para começar a quantidad de pessoas com 1 e não 0
		printf("Nome: ");
		fflush(stdin);
		gets(lista[i].nome);
		
		printf("Idade: ");
		scanf("%d", &lista[i].idade);
		
		printf("Altura: ");
		scanf("%f", &lista[i].altura);
	}
	//percorrendo o vetor para exibir dados
	for(i=0; i<TAM; i++)
	{	
		printf("\n\n------ Pessoa %d: ---------", i+1);  //"i+1" para começar a quantidad de pessoas com 1 e não 0
		printf("\nNome: %s\n", lista[i].nome);
		printf("Idade: %d\n", lista[i].idade);
		printf("Alura: %.2f\n", lista[i].altura);
	}
	
}
