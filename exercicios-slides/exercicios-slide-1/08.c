/* Escreva um programa em C que imprima os N primeiros termos da série de Fibonacci, lembrando que esta série é definida da seguinte forma:
 * Termo 1 = 1
 * Termo 2 = 1
 * Termo (x +1) = termo (x) + termo (x − 1)
 */
#include <stdio.h>

int fibonacci(int n);

int main()
{
	int n = 5;
	fibonacci(n);

	return 0;
}

int fibonacci(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;

	printf("1 ");

	int a = 0, b = 1, c;
	for(int i=2;i <= n; i++){	
		c = a + b;
		a = b;
		b = c;

		printf("%d ", c);
	}

	return b;
}
