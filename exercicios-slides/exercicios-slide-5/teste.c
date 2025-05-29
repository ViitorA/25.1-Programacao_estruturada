#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Quero criar uma matriz de 4x4
	int qtd_linhas = 4;
	int qtd_colunas = 4;

	// MÉTODO 1: Usando vetor simples, criar um vetor com M*N elementos
	int *mat;

	mat = (int*) malloc(qtd_linhas*qtd_colunas*sizeof(int));

	for(int i = 0; i < qtd_linhas; i++) {
		for(int j = 0; j < qtd_colunas; j++) {
			mat[i*4+j] = i+j;
		}
	}

	for(int i = 0; i < qtd_linhas; i++) {
		for(int j = 0; j < qtd_colunas; j++) {
			printf("%d ", mat[i*4+j]);
		}
		printf("\n");
	}

	// Liberação
	free(mat);

	printf("\n==================\n");

	// MÉTODO 2: Vetor de ponteiros
	
	int **mat2;

	// Passo 1: Aloca um vetor de ponteiros (linhas)
	mat2 = (int**) malloc(qtd_linhas*sizeof(int*));

	// Passo 2: p/a cada linha, aloca um vetor de inteiros (colunas)
	for(int i = 0; i < qtd_linhas; i++)
	       mat2[i] = (int*) malloc(qtd_colunas*sizeof(int));
	
	for(int i = 0; i < qtd_linhas; i++) {
		for(int j = 0; j < qtd_colunas; j++) {
			mat2[i][j] = i+j;
		}
	}	

	for(int i = 0; i < qtd_linhas; i++) {
		for(int j = 0; j < qtd_colunas; j++) {
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}	

	// Liberação
	for(int i = 0; i < qtd_linhas; i++)
		free(mat2[i]); // libera cada linha
	
	free(mat2); // Libera o vetor de ponteiros

	return 0;
}
