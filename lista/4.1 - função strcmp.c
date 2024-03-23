/*/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/

#include <stdio.h>
int funcaoStrcmp(char s1[], char s2[]);
void main()
{
        char s1[20], s2[20];
        int retorno;

        printf("Digite a primeira String: ");
        fflush(stdin);
        gets(s1);

        printf("Digite a segunda String: ");
        fflush(stdin);
        gets(s2);

        //chamando a função STRCMP
        retorno = funcaoStrcmp(s1,s2);

        if(retorno == 0)
        {
                printf("\nAs strings sao iguais.\nRetorno: %d.",retorno);
        }
        else
        {
                if(retorno < 0)
                {
                        printf("\nA string %s vem antes da string %s alfabeticamente.\nRetorno: %d.",s1,s2,retorno);
                }
                else
                {
                        printf("\nA string %s vem antes da string %s alfabeticamente.\nRetorno: %d.",s2,s1,retorno);
                }
        }
}
//STRCMP - COMPARAR STRING ('s1'>'s2' = -1; 's1'=='s2' = 0; 's1'>'s2' = 1)
int funcaoStrcmp(char s1[], char s2[])
{
        int i;
        //percorrendo as strings
        for(i=0; s1[i] && s2[i] && (s1[i]==s2[i]); i++);

        //retornando o resultado da "subtração" das strings de acordo com a tabela ASCII
        return (s1[i]-s2[i]);
        
        
        
       /* OUTRA FORMA DE RETORNAR SEUS RESULTADOS, MAS NAO EFICIENTE POIS FALHA EM CASO DE STRINGS COMO "CASA" E "CASAMENTO", POIS NAO LÊ O FIM DAS DUAS E ENTENDE QUE SAO IGUAIS
        {
                if(s1[i] == s2[i])
                {
                        return 0;
                }
                else
                {
                        if(s1[i] > s2[i])
                        {
                                return -1;
                        }
                        else
                        {
                                return 1;
                        }
                }
        }*/
}

/*
        //STRCMP - COMPARAR STRING ('s1'>'s2' = -1; 's1'=='s2' = 0; 's1'>'s2' = 1)
        char s1[] = "Muito";
        char s2[] = "Bela";
        int resultado = strcmp(s1,s2);
        
        printf("O resultado da comparacao eh %d", resultado);
*/
