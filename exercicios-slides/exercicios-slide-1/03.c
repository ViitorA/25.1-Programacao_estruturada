/* Escreva um programa que dados n números inteiros positivos, seja informada a soma dos números que são primos */
#include <stdio.h>


int primo(int n);



int main()
{
	primo(20);

	return 0;
}


int primo(int n) {
	int divs = 0;

	for(int i = 1; i <= n; i++) {
		if ( (n%i) == 0)
			divs++;
	}


}
