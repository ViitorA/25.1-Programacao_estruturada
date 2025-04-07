/* Dados dois números inteiros, n e m, quantos dígitos tem n^m ?
 * Exemplos:
 * 2 e 10 - 2^10 = 1024 - 4 dígitos
 * 3 e 9 - 3^9 = 19683 - 5 dígitos
 *
 * Entrada
 * A entrada é composta por vários casos de teste. A primeira linha tem um número inteiro C, representando a quantidade de casos de teste. 
 * As C linhas seguintes contém dois números inteiros N e M (1 <= N, M <= 100).
 *
 * Saída
 * Para cada caso de teste de entrada do seu programa, você deve imprimir um número inteiro contendo a quantidade de dígitos do resultado da potência calculada no respectivo caso de teste.
 *
 * Exemplo de Entrada:		| Exemplo de Saída:
 * 4				| 
 * 1 1				| 1
 * 2 10				| 4
 * 3 9				| 5
 * 100 100			| 201
 */

#include <stdio.h>
#include <math.h>

int calcularDigitos(int n, int m) 
{
	

	int resultado = floor(m*log10(n))+1;

	return resultado;
}

int main()
{
	int qtdCasos,n,m;

	scanf("%d", &qtdCasos);
 
	for(int i = 0; i < qtdCasos; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", calcularDigitos(n,m));
	}


	return 0;
}

