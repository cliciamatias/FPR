/*Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/
#include <stdio.h>
#define QUANT 2
typedef struct
{
	int modelo[15];
	int fabricacao;
}TAno;

typedef struct
{
	char placa[9];
	char modelo[10];
	char marca[15];
	char cor[15];
	float quilometragem;
	TAno ano;
	float valor;
	char tipo[20];
}TCarro;

void lerDadosCarro(TCarro carro[]);
void exibirCarros(TCarro carro[], char m[], int a1, int a2, float x);
void reajuste(TCarro carro[], float p);
int retirarDoEstoque(TCarro carro[], int *quant, char placa[]);

void main()
{
	TCarro veiculo[QUANT];
	char m[20] = "aaaa";
	int a1=1, a2=2, quant, retorno;
	float x=10.9, p=10;
	char placa[9] = "esok321";
	
	//chamando a função que lê os dados do veículo
	lerDadosCarro(veiculo);
	
	//chamando a função e exibe os carros os especificações de modelo, ano e valor
	exibirCarros(veiculo, m, a1, a2, x);
	
	//chamando a função com reajuste de p%
	reajuste(veiculo, p);
	
	//chamando função com remoção de veículo do estoque
	retorno = retirarDoEstoque(veiculo, &quant, placa);
	
	//verificando se veículo foi removido ou não (não pede, mas é bom confirmar se foi realizado com sucesso
	if(retorno == 1)
	{
		printf("\nVeiculo removido com sucesso!");
	}
	else
	{
		printf("\nNao ha veiculo para remover");
	}
}
//função para ler dados do veículo (para não "poluir" a main visualmente)
void lerDadosCarro(TCarro veiculo[])
{
	int i;
	//lendo os dados do veículo
	for(i=0; i<QUANT; i++)
	{
		printf("\n--------------\nPlaca: ");
		fflush(stdin);
		gets(veiculo[i].placa);
		
		printf("Modelo: ");
		fflush(stdin);
		gets(veiculo[i].modelo);
		
		printf("Marca: ");
		fflush(stdin);
		gets(veiculo[i].marca);
		
		printf("Cor: ");
		fflush(stdin);
		gets(veiculo[i].cor);
		
		printf("Quilometragem: ");
		scanf("%f", &veiculo[i].quilometragem);
		
		printf("Ano (fabricacao/modelo): ");
		scanf("%d %d", &veiculo[i].ano.fabricacao, &veiculo[i].ano.modelo);
		
		printf("Valor: ");
		scanf("%f", &veiculo[i].valor);
		
		printf("Tipo: ");
		fflush(stdin);
		gets(veiculo[i].tipo);
	}
}

//i. Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior a x reais;
void exibirCarros(TCarro carro[], char m[], int a1, int a2, float x)
{
	int i;
	
	//percorrendo o vetor de struct com informações dos carros
	for(i=0; i<QUANT; i++)
	{
		//verificando se o carro segue as especificações de modelo, ano e valor
		if((strcmp(carro[i].modelo, m[i])==0) && ((carro[i].ano.fabricacao >= a1) && (carro[i].ano.fabricacao <= a2)) && (carro[i].valor >= x))
		{
			//exibindo conforme solicitado
			printf("\nPlaca: %s", carro[i].placa);
		
			printf("\nModelo: %s", carro[i].modelo);
			
			printf("\nMarca: %s", carro[i].marca);
			
			printf("\nCor: %s", carro[i].cor);
			
			printf("\nQuilometragem: %.1f", carro[i].quilometragem);
			
			printf("\nAno (fabricacao/modelo): %d, %d", carro[i].ano.fabricacao, carro[i].ano.modelo);
			
			printf("\nValor: %.2f", carro[i].valor);
			
			printf("\nTipo: %s", carro[i].tipo);
		}
	}
}

//ii. Reajustar os valores de todos os carros 0km, considerando um aumento de p %;
void reajuste(TCarro carro[], float p)
{
	int i;
	
	//percorrendo o vetor de struct com informações dos carros
	for(i=0; i<	QUANT; i++)
	{
		//verificando se o carro é 0km
		if(carro[i].tipo == "0km")
		{
			carro[i].valor += (carro[i].valor * (p / 100)); //reajustando o valor do caro 0km com 'p% de aumento'
		}
	}
}

//iii. Retirar do estoque um determinado veículo, dada a sua placa
int retirarDoEstoque(TCarro carro[], int *quant, char placa[])
{
	int i, j;
	
	for(i=0; i<(*quant); i++)
	{
		//verificando se há a placa escolhida
		if(strcmp(carro[i].placa, placa) == 0)
		{
			for(j=i+1; j<(*quant); j++)
			{
				carro[j-1] = carro[j]; //removendo o carro do estoque
			}
			(*quant)--;
			return 1; //carro foi removido
		}
	}
	return 0; //não há carro removido
}




//-------------------------------------------------------------------------
/*Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/
/*
#include <stdio.h>
#include <string.h>
#define TAM 3 //quantidade de carros em estoque

typedef struct
{
	int fabricacao;
	int modelo;
} tipoAno;

typedef struct
{
	char placa[8];
	char modelo[20];
	char marca[20];
	char cor[20];
	float quilometragem;
	tipoAno ano;
	float valor;
	char tipo[6];
	
} tipoCarro;
//Retirar do estoque um determinado veículo, dada a sua placa
int removerCarro(tipoCarro estoque[], int *quantidade, char placa[])
{
	int i, j;
	
	for(i=0; i<*quantidade; i++)
	{
		if(strcmp(estoque[i].placa, placa) == 0)
		{
			for(j=i+1; j<*quantidade; j++)
			{
				estoque[j-1] = estoque[j];
			}
			(*quantidade)--;
			return 1;
		}
	}
	return 0;
}
//Reajustar os valores de todos os carros 0km, considerando um aumento de p %;
void reajustarCarros0km(tipoCarro estoque[], int quantidade, float p)
{
	int i;
	
	for(i=0; i<quantidade; i++)
	{
		if(strcmp(estoque[i].tipo, "0 km") == 0)
		{
			estoque[i].valor += (estoque[i].valor * (p/100.0));
		}
	}
}
void exibirDadosCarro(tipoCarro carro)
{
	printf("Placa: %s\n", carro.placa);
	printf("Marca/Modelo: %s/%s\n", carro.marca, carro.modelo);
	printf("Cor: %s\n", carro.cor);
	printf("Km: %.2f\n", carro.quilometragem);
	printf("Ano(fabricacao/modelo): %d/%d \n", carro.ano.fabricacao, carro.ano.modelo);
	printf("Valor: %.2f\n", carro.valor);
	printf("Tipo: %s\n", carro.tipo);
}

//Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior a x reais;
void exibirFiltros(tipoCarro estoque[], int quantidade, char m[], int a1, int a2, float xReais)
{
	int i;
	
	for(i=0; i<quantidade; i++)
	{
		if(strcmp(estoque[i].modelo, m) == 0 && 
		(estoque[i].ano.fabricacao >= a1 && estoque[i].ano.fabricacao <= a2) && 
		(estoque[i].valor <= xReais))
		{
			exibirDadosCarro(estoque[i]);
		}
	}	
}

int main()
{
	tipoCarro estoque[TAM];

	strcpy(estoque[0].placa, "placa1");
	strcpy(estoque[0].modelo, "modelo1");
	strcpy(estoque[0].marca, "marca1");
	strcpy(estoque[0].cor, "cor1");
	estoque[0].quilometragem = 1.0;
	estoque[0].ano.fabricacao = 2001;
    estoque[0].ano.modelo = 2002;
    estoque[0].valor = 100.00;
	strcpy(estoque[0].tipo, "tipo1");
	
	strcpy(estoque[1].placa, "placa2");
	strcpy(estoque[1].modelo, "modelo2");
	strcpy(estoque[1].marca, "marca2");
	strcpy(estoque[1].cor, "cor2");
    estoque[1].quilometragem = 2.0;
    estoque[1].ano.fabricacao = 2003;
    estoque[1].ano.modelo = 2004;
    estoque[1].valor = 200.00;
	strcpy(estoque[1].tipo, "tipo2");
	
	strcpy(estoque[2].placa, "placa3");
	strcpy(estoque[2].modelo, "modelo3");
	strcpy(estoque[2].marca, "marca3");
	strcpy(estoque[2].cor, "cor3");
    estoque[2].quilometragem = 3.0;
    estoque[2].ano.fabricacao = 2005;
    estoque[2].ano.modelo = 2006;
    estoque[2].valor = 300.00;
	strcpy(estoque[2].tipo, "tipo3");

//i. Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior a x reais;
	exibirFiltros(estoque, TAM, "modelo2", 2001, 2004, 200.00);


	return 0;
} */
