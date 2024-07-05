#include <stdio.h>
#include <stdlib.h>

#define TAM 10

//definindo tipos
typedef struct No {
    int valor;
    struct No* prox;
} TNo;

typedef struct {
    TNo* inicio;
} TLista;

//protótipo das funções
int tabelaHash(int numero);
void inicializarLista(TLista *L);
void inicializarTabela(TLista tabela[]);
int buscarLista(TLista *L, int numero);
int inserirLista(TLista *L, int numero);
int removerLista(TLista *L, int numero);
int alterarLista(TLista *L, int velho, int novo);
void exibirLista(TLista *L);
void inserirNaTabela(TLista tabela[], int numero);
int buscaNaTabela(TLista tabela[], int numero);
int removerDaTabela(TLista tabela[], int numero);
int alterarNaTabela(TLista tabela[], int velho, int novo);
void exibirTabela(TLista tabela[]);
int menu();

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
                printf("\nPrograma finalizado!\n\n");
                break;
                
            default:
                printf("\n\nOpcao invalida! Tente novamente.\n");
        }
        system("PAUSE");
        
    } while(opcao != 0);
}

int tabelaHash(int numero)
{
    return numero % TAM; //retornando o resto do numero para saber sua lista (0 a 9)
}

void inicializarLista(TLista *L)
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
	//verificando se o novo valor existe na lista
    if(buscarLista(L, novo))
	{
        return 0; //retornando 0 pois já existe
    }
    
    //inicializando ponteiro de 'aux'
    TNo *aux = L->inicio;
    
    //percorrendo a lista
    while(aux)
	{
		//verificando se valor é igual ao escolhido para ser alterado
        if(aux->valor == velho)
		{
			//recebendo o novo valor
            aux->valor = novo;
            return 1 ;
        }
        //atualizando 'aux'
        aux = aux->prox;
    }
    return 0; //retornando 0 pois valor não enocntrado para ser alterado
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
    
    //chamando função que remove elemento da lista
    return removerLista(&tabela[posicao], numero);
}

int alterarNaTabela(TLista tabela[], int velho, int novo)
{
    int posicaoVelho = tabelaHash(velho); //recebendo a posição do valor antigo
    int posicaoNovo = tabelaHash(novo); //recebendo a posição do novo valor
    
    //verificando se ambos os valores estão na mesma posição na tabela, para apenas alterar na mesma lista
    if(posicaoVelho == posicaoNovo)
	{
		//alterando os valores dentro da lista
        return alterarLista(&tabela[posicaoVelho], velho, novo);
    }
	else
	{
		//removendo o antigo valor da sua lista atual
        if(removerLista(&tabela[posicaoVelho], velho))
		{
			//inserindo o novo valor na sua respectiva lista
            return inserirLista(&tabela[posicaoNovo], novo);
        } 
		else
		{
            return 0; //se houve erro, retornando 0
        }
    }
}

void exibirTabela(TLista tabela[])
{
	int i;
	
	//percorrendo a tabela 
    for(i=0; i<TAM; i++)
	{
		//exibindo tabela contendo as listas encadeadas
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
