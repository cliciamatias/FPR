/*QUESTÃO 02: 
Desenvolver uma função que, dada uma matriz 
M15×20, determine se um número X se encontra 
na linha L da matriz.*/
#include <stdio.h>
int encontrarXnaLinha(int m[15][20]);
void main()
{
    int i, j, num=1, retorno;
    int matriz[15][20];
    
    for(i=0;i<15;i++)
    {
        for(j=0;j<20;j++)
        {
            matriz[i][j]=num;
            num++;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
   retorno= encontrarXnaLinha(matriz);
   if(retorno == 1)
   {
       printf("Ha este nunero na linha");
   }
   else 
   {
       printf("NAO ha esta numero na linha");
   }
}   
int encontrarXnaLinha(int m[15][20])
{
    int i,j, l, x;
    
    
    printf("\nDigite a linha: ");
    scanf("%d", &l);
    printf("\nDigite o numero X a ser encontrado na linha %d: ", l);
    scanf("%d", &x);
    
    for(i=0; i<15; i++)
    {
        for(j=0; j<20; j++)
        {
            if(m[l][j]==x)
            {
                return 1;
            }
        }
      //  printf("\n");
    }
    return 0;
}
