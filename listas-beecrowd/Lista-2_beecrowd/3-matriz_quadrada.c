/* Escreva um algoritmo que leia um inteiro N (0 ≤ N ≤ 100), correspondente a ordem de uma matriz M de inteiros, e construa a matriz de acordo com o exemplo abaixo.
 * 
 * Entrada
 * A entrada consiste de vários inteiros, um valor por linha, correspondentes as ordens das matrizes a serem construídas. O final da entrada é marcado por um valor de ordem igual a zero (0).
 *
 * Saída
 * Para cada inteiro da entrada imprima a matriz correspondente, de acordo com o exemplo. Os valores das matrizes devem ser formatados em um campo de tamanho 3 justificados à direita e separados por espaço. 
 * Após o último caractere de cada linha da matriz não deve haver espaços em branco. Após a impressão de cada matriz deve ser deixada uma linha em branco.
 *
 * Exemplo Entrada	| Exemplo Saída
 * 1			| 1
 * 2			|
 * 3			| 1 1
 * 4			| 1 1
 * 5			|
 * 0			| 1 1 1
 * 			| 1 2 1
 * 			| 1 1 1
 * 			|
 * 			| 1 1 1 1
 * 			| 1 2 2 1
 * 			| 1 2 2 1
 * 			| 1 1 1 1
 * 			|
 * 			| 1 1 1 1 1
 * 			| 1 2 2 2 1
 * 			| 1 2 3 2 1
 * 			| 1 2 2 2 1
 * 			| 1 1 1 1 1
 */

#include <stdio.h>

void escrever_matriz(int n, int matriz[n][n]) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%3d", matriz[i][j]);
			
			if( j < n-1) printf(" ");	
		}
		printf("\n");
	}
}

void construir_matriz(int n, int matriz[n][n])
{
	int centro = n/2;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int distancia = (i < j) ? i : j;
			distancia = (distancia < n - 1 - i) ? distancia : n - 1 - i;
			distancia = (distancia < n - 1 - j) ? distancia: n - 1 - j;
			matriz[i][j] = distancia + 1;
		}
	}

}

int main()
{
	int n;

	while(1) {
		scanf("%d", &n);
		if(n == 0) break;

		int matriz[n][n];
		construir_matriz(n, matriz);
		escrever_matriz(n, matriz);
		printf("\n");
	}


	return 0;
}
