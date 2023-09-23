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


int removerCarro(tipoCarro estoque[], int quantidade, char placa[])
{
	int i, j;
	
	for(i=0; i<quantidade; i++)
	{
		//verificadno se é o carro a ser removido
		if(strcmp(estoque[i].placa, placa) == 0)
		{
			for(j=i+1; j<*quantidade; j++) //j inicia com o proxima posição
			{
				estoque[j-1] = estoque[j];
			}
			//atualizando quant de carros 
			(*quantidade)--;
			return 1;
		}
	}
	return 0;
}

void reajustarCarros0km(tipoCarro estoque[], int quantidade, float p)
{
	int i;
	
	for(i=0; i<quantidade; i++)
	{
		//verificando se o carro da posição 'i' é 0km
		if(strcmp(estoque[i].tipo), "0km" == 0)
		{
			//reajustar o valor do carro
			estoque[i].valor += (estoque[i].valor * (p/100));
			
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


void exibirFiltros(tipoCarro estoque[], int quantidade, char m[], int a1, int a2, float xReais)
{
	int i;
	
	//percorredno o vetor de carros
	for(i=0; i<quantidade; i++)
	{
		//verificando se o carro da posição 'i' do vetor atende ao solicitado
		if(strcmp(estoque[i].modelo, m) == 0 && 
		((estoque[i].ano.fabricacao >= a1) && (estoque[i].ano.fabricacao <= a2)) && 
		(estoque[i].valor <= xReais) ) //strcmp - compara strings, no caso o modelo em estoque com o solicitado pelo usuário
		{
			exibirDadosCarro(estoque[i]);
		}
	}	
}
void main()
{
	char modelo[20];
	int a1, a2;
	float xReais;
	float p;
	char placa[20];
	tipoCarro estoque[TAM] = {
		{"placa1", "modelo1", "marca1", "cor1", 0.1, 1, 100.00, "tipo1"},
		{"placa2", "modelo2", "marca2", "cor2", 0.2, 2, 200.00, "tipo2"},
		{"placa3", "modelo3", "marca3", "cor3", 0.3, 3, 300.00, "tipo3"},
	};
}
