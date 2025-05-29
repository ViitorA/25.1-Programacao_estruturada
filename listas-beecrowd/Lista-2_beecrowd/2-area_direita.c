/* Leia um caractere maiúsculo, que indica uma operação que deve ser realizada e uma matriz M[12][12]. Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão na área direita da matriz, 
 * conforme ilustrado abaixo.
 *
 * \ 0 0 0 0 0 0 0 0 0 0 /
 * 0 \ 0 0 0 0 0 0 0 0 / #
 * 0 0 \ 0 0 0 0 0 0 / # #
 * 0 0 0 \ 0 0 0 0 / # # #
 * 0 0 0 0 \ 0 0 / # # # #
 * 0 0 0 0 0 \ / # # # # #
 * 0 0 0 0 0 / \ # # # # #
 * 0 0 0 0 / 0 0 \ # # # #
 * 0 0 0 / 0 0 0 0 \ # # #
 * 0 0 / 0 0 0 0 0 0 \ # #
 * 0 / 0 0 0 0 0 0 0 0 \ #
 * / 0 0 0 0 0 0 0 0 0 0 \
 *
 * Entrada
 * A primeira linha de entrada contem um único caractere Maiúsculo O ('S' ou 'M'), indicando a operação (Soma ou Média) que deverá ser realizada com os elementos da matriz. 
 * Seguem os 144 valores de ponto flutuante que compõem a matriz.
 *
 * Saída
 * Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.
 *
 * Exemplo de Entrada:	| Exemplo de Saída:
 * S			| 111.4
 * 1.0
 * 330.0
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
                                if(j > (N-1-i) && j > i) soma += M[i][j];
                        }
                }

                printf("%.1f\n", soma);

        } else {
                float media = 0.0;
                int elementos = 0;

                for(int i = 0; i < N; i++) {
                        for(int j = 0; j < N; j++) {
                                if(j > (N-1-i) && j > i) {
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
	char C;
	float M[12][12];

	scanf("%c", &C);

	ler_matriz(12, M);

	operar_matriz(C, 12, M);

	return 0;
}
