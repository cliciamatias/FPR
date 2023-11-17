/*Questão 01:

Desenvolver uma função que, dado um arquivo 

texto, verifique o número de caracteres no 

mesmo.
*/
#include<stdio.h>
void main()
{
    char nomeArq[30] = "questao1";
    int quant = quantCaracteres(nomeArq);
    
    printf("numero de caracteres no arquivo: %d", quant);
}
int quantCaracteres(char nomeArq[])
{
    int cont=0;
    char caracter;
    FILE* arquivo;
    
    arquivo = fopen(nomeArq, "r");
    if(arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo.");
    }
    else
    {
        while(fscanf(arquivo,"%c", &caracter) != EOF)
        {
            cont++;
        }
        fclose(arquivo);
    }
    return cont;
}
