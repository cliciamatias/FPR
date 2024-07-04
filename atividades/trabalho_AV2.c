/*a. A tabela hash será composta por 10 listas
encadeadas simples (na prática, um vetor de
TLista, com tamanho igual a 10);
b. Os elementos de cada uma das listas não estão
dispostos de forma ordenada (crescente ou
decrescente). Ou seja, não há critério algum
de ordenação de seus elementos;
c. Elementos repetidos são proibidos nesta
tabela hash.

Devem ser desenvolvidas as mesmas operações
(funções) trabalhadas nas aulas para a implementação
de lista encadeada, a saber:
? Inserção de um novo valor;
? Remoção de determinado elemento;
? Alteração de um número por outro;
? Busca de um elemento na tabela;
? Exibição dos elementos: esta operação poderá
ser executada de duas maneiras, por escolha
do usuário – exibir os elementos de uma das
listas (informando o seu número) ou de toda a
tabela.*/


//importação de bibliotecas

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;
//typedef TNo* TLista;

typedef struct {
	TNo *inicio;
} TLista;

//protótipos das funções
//___________________________

int tabelaHash(int numero)
{
	return numero % TAM; //retornando o resto do numero para saber sua lista
}

void inicializarLista(TLista *L)
{
	//inicializando para que o início de cada lista fique fazia
	L->inicio = NULL;
}

void inicializarTabela(TLista tabela[])
{
	int i;
	
	//percorrendo a tabela
	for(i=0; i<TAM; i++)
	{
		//percorrendo o endereço de cada posição(lista) da tabela, pois cada posição do vetor tabela é uma lista
		inicializarLista(&tabela[i]);
	}
}

int inserirLista(TLista *L, int numero)
{
	//declaração de variáveis
	TNo *aux;
	int existe = buscarLista(L, numero); //chamando função que busca determinado número
	
	//verificando se o número já existe na lista
	if(existe)
	{
		return 0; //se já existe, retornar 0
	}
	else
	{
		//alocando memória para o número a ser inserido
		aux = (TNo*) malloc (sizeof(TNo));
		
		//verificando se houve erro na alocação
		if(!aux)
		{
			printf("\nErro ao alocar memoria!");
			return 0; //houve erro na alocação de memória na variável 'aux', retornar 0
		}
		else
		{
			//armazenando 'numero' na posição alocada recentemente
			aux->valor = numero;
			
			//novo nó apontando para o primeiro nó da lista (inicio da lista)
			aux->prox = L->inicio;
			
			//antigo primeiro nó apontando para o novo nó
			L->inicio = aux;
			
			return 1; //retornando 1 pois elemento foi alocado com sucesso
		}
	}
}

int buscarLista(TLista *L, int numero)
{
	//declaração de variáveis
	TNo *aux = L->inicio;

	//percorrendo a lista	
	while(aux)
	{
		//verificando se 'numero' foi encontrado na lista
		if(aux->valor == numero)
		{
			return *aux; //retornando o valor encontrado
		}
		
		//atualizando 'aux'
		aux = aux->prox;
	}
	
	//'numero' não se encontra na lista
	return NULL;
}

void exibirLista(TLista *L)
{
	//declaração de variáveis
	TNo *aux = L->inicio;
	
	//verificando se a lista está vazia
	if(!aux)
	{
		printf("Essa lista esta vazia!\n");
	}
	else
	{
		printf("Lista: ");
		
		//percorrendo a lista
		while(aux)
		{
			printf("%d ", aux->valor); //exibindo a lista
			
			//atualizando o valor de 'aux' para que todos os elementos da lista sejam exibidos
			aux = aux->prox;
		}
		printf("\n");
	}
}

void inserirNaTabela(TLista tabela[], int numero)
{
	int posicao = tabelaHash(numero); //'posicao' recebendo o resto da divisão de 'numero', para identificar sua posição no vetor
	
	//inserindo o elemento no endereço do vetor 'tabela' pois cada posição é uma lista (0 a 9)
	inserirLista(&tabela[posicao], numero);
}

int buscaNaTabela(TLista tabela[], int numero)
{
	int posicao = tabelaHash(numero);
	
	//buscando e retornando em qual posição do vetor 'tabela' o 'numero' está localizado
	return buscarLista(&tabela[posicao], numero);
}

void exibirTabela(TLista tabela[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		printf("%d = ", i);
		exibirLista(&tabela[i]);
	}
}

int menu()
{
	int opcao;
	
	//exibindo o menu ao usuário
	printf("Menu de opcoes:\n");
	printf("(1) Inserir\n");
	printf("(2) Buscar\n");
	printf("(3) Exibir\n");
	printf("(0) Sair\n\n");
	
	//lendo a opção escolhida
	printf("Entre com a sua opcao: ");
	scanf("%d", &opcao);
	
	//retornando a opção
	return opcao;
}

void main()
{
	//declaração de variáveis
	TLista tabela[TAM];
	int opcao=menu(), num, retorno;
	
	inicializarTabela(tabela);
	
	do
	{
		system("CLS");	//limpar tela    clrscr();
		
		//verificando a opção escolhida
		switch(opcao)
		{
			//Inserir
			case 1: printf("\nEntre com o valor a ser inserido: ");
			        scanf("%d", &num);
			        
			        inserirTabela(tabela, num); //chamando a função
					break;

			//Buscar
			case 2: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num);
			        
			        retorno = buscaNaTabela(tabela, num); //chamando a função
					if(retorno != 0)
					{
						printf("\nValor encontrado com sucesso!");
					}
					else
					{
						printf("\nValor nao encontrado! Tente novamente.");
					}
					break;
					
			//Exibir
			case 3: exibir (tabela);
					break;
					
			//Saída
			case 0: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}while(opcao != 0);
}
