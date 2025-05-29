#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// typedef tipo_pre_definido novo_nome;
typedef int* p_int;
typedef float Vetor[4]; // Vetor float de 4 posições
	
// Struct - tipo estruturado de dados
// Ex.: Ponto no espaço bidimensional -> representado por duas coordenadas (x,y) mas tratado como um único objeto
// Ex. 2: Dados associados a um aluno -> nome,matrícula,cpf,endereço, etc. estruturados em um único objeto

struct Ponto {
	float x; // Dados simples
	float y;
};

typedef char String[40];
typedef int Vetor15[15];

struct Endereco {
	String rua, bairro, cidade;
	int num;
	int cep[10];
}; 

typedef struct Aluno { // Usamos typedef aqui para evitar ter que escrever struct Aluno toda vez que for declarar variável
	struct Endereco ender; // Dados Compostos - Aninhamento de estruturas
	String nome;
	int matricula;
	Vetor15 CPF;
} Aluno;

// Passagem de tipo estruturado p/a função
// Caso tivesse usado o typedef: float distancia(Ponto *p, Ponto *q);
float distancia(struct Ponto p, struct Ponto q) {
	float dist = sqrt( (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y) );
	return dist;
}

int main() {
	p_int npi = malloc(sizeof(int));
	*npi = 25;
	printf("%p -> %d\n", npi, *npi);
	free(npi);

	Vetor v;
	v[0] = 3;
	printf("%f\n", v[0]);

/* STRUCT */
	struct Ponto p1;
	struct Ponto p2;

	puts("Digite as coordenadas do ponto 1: ");
	scanf("%f %f", &p1.x, &p1.y);
	printf("O ponto fornecido foi: (%.1f,%.1f)\n", p1.x, p1.y);		

	puts("Digite as coordenadas do ponto 2: ");
	scanf("%f %f", &p2.x, &p2.y);
	printf("O ponto fornecido foi: (%.1f,%.1f)\n", p2.x, p2.y);

	float dist = distancia(p1, p2);
	printf("A distância entre esses pontos é: %.2f\n", dist); 

// Ponteiro p/a estrutura
	// 1. Declara o ponteiro
	Aluno *aluno1;

	// 2. Aloca memória para a struct
	aluno1 = malloc(sizeof(struct Aluno));
	if (aluno1 == NULL) {
		printf("Erro na alocação de memória!\n");
		return 1;
	}

	// 3. Agora pode acessar os campos
	// (*aluno1).matricula = 123456 ou
	aluno1->matricula = 123456;
	strcpy(aluno1->nome, "Maria Ribeiro");
	
	// Não se pode usar &alunoe1.nome pois é ponteiro	
	printf("%s | %d\n", (*aluno1).nome, aluno1->matricula);
	
	free(aluno1);
	aluno1 = NULL; // evita "dangling pointers" e previne acesso à memória já liberada

	

	return 0;
}

