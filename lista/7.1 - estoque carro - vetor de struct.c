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
}
