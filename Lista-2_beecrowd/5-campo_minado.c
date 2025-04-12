/* Leonardo Viana é um garoto fascinado por jogos de tabuleiro. Nas férias de janeiro, ele aprendeu um jogo chamado "Campo minado", que é jogado em um tabuleiro com N células dispostas na horizontal. 
 * O objetivo desse jogo é determinar, para cada célula do tabuleiro, o número de minas explosivas nos arredores da mesma (que são a própria célula e as células imediatamente vizinhas à direita e à esquerda, 
 * caso essas existam). Por exemplo: 0 1 1 0 1 (1 é onde tem minas)
 * 
 * A primeira célula não possui nenhuma mina explosiva, mas é vizinha de uma célula que possui uma mina explosiva. Nos arredores da segunda célula temos duas minas, e o mesmo acontece para a terceira e quarta células; 
 * a quinta célula só tem uma mina explosiva em seus arredores: 1 2 2 2 1
 *
 * Leonardo sabe que você participa da OBI e resolveu lhe pedir para escrever um programa de computador que, dado um tabuleiro, imprima o número de minas na vizinhança de cada posição. Assim, ele poderá conferir as 
 * centenas de tabuleiros que resolveu durante as férias.
 *
 * Entrada
 * A primeira linha da entrada contém um inteiro N (1 ≤ N ≤ 50) indicando o número de células no tabuleiro. O tabuleiro é dado nas próximas N linhas. A i-ésima linha seguinte contém 0 se não existe mina na i-ésima 
 * célula do tabuleiro e 1 se existe uma mina na i-ésima célula do tabuleiro.
 *
 * Saída
 * A saída é composta por N linhas. A i-ésima linha da saída contém o número de minas explosivas nos arredores da i-ésima célula do tabuleiro.
 *
 * Exemplo de Entrada:	| Exemplo de Saída:
 * 5			| 1
 * 0			| 2
 * 1			| 2
 * 1			| 2
 * 0			| 1
 * 1
 */


#include <stdio.h>
#include <string.h>

void imprimir_vetor(int n, int vetor[]) 
{
	for(int i = 0; i < n; i++) {
		printf("%d\n", vetor[i]);
	}
}

void analisar_vetor(int n, int vetor[])
{
	int minas[n];

	for(int i = 0; i < n; i++) {
		// Com += ele vai somar com algum valor aleatório que tinha na memória
		minas[i] = vetor[i];

		if(i > 0) minas[i] += vetor[i-1];
		if(i < n-1) minas[i] += vetor[i+1];
	}


	memcpy(vetor, minas, sizeof(minas));
}

int main()
{
	int n;
	scanf("%d", &n);

	int tabuleiro[n];

	for(int i = 0; i < n; i++) {
		scanf("%d", &tabuleiro[i]);
	}

	analisar_vetor(n,tabuleiro);
	imprimir_vetor(n,tabuleiro);

	return 0;
}
