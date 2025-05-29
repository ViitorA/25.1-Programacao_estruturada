/* Os habitantes de Nlogônia são muito supersticiosos. Uma de suas crenças é que os números das casas de rua que têm um dígito repetido traz sorte ruim para os moradores. 
 * Portanto, eles nunca iriam viver em uma casa que tem o número 838 ou 1004, por exemplo.
 *
 * A rainha de Nlogônia ordenou a construção de uma nova avenida à beira-mar e quer atribuir para as novas casas apenas números sem dígitos repetidos, para evitar desconforto entre os seus súditos. 
 * Você foi nomeado por Sua Majestade para escrever um programa que, dado dois inteiros N e M, determine a quantidade máxima possível de casas que podem assumir um número entre N e M inclusive, 
 * sem que ocorram dígitos repetidos nestes números.
 *
 * Entrada:
 * Cada teste é descrito usando uma linha. A linha contém dois inteiros N e M, conforme descrito acima (1 ≤ N ≤ M ≤ 5000).
 *
 * Saída
 * Para cada caso de teste imprima um valor inteiro que representa a quantidade máxima possível de números de casa entre N e M inclusive, sem dígitos repetidos.
 *
 * Exemplo de Entrada:
 * 87 104
 * 989 1022
 * 22 25
 * 1234 1234
 *
 * Exemplo de Saída:
 * 14
 * 0
 * 3
 * 1
 */

#include <stdio.h>
#include <math.h>

long tamanho(long n);
long contaValidos(long n, long m);
int repetido(double n);

int main()
{
	long n,m;
	
	while(scanf("%ld %ld", &n, &m) == 2) {
		printf("%ld\n", contaValidos(n, m));
	}

	return 0;
}

long tamanho(long n)
{
	long i = 0;

	while(n > 0.9) {
		n /= 10;
		i++;	
	}

	return i;
}

long contaValidos(long n, long m)
{
	long validos = 0;

	while(n <= m) {
		if (!repetido(n)) validos++;

		n++;
	}

	return validos;
}

int repetido(double n)
{
	const float NUM_ORIGINAL = n;
	long contadorRepeticoes = 0;
		

	// Testa todos os dígitos de 0 a 9
	for(int digito = 0; digito < 10; digito++) {
		for(double i = tamanho(n); i > 0; i--) {
			// Seja n = 1004
			
			// 100.4
			n /= 10;

			// j = (100.4 - 100) = 0.4
			double j = (n - (long)n);

			// n = 100.4 - 0.4 = 100
			n -= j;

			// j = 0.4*10 = 4
			j = round(j*10);


			if(j == digito) contadorRepeticoes++; 
		}

		n = NUM_ORIGINAL;

		if(contadorRepeticoes > 1) return 1;

		contadorRepeticoes = 0;
	}

	return 0;
}

