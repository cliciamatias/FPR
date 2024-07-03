/*QUESTÃO 04:
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são
iguais; isto é, contêm os mesmos elementos, na mesma ordem.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct No {
	int valor;
	struct No *prox;
} TNo;
typedef TNo* TLista;

int compararListas(TLista l1, TLista l2);
int inserir(TLista *L, int numero);
void exibir(TLista L);

void main()
{
	TLista L1=NULL, L2=NULL;
	int comparacao = compararListas(L1, L2); //chamando a função de comparação das listas
	
	//inserindo valores na lista 'L1'
	inserir(&L1, 2);
	inserir(&L1, 4);
	inserir(&L1, 6);
	inserir(&L1, 8);
	
	//inserindo valores na lista 'L2'
	inserir(&L2, 2);
	inserir(&L2, 4);
	inserir(&L2, 6);
	inserir(&L2, 8);
	
	//exibindo as listas 'L1' e 'L2'
	exibir(L1);
	exibir(L2);
	
	//verificando se as listas sao iguais
	if(comparacao == 1)
	{
		printf("\nAs listas sao iguais.");
	}
	else
	{
		printf("As listas NAO sao iguais");
	}
}

int compararListas(TLista l1, TLista l2)
{
	TLista aux1 = l1, aux2 = l2; 
	
	//percorrendo as listas (enquanto existirem...)
	while(aux1 && aux2)
	{
		//verificando se há algum valor de diferente entre as listas
		if(aux1->valor != aux2->valor)
		{
			return 0; //valores diferentes, retornando 0
		}
		
		//atualizando as variáveis auxiliares para que em cada repetição aponte para o próximo valor
		aux1 = aux1->prox;
		aux2 = aux2->prox;
	}
	//verificando se as duas listas terminaram, se possuem o mesmo tamanho
	if(!aux1 && !aux2)
	{
		return 1; //ambas as listas chegaram em NULL, então terminaram, retornar 1, pois sao iguais
	}
	else
	{
		return 0; //nao terminaram juntas, então listas diferentes, retornar 0
	}
}

//função para inserir elementos na lista
int inserir(TLista *L, int numero)
{
	TLista aux;
	
	//alocando memória, para armazenar numeros na lista
	aux = (TLista) malloc(sizeof(TNo));
	
	//verificando se houve erro ao alocar
	if(!aux)
	{
		return 0;
	}
	else
	{
		//posição recente recebe o numero inserido
		aux->valor = numero;
		
		//novo nó apontando para o antigo primeiro nó
		aux->prox = *L;
		
		//fazendo com que *L aponte para o novo nó
		*L = aux; 
		
		return 1; //retornando 1 pois foi alocado com sucesso
	}
}

void exibir(TLista L)
{
	TLista aux = L;
	
	//verificando se a lista está vazia (NULL)
	if(!L)
	{
		printf("\nLista Vazia.");
	}
	else
	{
		printf("\nLista: ");
		
		//percorrendo a lista
		while(aux)
		{
			printf("%d ", aux->valor); 
			
			//atualizando o valor da lista para exibir o próximo
			aux = aux->prox;
		}
		printf("\n");
	}
}

// _________________________________________________________
/*
//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int compararListas (TLista lista1, TLista lista2);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declaração de variáveis
	TLista L1 = NULL, L2 = NULL, L3 = NULL;
	
	//inserindo elementos em L1
	inserir (&L1, 10);
	inserir (&L1, 4);
	inserir (&L1, 13);
	inserir (&L1, 7);
	
	//inserindo elementos em L2
	inserir (&L2, 7);
	inserir (&L2, 4);
	inserir (&L2, 10);
	inserir (&L2, 13);
		
	//inserindo elementos em L3
	inserir (&L3, 10);
	inserir (&L3, 4);
	inserir (&L3, 13);
	inserir (&L3, 7);
	inserir (&L3, 5);
	
	//exibindo as listas
	exibir (L1);
	exibir (L2);
	exibir (L3);
	
	//chamando a função
	if (compararListas (L1, L2) == 1)
	{
		printf ("\n\nL1 e L2 possuem os mesmos elementos, na mesma ordem!\n\n");
	}
	else
	{
		printf ("\n\nL1 e L2 NAO possuem os mesmos elementos, na mesma ordem!\n\n");
	}
	
	if (compararListas (L1, L3) == 1)
	{
		printf ("\n\nL1 e L3 possuem os mesmos elementos, na mesma ordem!\n\n");
	}
	else
	{
		printf ("\n\nL1 e L3 NAO possuem os mesmos elementos, na mesma ordem!\n\n");
	}

}

//implementação das funções
int compararListas (TLista lista1, TLista lista2)
{
	//declaração de variáveis
	TLista aux1 = lista1, aux2 = lista2;
	
	//percorrendo as listas
	while (aux1 && aux2)
	{
		//verificando se dois elementos distintos foram encontrados
		if (aux1->valor != aux2->valor)
		{
			return 0;
		}
		
		//atualizando os auxiliares
		aux1 = aux1->prox;
		aux2 = aux2->prox;
	}
	
	//verificando se as duas listas terminaram
	if (!aux1 && !aux2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória para o novo elemento
	aux = (TLista) malloc (sizeof(TNo));   //malloc - memory allocation
	
	//verificando se houve erro na alocação
	if (!aux)
	{
		return 0;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posição recém-alocada
		aux->valor = numero;
		
		//Passo 3: fazer o novo nó apontar para o "antigo primeiro nó"
		aux->prox = *L;
		
		//Passo 4: fazer com que *L aponte para o novo Nó
		*L = aux;
		
		return 1;
	}
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	//verificando se a lista está vazia
	if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Lista: ");
	
		//while (aux != NULL)
		while (aux)
		{
			printf ("%d ", aux->valor);
			//ou:    printf ("%d ", (*aux).valor);
			
			aux = aux->prox;
		}
		
		printf ("\n");
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}














*/
