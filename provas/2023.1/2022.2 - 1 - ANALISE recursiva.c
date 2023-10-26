/*Quest�o 01 [2,5 pontos]:
Dada a fun��o recursiva apresentada abaixo, pede-se:
a. O caso base e o seu objetivo no desenvolvimento de fun��es recursivas;
b. O caso geral e o seu objetivo no desenvolvimento de fun��es recursivas;
c. O resultado do comando funcao (15,23); disparado pela fun��o main, mostrando a sequ�ncia de chamadas,
assim como tudo que � exibido ao usu�rio.*/
void funcao (int x, int y) 
{
	if (x != y) //caso baso: quando x for igual a y para
	{
		printf ("x = %d e y = %d\n", x, y);
		if (x < y) //caso geral
		{
			funcao (x+1, y-2);
		} 
		else 
		{
			funcao (x-2,y+3);
		}
	}
}



/*A fun��o funcao � uma fun��o recursiva que recebe dois argumentos inteiros, x e y, 
e executa uma s�rie de chamadas recursivas at� que x seja igual a y. Vamos analisar a fun��o em partes:

a. Caso Base: O caso base de uma fun��o recursiva � a condi��o que determina quando a recurs�o deve parar. 
No caso da fun��o funcao, o caso base � quando x � igual a y. O objetivo do caso base � evitar que a 
recurs�o continue indefinidamente.

b. Caso Geral: O caso geral � o bloco de c�digo que � executado quando a condi��o do caso base n�o � atendida. 
No caso da fun��o funcao, o caso geral inclui a impress�o dos valores de x e y e, em seguida, faz chamadas 
recursivas com x aumentado em 1 e y diminu�do em 2 se x for menor que y, ou x diminu�do em 2 e y aumentado 
em 3 se x for maior que y. O objetivo do caso geral � avan�ar em dire��o ao caso base.

c. Agora, vamos executar a fun��o funcao(15, 23):

x = 15 e y = 23 (impress�o)
Chamada recursiva: funcao(16, 21)
x = 16 e y = 21 (impress�o)
Chamada recursiva: funcao(14, 24)
x = 14 e y = 24 (impress�o)
Chamada recursiva: funcao(16, 21) (observe que estamos retrocedendo agora)
x = 16 e y = 21 (impress�o)
Chamada recursiva: funcao(14, 24) (novamente, retrocedendo)
... continua alternando entre 16, 21 e 14, 24 ...
Retorno para a chamada anterior funcao(14, 24)
Continua com a pr�xima instru��o ap�s a chamada recursiva
Retorno para a chamada original funcao(16, 21)
Continua com a pr�xima instru��o ap�s a chamada recursiva
Retorno para a chamada inicial funcao(15, 23)
Continua com a pr�xima instru��o ap�s a chamada recursiva
Este processo de chamadas e retornos recursivos continuar� at� que x seja igual a y. 
A sa�da ser� uma s�rie de impress�es dos valores de x e y em cada etapa da recurs�o. 
Observe que as chamadas retrocedem quando x � maior que y, o que cria uma estrutura 
de �rvore de chamadas recursivas.*/
