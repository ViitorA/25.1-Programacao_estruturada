#include <stdio.h>
#include <stdlib.h> // Biblioteca necessária para a alocação dinâmica

void exemplo1()
{
	// malloc - Recebe o espaço a ser alocado e aloca o espaço contíguo de memória
	// Retorno é void: ponteiro genérico
	int *vetor;

	// vetor = malloc(10*4)
	// O ponteiro vai ser void, tecnicamente você pode fazer isso, mas é sempre bom fazer cast e deixar claro o tipo
	vetor = (int *) malloc(10*sizeof(int)); // vetor de 10 posições	
	
	// Se não tiver espaço, malloc retorna NULL
	if(vetor == NULL) printf("Não há espaço");

	// ATENÇÃO: O ESPAÇO DEVE SER LIBERADO SEMPRE DEPOIS QUE FOR UTILIZADO
	free(vetor);
}

void exemplo2()
{
	int *v;
	v = malloc(1000 * sizeof(int));

	for(int i = 0; i < 990; i++) 
		scanf("%d", &v[i]);

	// realloc(var_anterior, tamanho novo)
	v = realloc(v, 2000 * sizeof(int));

	for(int i = 990; i < 2000; i++)
		scanf("%d", &v[i]);
}

void matrizes_dinamicas()
{
	/*
	float *mat; -> matriz representada por um vetor
	mat = (float*) malloc(m*n*sizeof(float));
	Acesso ao elemento mat[i][j]: mat[i*n+j], onde n é o numero de colunas
	*/
}

void vetor_de_ponteiros()
{
	int l,c;
	float **mat;

	mat = (float**) malloc(l*sizeof(float*));

	for(int i = 0; i<l; i++)
		mat[i] = (float*) malloc(c*sizeof(float));

	// Acesso: mat[i][j]
	// Liberação:
	// for(int i = 0; i < m; i++)
	//	free(mat[i]);
	//
	// free(mat);
}

// Passando ponteiros para funções:
// void f(float **mat);
// void f(float (*mat)[3]);
// void f(float mat[][3]);

/* RETORNANDO PONTEIROS
 * Não retorne o endereço de uma variável local, já que quando a função termina, aquela memória é liberada
 * Por exemplo, essa função aqui vai dar ruim:
 * int * getRandom( ) {
 * 	int r[10];
 * 	int i;
 *	// set the seed 
 *	srand( (unsigned)time( NULL ) );
 *	for ( i = 0; i < 10; ++i) {
 * 		r[i] = rand();
 *		printf("%d\n", r[i] );
 *	}
 *	return r;
 * }
 *
 * JEITO CERTO: Lembrando que isso funciona porque com malloc, aquela memória só é liberada depois do free()
 * float *alocar_vetor_real (int n) {
 * 	float *v;
 * 	// aloca o vetor
 * 	v = (float *) malloc (n*sizeof(float));
 * 	if (v == NULL) {
 * 	printf ("** Erro: Memoria Insuficiente **");
 * 	return (NULL);
 * 	}
 *	 return v; // retorna o ponteiro para o vetor
 * }
 * 
*/

int **AlocaMatriz(int m, int n){
	int **M;
	int i;
	M = (int **)malloc(sizeof(int *)*m);
	if(M == NULL){
		printf("Memoria insuficiente.\n");
		exit(1);
	}

	for(i = 0; i < m; i++){
		M[i] = (int *)malloc(sizeof(int)*n);

		if(M[i] == NULL){
			printf("Memoria insuficiente.\n");
			exit(1);
		}
	}
	return M;
}

void LiberaMatriz(int **M, int m){
	int i;
	for(i = 0; i < m; i++)
		free(M[i]);
	free(M);
}

