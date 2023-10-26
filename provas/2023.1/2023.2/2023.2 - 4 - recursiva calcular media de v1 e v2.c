#include <stdio.h>
#define TAM 5
float mediaIntervaloRecursiva(int vetor[], int tamanho, int num1, int num2, int i, float soma, int cont);
void main() 
{
    int vetor[] = {1, 2, 3, 4, 5}; 
    int num1 = 2, num2 = 4; 
    float media;

    // Chamando a fun��o 
    media = mediaIntervaloRecursiva(vetor, TAM, num1, num2, 0, 0.0, 0);
	
    printf("A media: %.2f.", media);
}
float mediaIntervaloRecursiva(int vetor[], int tamanho, int num1, int num2, int i, float soma, int cont)
{
    if(i == tamanho)
	{ 
		// Se o �ndice i � igual ao tamanho do vetor...
        return soma / cont; // ... retorna a m�dia (soma dividida pelo contador).
    } 
	else 
	{ 
		// Se o �ndice i n�o � igual ao tamanho do vetor...
        if(vetor[i] >= num1 && vetor[i] <= num2) // ... se o valor na posi��o i do vetor est� entre num1 e num2 (inclusive)...
		{ 
            soma += vetor[i]; // ... adiciona esse valor � soma...
            cont++; // ... e incrementa o contador.
        }
        // Chama a fun��o mediaIntervaloRecursiva novamente com o pr�ximo �ndice (i + 1), a nova soma e o novo contador.
        return mediaIntervaloRecursiva(vetor, tamanho, num1, num2, i + 1, soma, cont);
    }
} 
