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
