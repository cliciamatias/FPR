/*Questão 02:
Desenvolver uma função que, dado um arquivo 
texto, verifique o número de vezes que um 
determinado caracter aparece no arquivo.
*/
#include<stdio.h>
void main()
{
    char nomeArq[30] = "questao1";
    char c = 'a';
    int quant = quantCaracteres(nomeArq, c);
     
    
    printf("numero de caracteres no arquivo: %d", quant);
}
int quantCaracteres(char nomeArq[], char c)
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
            if(caracter == c)
            {
                cont++;
            }
        }
        fclose(arquivo);
    }
    return cont;
}
