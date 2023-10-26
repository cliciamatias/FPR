/*Questão 01 [2,5 pontos]:
Dada a função recursiva apresentada abaixo, pede-se:
a. O caso base e o seu objetivo no desenvolvimento de funções recursivas;
b. O caso geral e o seu objetivo no desenvolvimento de funções recursivas;
c. O resultado do comando funcao (15,23); disparado pela função main, mostrando a sequência de chamadas,
assim como tudo que é exibido ao usuário.*/
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



/*A função funcao é uma função recursiva que recebe dois argumentos inteiros, x e y, 
e executa uma série de chamadas recursivas até que x seja igual a y. Vamos analisar a função em partes:

a. Caso Base: O caso base de uma função recursiva é a condição que determina quando a recursão deve parar. 
No caso da função funcao, o caso base é quando x é igual a y. O objetivo do caso base é evitar que a 
recursão continue indefinidamente.

b. Caso Geral: O caso geral é o bloco de código que é executado quando a condição do caso base não é atendida. 
No caso da função funcao, o caso geral inclui a impressão dos valores de x e y e, em seguida, faz chamadas 
recursivas com x aumentado em 1 e y diminuído em 2 se x for menor que y, ou x diminuído em 2 e y aumentado 
em 3 se x for maior que y. O objetivo do caso geral é avançar em direção ao caso base.

c. Agora, vamos executar a função funcao(15, 23):

x = 15 e y = 23 (impressão)
Chamada recursiva: funcao(16, 21)
x = 16 e y = 21 (impressão)
Chamada recursiva: funcao(14, 24)
x = 14 e y = 24 (impressão)
Chamada recursiva: funcao(16, 21) (observe que estamos retrocedendo agora)
x = 16 e y = 21 (impressão)
Chamada recursiva: funcao(14, 24) (novamente, retrocedendo)
... continua alternando entre 16, 21 e 14, 24 ...
Retorno para a chamada anterior funcao(14, 24)
Continua com a próxima instrução após a chamada recursiva
Retorno para a chamada original funcao(16, 21)
Continua com a próxima instrução após a chamada recursiva
Retorno para a chamada inicial funcao(15, 23)
Continua com a próxima instrução após a chamada recursiva
Este processo de chamadas e retornos recursivos continuará até que x seja igual a y. 
A saída será uma série de impressões dos valores de x e y em cada etapa da recursão. 
Observe que as chamadas retrocedem quando x é maior que y, o que cria uma estrutura 
de árvore de chamadas recursivas.*/
