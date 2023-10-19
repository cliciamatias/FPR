/*Quest�o 07:
Desenvolver uma fun��o recursiva que
determine o n�mero de caracteres comuns
entre duas strings s1 e s2.*/
#include <stdio.h>
#include <string.h>
int caracteresComuns(char s1[], char s2[], int i, int j);
void main()
{
    char s1[] = "pamonha";
    char s2[] = "linha";

    int comuns = caracteresComuns(s1, s2, 0, 0);

    printf("N�mero de caracteres comuns: %d\n", comuns);
}
int caracteresComuns(char s1[], char s2[], int i, int j)
{
    // Caso base: quando uma das strings chega ao fim
    if (s1[i] == '\0' || s2[j] == '\0') {
        return 0;
    }

    // Se os caracteres s�o iguais, acrescenta 1 e chama recursivamente para os pr�ximos caracteres
    if (s1[i] == s2[j]) {
        return 1 + caracteresComuns(s1, s2, i + 1, j + 1);
    } else {
        // Se os caracteres n�o s�o iguais, chama recursivamente para todas as combina��es poss�veis
        int comuns1 = caracteresComuns(s1, s2, i + 1, j);
        int comuns2 = caracteresComuns(s1, s2, i, j + 1);
        if (comuns1 > comuns2) {
            return comuns1;
        } else {
            return comuns2;
        }
    }
}
