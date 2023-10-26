/*Questão 04 [2,5 pontos]:
Considerando a existência de um vetor, onde cada posição armazena os seguintes dados: nome do aluno, código da
disciplina, nota na AV1 e nota na AV2, pede-se o desenvolvimento de uma função que, dado um vetor nos moldes do
descrito, crie (e retorne) um outro vetor com os seguintes dados em cada posição: código da disciplina, status
(Aprovado, Reprovado ou Em AVF) e a quantidade de alunos nesta situação.
Exemplo:
JOAO PEDRO MARIA ANA CARLOS PAULO KATIA SILVIA GLORIA ANTONIO
FAC   ESD   FPR  FAC  FAC    FPR   ESD   FAC    FPR     ESD
10,0  6,0  10,0  8,0  7,0    5,0   5,0   2,0    4,0     3,0
8,0   7,0   5,0  3,0  7,0    2,0   9,0   4,0    1,0     4,0
____________________________________________________________
FAC   ESD   FPR  FAC  FPR    FAC   ESD
apr   apr   apr  AVF  rep    apr   rep
 2     2     1    1    2      1     1*/
//importa??o de bibliotecas
#include <stdio.h>
#include <string.h>

//definicao de tipos
typedef struct
{
	char nome[20];
	char disciplina[4];
	float av1;
	float av2;
} tipoAluno;

typedef struct
{
	char nome[4];
	char situacao[4];
	int quantAlunos;
} tipoDisciplina;

//prot?tipos das fun??es
void dados(tipoAluno vetorAlunos[], tipoDisciplina vetDisciplinas[], int tamanho);
void inicializarAlunos (tipoAluno alunos[], int tamanho);
void exibirDisciplinas (tipoDisciplina vetDisciplinas[], int tamanho);

//main
void main ()
{
	//declara??o de vari?veis
	tipoAluno vetorAlunos[10];
	tipoDisciplina vetDisciplinas[10];	 
	int quantDisciplinas;
		 
	//inicializando o vetor de alunos
	inicializarAlunos (vetorAlunos, 10);
	
	//chamando a fun??o e retornando o vetor vetDisciplinas preenchido
	dados(vetorAlunos, vetDisciplinas, quantDisciplinas);
	
	//exibindo o vetor VetDisciplinas
	exibirDisciplinas (vetDisciplinas, quantDisciplinas);
}
	
//implementa??o das fun??es
void dados(tipoAluno vetorAlunos[], tipoDisciplina vetDisciplinas[], int tamanho)
{
	int i;
	for(i=0; i<tamanho; i++)
	{
		if(vetorAlunos[i].av1 >= 6)
		{
			printf("oiii");
		}
	}
}

void inicializarAlunos (tipoAluno alunos[], int tamanho)
{
	//posicao 0
	strcpy (alunos[0].nome, "JOAO");
	strcpy (alunos[0].disciplina, "FAC");
	alunos[0].av1 = 10.0;
	alunos[0].av2 = 8.0;
	
	//posicao 1
	strcpy (alunos[1].nome, "PEDRO");
	strcpy (alunos[1].disciplina, "ESD");
	alunos[1].av1 = 6.0;
	alunos[1].av2 = 7.0;
	
	//posicao 2
	strcpy (alunos[2].nome, "MARIA");
	strcpy (alunos[2].disciplina, "FPR");
	alunos[2].av1 = 10.0;
	alunos[2].av2 = 5.0;
	
	//posicao 3
	strcpy (alunos[3].nome, "ANA");
	strcpy (alunos[3].disciplina, "FAC");
	alunos[3].av1 = 8.0;
	alunos[3].av2 = 3.0;
	
	//posicao 4
	strcpy (alunos[4].nome, "CARLOS");
	strcpy (alunos[4].disciplina, "FAC");
	alunos[4].av1 = 7.0;
	alunos[4].av2 = 7.0;
	
	//posicao 5
	strcpy (alunos[5].nome, "PAULO");
	strcpy (alunos[5].disciplina, "FPR");
	alunos[5].av1 = 5.0;
	alunos[5].av2 = 2.0;
	
	//posicao 6
	strcpy (alunos[6].nome, "KATIA");
	strcpy (alunos[6].disciplina, "ESD");
	alunos[6].av1 = 5.0;
	alunos[6].av2 = 9.0;
	
	//posicao 7
	strcpy (alunos[7].nome, "SILVIA");
	strcpy (alunos[7].disciplina, "FAC");
	alunos[7].av1 = 2.0;
	alunos[7].av2 = 4.0;
	
	//posicao 8
	strcpy (alunos[8].nome, "GLORIA");
	strcpy (alunos[8].disciplina, "FPR");
	alunos[8].av1 = 4.0;
	alunos[8].av2 = 1.0;
	
	//posicao 9
	strcpy (alunos[9].nome, "ANTONIO");
	strcpy (alunos[9].disciplina, "ESD");
	alunos[9].av1 = 3.0;
	alunos[9].av2 = 4.0;
}

void exibirDisciplinas (tipoDisciplina vetDisciplinas[], int tamanho)
{
	int i;
	
	for (i=0;i<tamanho;i++)
	{
		printf ("Disciplina: %s\n", vetDisciplinas[i].nome);
		printf ("Situacao: %s\n", vetDisciplinas[i].situacao);
		printf ("Quantidade de alunos: %d\n\n", vetDisciplinas[i].quantAlunos);
	}
}

