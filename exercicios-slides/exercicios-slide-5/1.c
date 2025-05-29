#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int N, int *vetor)
{
	printf("Digite os %d valores do vetor:\n", N);
	for(int i = 0; i < N; i++) {
		scanf("%d", vetor+i);
	}
	
}

void mostrar_vetor(int N, int *vetor)
{
	for(int i = 0; i < N; i++) {
		printf("%d ", *(vetor+i));
	}
	printf("\n");
}

int main()
{
	int N, X;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &N);
	
	if(N <= 0) {
		printf("Vetor inválido!\n");
		return 1;
	}

	int *vet;
	vet = (int*) malloc(N*sizeof(int));

	if( vet == NULL) {
		printf("Erro na alocação de memória!\n");
		return 1;
	}

	preencher_vetor(N, vet);
	mostrar_vetor(N, vet);

	printf("Digite o número que você procura: ");
	scanf("%d", &X);

	int **enderecos = NULL;
	int contador = 0;

	for (int i = 0; i < N; i++) {
		if( *(vet+i) == X) { // ou vet[i] == X
			int **temp = (int **) realloc(enderecos, (contador+1) * sizeof(int *));

			if(temp == NULL) {
				printf("Erro na realocação de memória!\n");
				free(vet);
				free(enderecos);
				return 1;
			}

			enderecos = temp;

			*(enderecos+contador) = vet+i;
			contador++;
		}
	}

	if(contador == 0) {
		printf("O número não foi encontrado no vetor.\n");
	} else {
		printf("Esse número aparece nos endereços: ");

		for(int i = 0; i < contador; i++) {
			printf("%p", (void *) *(enderecos+i));
		}

		printf("\n");
	}
		
	
	free(vet);
	free(enderecos);

	return 0;
}
