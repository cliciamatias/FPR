#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct No {
    int valor;
    struct No* prox;
} TNo;

typedef struct {
    TNo* inicio;
} TLista;

int tabelaHash(int numero)
{
    return numero % TAM; //retornando o resto do numero para saber sua lista (0 a 9)
}

void inicializarLista(TLista* L)
{
    L->inicio = NULL; //inicializando para que o início de cada lista fique vazia
}

void inicializarTabela(TLista tabela[])
{
    int i;
    
    //percorrendo a tebela
	for(i=0; i<TAM; i++)
	{
		//percorrendo o endereço de cada posição(lista) da tebela
        inicializarLista(&tabela[i]);
    }
}

int buscarLista(TLista *L, int numero)
{
    TNo *aux = L->inicio;
    
    //percorrendo a lista
    while(aux)
	{
		//verificando se 'numero' foi encontrado na lista
        if(aux->valor == numero)
		{
            return 1; //'numero' encontrado
        }
        //atualizanod 'aux'
        aux = aux->prox;
    }
    return 0; //'numero' não encontrado
}

int inserirLista(TLista *L, int numero)
{
	TNo *aux;
	int existe = buscarLista(L, numero); //chamando função q verifica se já existe 'numero' na lista
	
    if(existe)
	{
        return 0; //já existe, retornar 0
    }
    else
    {
    	aux = (TNo*) malloc (sizeof(TNo)); //alocando memória para o numero a ser inserido  	
    }
    
    //verificando se houve erro na alocação
    if(!aux)
	{
        printf("\nErro ao alocar memoria!");
        return 0;
    }
    else
    {
    	//armazenando 'numero' na posição alocada recentemente
	    aux->valor = numero;
	    
	    //novo nó apontando para o priemiro nó da lista (início da lista)
	    aux->prox = L->inicio;
	    
	    //antigo primeiro nó apontando para o novo nó
	    L->inicio = aux;
	    
	    return 1; //retornando 1 pois elemento foi alocado
    }
}

int removerLista(TLista *L, int numero)
{
    TNo *aux = L->inicio;
    TNo *anterior = NULL;
    
    while(aux)
	{
        if(aux->valor == numero)
		{
            if(anterior)
			{
                anterior->prox = aux->prox;
            }
			else
			{
                L->inicio = aux->prox;
            }
            free(aux);
            return 1;
        }
        anterior = aux;
        aux = aux->prox;
    }
    return 0;
}

int alterarLista(TLista *L, int velho, int novo)
{
    if(buscarLista(L, novo))
	{
        return 0; 
    }
    TNo *aux = L->inicio;
    
    while(aux)
	{
        if(aux->valor == velho)
		{
            aux->valor = novo;
            return 1 ;
        }
        aux = aux->prox;
    }
    return 0;
}

void exibirLista(TLista *L)
{
    TNo *aux = L->inicio;
    
    printf("Lista: ");
    //percorrendo a lista
    while(aux)
	{
        printf("%d ", aux->valor); //exibindo a lista
        
        //atualizando 'aux' para que todos os elementos da lista sejam exibidos
        aux = aux->prox;
    }
    printf("\n");
}

void inserirNaTabela(TLista tabela[], int numero)
{
	//'posicao' recebendo resto da divisão de 'numero' para identificar sua posição na tabela
    int posicao = tabelaHash(numero); 
    int insere = inserirLista(&tabela[posicao], numero); //chamando função que insere elemento na lista
    
    //verificando se já há o numero na lista
    if(!insere)
	{
        printf("Erro! Numero repetido.\n");
    }
}

int buscaNaTabela(TLista tabela[], int numero)
{
    int posicao = tabelaHash(numero);
    
    //buscando e retornando en qual posição do vetor 'tabela' o 'numero' está alocado
    return buscarLista(&tabela[posicao], numero);
}

int removerDaTabela(TLista tabela[], int numero)
{
    int posicao = tabelaHash(numero);
    
    return removerLista(&tabela[posicao], numero);
}

int alterarNaTabela(TLista tabela[], int velho, int novo)
{
    int posicaoVelho = tabelaHash(velho);
    int posicaoNovo = tabelaHash(novo);
    
    if(posicaoVelho == posicaoNovo)
	{
        return alterarLista(&tabela[posicaoVelho], velho, novo);
    }
	else
	{
        if(removerLista(&tabela[posicaoVelho], velho))
		{
            return inserirLista(&tabela[posicaoNovo], novo);
        } 
		else
		{
            return 0;
        }
    }
}

void exibirTabela(TLista tabela[])
{
	int i;
	
    for(i=0; i<TAM; i++)
	{
        printf(" [%d] = ", i);
        exibirLista(&tabela[i]);
    }
}

int menu()
{
    int opcao;
    
    printf("\nMenu de opcoes:\n");
    printf("(1) Inserir\n");
    printf("(2) Buscar\n");
    printf("(3) Remover\n");
    printf("(4) Alterar\n");
    printf("(5) Exibir\n");
    printf("(0) Sair\n\n");
    
    printf("Entre com a sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void main()
{
    TLista tabela[TAM];
    int num, novo, retorno, opcao;

    inicializarTabela(tabela);

    do
	{
        system("CLS"); //limpar tela
        
        opcao = menu(); //chamando função menu
        
        switch(opcao)
		{
			//Inserir
            case 1:
                printf("\nEntre com o valor a ser inserido: ");
                scanf("%d", &num);
                
                inserirNaTabela(tabela, num); //chamando função
                break;
                
            //Buscar
            case 2:
                printf("\nEntre com o valor a ser buscado: ");
                scanf("%d", &num);
                
                retorno = buscaNaTabela(tabela, num); //chamando função
                
                //verificando se o valor foi encontrado
                if(retorno)
				{
                    printf("\nValor encontrado com sucesso!\n");
                }
				else
				{
                    printf("\nErro ao encontrar valor. Tente novamente.\n");
                }
                break;
                
            //Remover
            case 3:
                printf("\nEntre com o valor a ser removido: ");
                scanf("%d", &num);
                
                retorno = removerDaTabela(tabela, num); //chamando a função
                
                //verificando se valor foi removido
                if(retorno)
				{
                    printf("\nValor removido com sucesso!\n");
                }
				else
				{
                    printf("\nNao ha este valor! Tente novamente.\n");
                }
                break;
                
            //Alterar
            case 4:
                printf("\nEntre com o valor a ser alterado: ");
                scanf("%d", &num);
                printf("\nEntre com o novo valor: ");
                scanf("%d", &novo);
                
                retorno = alterarNaTabela(tabela, num, novo); //chamando a função
                
                //verificando se valor foi alterado
                if(retorno)
				{
                    printf("\nValor alterado com sucesso!\n");
                }
				else
				{
                    printf("\nErro ao alterar o valor! Tente novamente.\n");
                }
                break;
                
            //Exibir tabela
            case 5:
            	printf("\n----------------- TABELA -------------------\n\n");
                exibirTabela(tabela); //chamando a função
                printf("\n---------------------------------------------\n\n");
                break;
                
            //Sair
            case 0:
                printf("\n\nPrograma finalizado!\n");
                break;
                
            default:
                printf("\n\nOpcao invalida! Tente novamente.\n");
        }
        system("PAUSE");
        
    } while(opcao != 0);
}
