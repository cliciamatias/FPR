/*Questão 05:
O histórico de um aluno é representado por um
vetor de structs onde cada posição armazena o
código da disciplina cursada, semestre e ano
que a cumpriu e a média final na disciplina.
Implementar uma função que exiba o histórico
do aluno com o seguinte formato:
NomeDisciplina1 (código1) MédiaDisciplina1
NomeDisciplina2 (código2) MédiaDisciplina2
NomeDisciplinaN (códigoN) MédiaDisciplinaN
Coeficiente de rendimento: CR

Observações:
1. Para obter os dados da disciplina, um outro
vetor de structs deve ser consultado. Este,
por sua vez, armazena para cada disciplina
do curso as seguintes informações: código,
nome e número de créditos;
2. O coeficiente de rendimento consiste em
uma média ponderada de todos os graus
atribuídos às disciplinas cursadas, onde os
pesos são representados pelo número de
créditos da disciplina;
3. Todos os dados em negrito apresentados no
formato do histórico devem ser obtidos a
partir dos vetores.*/
#include <stdio.h>
#include <string.h>
#define TAM 3
#define TAM2 5
typedef struct
{
	int codigoDisciplina;
	int semestre;
	int ano;
	float mediaFinal;
} tipoHistorico;

typedef struct
{
	int codigo;
	char nome[20];
 	int creditos;
} tipoDisciplina;

void exibirHistorico(tipoDisciplina disciplina[], int tamanho2, tipoHistorico histAluno[], int tamanho);
void main()
{
	tipoHistorico histAluno[TAM];
	tipoDisciplina disciplina[TAM2];
	
	disciplina[0].codigo = 101;
	strcpy(disciplina[0].nome, "FAC");
	disciplina[0].creditos = 10;
	
	disciplina[1].codigo = 111;
	strcpy(disciplina[1].nome, "ORG");
	disciplina[1].creditos = 20;
	
	disciplina[2].codigo = 222;
	strcpy(disciplina[2].nome, "MAC");
	disciplina[2].creditos = 30;
	
	disciplina[3].codigo = 333;
	strcpy(disciplina[3].nome, "IHM");
	disciplina[3].creditos = 40;
	
	disciplina[4].codigo = 444;
	strcpy(disciplina[4].nome, "LPO");
	disciplina[4].creditos = 50;
	
	//declarando dados das variáveis
	histAluno[0].codigoDisciplina = 101;
	histAluno[0].semestre = 2;
	histAluno[0].ano = 2020;
	histAluno[0].mediaFinal = 9.8;
	histAluno[1].codigoDisciplina = 111;
	histAluno[1].semestre = 1;						//disciplainas FAC, ORG e LPO
	histAluno[1].ano = 2020;
	histAluno[1].mediaFinal = 8.8;
	histAluno[2].codigoDisciplina = 444;
	histAluno[2].semestre = 1;
	histAluno[2].ano = 2022;
	histAluno[2].mediaFinal = 7.7;
	
	exibirHistorico(disciplina,TAM2,histAluno,TAM);
}
void exibirHistorico(tipoDisciplina disciplina[], int tamanho2, tipoHistorico histAluno[], int tamanho)
{
	int i, j, somaCredito=0;
	float  multip, soma=0, media;
	
	//percorrendo o histórico do alunos
	for(i=0; i<tamanho; i++)
	{
		//percorrendo as disciplinas existentes no curso
		for(j=0; j<tamanho2; j++)
		{
			//verificando as disciplinas que o aluno foi matriculado de acordo com o código
			if(histAluno[i].codigoDisciplina == disciplina[j].codigo)
			{
				//multiplicando a nota pelo seu respectivo crédito
				multip = histAluno[i].mediaFinal * disciplina[i].creditos;
				
				//somando as multiplicações feitas 
				soma += multip;
				
				//somando os créditos;
				somaCredito += disciplina[i].creditos;
				
				//exibindo resultado
				printf("Disciplina: %s (%d)\t Media: %.2f\n", disciplina[j].nome, disciplina[j].codigo, histAluno[i].mediaFinal);
			}
		}
	}
	//calculando a média ponderada
	media = soma / (float)somaCredito;
	//retornando o resultado do CR
	printf("\nCoeficiente de Rendimento (CR): %.2f", media);
}
