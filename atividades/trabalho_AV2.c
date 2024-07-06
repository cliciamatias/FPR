/*========================================
Alunos: Clicia Matias e Bruno dos Santos Gonçalves
2FPR - Manhã
==========================================
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

//definindo os tipos
typedef struct No
{
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

//implementação das funções
int tabelaHash(int n)
{
	return n % TAM;
}

TLista buscar (TLista L[], int n)
{
	int p = tabelaHash(n);
	TLista aux = L[p];
	
	//percorrendo a lista
	while(aux)
	{
		//verificando se 'n' foi encontrado na lista
		if (aux->valor == n)
		{
			return aux;
		}
		//atualizando 'aux'
		aux = aux->prox;
	}
	return NULL;
}

int inserir (TLista L[], int n)
{
	TLista aux;
	int p = tabelaHash(n);
	
	//verificando se já existe 'n' na lista
	if(buscar(L, n))
	{
		return 0; //já existe, retornando 0 pois não pode valor repetido
	}
	else
	{
		aux = (TLista) malloc (sizeof(TNo)); //alocando memória para o número ser inserido
		
		//verificando se houve erro na alocação
		if(!aux)
		{
			return 0; //nao alocado
		}
		else
		{
			//inserindo o valor na tabela
			aux->valor = n;
			aux->prox = L[p];
			L[p] = aux;
			
			return 1; //'n' alocado
		}
	} 
	
}

int remover (TLista L[], int n)
{
	TLista pre, pos;
	int p = tabelaHash(n);
	
	if (L[p])
	{
		if (L[p]->valor == n)
		{
			pre = L[p];   
				
			L[p] = pre->prox;       
				
			free (pre);
				
			return 1;
		} 
		else
		{
			pos = (L[p])->prox;
			
			pre = L[p];
			
			while (pos)
			{

				if (pos->valor == n)
				{
					
					pre->prox = pos->prox;
					
					
					free (pos);
	
					return 1;
				}
				else
				{
					pre = pos;
					pos = pos->prox;  
				}
			}
		}
	}
	return 0;
}

int alterar (TLista L[], int velho, int novo)
{
	TLista posnovo, posvelho;
	posvelho = buscar(L, velho);
	posnovo = buscar(L, novo);
	
	//verificando se não existe o valor a ser alterado para notificar erro ao alterar vslor que nao existe
	if(!posvelho)
	{
		return 0; 
	}
	else
	{
		//verificando se valor a ser inserido já existe, pois não é permitido repetição
		if(posnovo)
		{
			return 0;
		}
		else
		{	
			//verificando se valores a serem alterados estão na mesma posição da tabela
			if(tabelaHash(velho) == tabelaHash(novo))
			{
				//recebendo o novo valor
				posvelho->valor = novo;
				return 1;
			}
			else
			{
				//inserindo o novo valor e removendo o antigo em suas respectivas posições
			 	inserir(L, novo);
				remover(L, velho);
				return 1;	
			}
		}
	}	
}

void exibir (TLista L[])
{
	int i;
	
	//percorrendo a tabela
	for(i=0; i<TAM; i++)
	{
		TLista aux = L[i];
		
		if(!L[i])
		{
			printf("LISTA [%d]: Vazia!", i);
		}
		else
		{
			printf("LISTA [%d]: ", i);
			while(aux)
			{
				printf("%d ", aux->valor);
				
				//atualizando 'aux'
				aux = aux->prox;
			}
		}
		printf("\n");
	}
	
}

int menu ()
{	
	int operacao;
	
	printf("Menu de Operacoes:\n\n");
	printf("(1) Inserir\n");
	printf("(2) Remover\n");
	printf("(3) Alterar\n");
	printf("(4) Buscar\n");
	printf("(5) Exibir\n");
	printf("(6) Sair\n\n");
	
	printf("Entre com sua opcao: ");
	scanf("%d", &operacao);
	
	return operacao;
}

void main()
{
	TLista L[TAM];
	TLista pos;
	int num1, num2, op, i;
	
	for(i=0;i<TAM;i++)
	{
		L[i] = NULL;
	}
	
	do
	{
		system("CLS");
		
		op = menu(); //chamando função menu
		
		switch (op)
		{
			//Inserir
			case 1:
				printf("Entre com o valor a ser inserido: ");
				scanf("%d", &num1);
				
				if(inserir(L, num1))
				{
					printf("\n\tNumero inserido com sucesso!\n");
				}
				else
				{
					printf("\n\tNumero nao inserido!\n");	
				}
				break;
				
			//Remover
			case 2:
				printf("Entre com o valor a ser removido: ");
				scanf("%d", &num1);
				
				if(remover(L, num1))
				{
					printf("\n\tValor removido com sucesso!\n");
				}
				else
				{
					printf("\n\tValor não removido.\n");
				}
				break;
				
			//Alterar
			case 3:
				printf("Entre com o valor a ser Alterado: ");
				scanf("%d", &num1);
				printf("Entre com o valor o novo valor: ");
				scanf("%d", &num2);
				
				if(alterar(L, num1, num2))
				{
					printf("\n\tValor Alterado com sucesso!\n");
				}
				else
				{
					printf("\n\tValor nao foi alterado.\n");
				}
				break;
				
			//Buscar
			case 4:
				printf("Entre com o valor a ser buscado: ");
				scanf("%d", &num1);
				
				pos = buscar(L, num1);
				if(pos)
				{
					printf("\n\tO valor foi encontrado na lista!\n");		
				}
				else
				{
					printf("\n\tO valor nao esta na lista!\n");	
				}
				break;
				
			//Exibir tabela
			case 5:
				printf("\n----------------- TABELA -------------------\n\n");
				exibir(L);
				printf("\n---------------------------------------------\n\n");
				break;
				
			//Sair
			case 6: 
				printf("\n\tPrograma finalizado.\n\n");
				break;
				
			default: 
				printf("\n\tOpcao invalida! Tente novamente.\n");	
		}
		system("PAUSE");
	}
	while(op != 6);	
}
