/* Escreva um programa em C que decide se um número é primo. Pergunte ao usuário qual número ele deseja verificar. */

#include <stdio.h>

int primo(int n);

int main()
{
	int numero;
	
	printf("Qual número você deseja verificar se é primo?\n");
	scanf("%d", &numero);
	
	if(primo(numero)) {
		printf("É primo\n");
	} else{
		printf("Não é primo\n");
	}
	

}

int primo(int n) {
	int divs = 0;

	for (int i = 1; i <= n; i++) {
		if ( (n%i) == 0)
			divs++;
	}

	printf("Divs: %d\n", divs);

	if (divs == 2)
		return 1;

	return 0;
}
