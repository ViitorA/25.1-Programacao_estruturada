/* Leia um caractere maiúsculo, que indica uma operação que deve ser realizada e uma matriz M[12][12]. Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão 
 * acima da diagonal principal da matriz, conforme ilustrado abaixo.
 *
 * \ # # # # # # # # # # #
 * 0 \ # # # # # # # # # # 
 * 0 0 \ # # # # # # # # # 
 * 0 0 0 \ # # # # # # # #
 * 0 0 0 0 \ # # # # # # #
 * 0 0 0 0 0 \ # # # # # #
 * 0 0 0 0 0 0 \ # # # # #
 * 0 0 0 0 0 0 0 \ # # # #
 * 0 0 0 0 0 0 0 0 \ # # #
 * 0 0 0 0 0 0 0 0 0 \ # #
 * 0 0 0 0 0 0 0 0 0 0 \ #
 * 0 0 0 0 0 0 0 0 0 0 0 \
 *
 * Entrada
 * A primeira linha de entrada contem um único caractere Maiúsculo O ('S' ou 'M'), indicando a operação (Soma ou Média) que deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto flutuante que compõem a matriz.
 *
 * Saída
 * Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.
 *
 * Exemplo de Entrada:	| Exemplo de Saída:
 * S			| 12.6
 * 1.0
 * 0.0
 * -3.5
 * 2.5
 * 4.1
 * ...
 */

#include <stdio.h>

void ler_matriz(int N, float M[N][N])
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%f", &M[i][j]);
		}
	}

}

void operar_matriz(char operacao, int N, float M[N][N])
{
	if(operacao == 'S'){
		float soma = 0.0;	

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(j > i) soma += M[i][j];
			}
		}

		printf("%.1f\n", soma);

	} else {
		float media = 0.0;
		int elementos = 0;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(j > i) {
					media += M[i][j];
					elementos++;
				}
			}
		}

		printf("%.1f\n", media /= elementos);
	}

}

int main()
{
	const int N = 12;
	float M[N][N];
	
	char C;
	scanf("%c", &C);
	
	ler_matriz(N,M);
	operar_matriz(C, N, M);

	return 0;
}
