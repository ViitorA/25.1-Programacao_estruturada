#include "dados.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[80];

typedef struct endereco {
	String rua;
	int numero;
	String complemento;
	String bairro;
	String cep;
	String cidade;
	String estado;
	String pais;
} Endereco;

typedef struct telefone { 
	// Se fosse int, teria problemas pois o número 09405 seria o mesmo que 9405?
	// Se fosse um vetor int, ficaria ruim para o input depois
	char ddd[3]; // mais um caractere p/a o \0
	char numero[10];	
} Telefone;

typedef struct aniversario {
	int dia;
	int mes;
	int ano;
} Aniversario;

typedef struct pessoa {
	String nome;
	String email;
	Endereco endereco;
	Telefone telefone;
	Aniversario aniversario;
	String observacoes;
} Pessoa;


Pessoa *criar_agenda(int size) {
	Pessoa *agenda = (Pessoa*) malloc(sizeof(Pessoa)*size);
	
	if (agenda == NULL) {
		puts("MEMÓRIA INSUFICIENTE!");
		exit(1);
	}

	return agenda;
}

void imprimir_dados(Pessoa pessoa) {
	printf("====================\n");
	printf("Nome: %s\n", pessoa.nome);
	printf("E-Mail: %s\n", pessoa.email);
	printf("Endereço: \n");
		printf("\tCEP: %s\n", pessoa.endereco.cep);
		printf("\tRua: %s, num. %d\n", pessoa.endereco.rua, pessoa.endereco.numero);
		printf("\tComplemento: %s\n", pessoa.endereco.complemento);
		printf("\tBairro: %s\n", pessoa.endereco.bairro);
		printf("\tCidade: %s\n", pessoa.endereco.cidade);
		printf("\tEstado: %s\n", pessoa.endereco.estado);
		printf("\tPaís: %s\n\n", pessoa.endereco.pais);
	printf("Número de Telefone: %s %s\n", pessoa.telefone.ddd, pessoa.telefone.numero);
	printf("Aniversário: %d/%d/%d\n", pessoa.aniversario.dia, pessoa.aniversario.mes, pessoa.aniversario.ano);
	printf("Observações: %s\n", pessoa.observacoes);
	printf("====================\n");
}

void imprimir_agenda_parcialmente(Pessoa *agenda, int qtd_pessoas) {
	for (int i = 0; i < qtd_pessoas; i++) {
		printf("====================\n");
		printf("Nome: %s\n", agenda[i].nome);
		printf("E-Mail: %s\n", agenda[i].email);
		printf("Número de Telefone: %s %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
		printf("====================\n");
	}
}

void imprimir_agenda_completa(Pessoa *agenda, int qtd_pessoas) {
	for (int i = 0; i < qtd_pessoas; i++) {
		imprimir_dados(agenda[i]);
	}
}

void buscar_nome(char *nome, Pessoa *agenda) {
	for(int i = 0; i < 100; i++) {
		if(strcmp(agenda[i].nome, nome) == 0) {
			imprimir_dados(agenda[i]);
		}	
	}
}

void buscar_mes(int mes, Pessoa *agenda) {
	for(int i = 0; i < 100; i++) {
		if(agenda[i].aniversario.mes == mes) {
			imprimir_dados(agenda[i]);
		}
	}
}

void buscar_dia_mes(int dia, int mes, Pessoa *agenda) {
	for(int i = 0; i < 100; i++) {
		if(agenda[i].aniversario.mes == mes && agenda[i].aniversario.dia == dia) {
			imprimir_dados(agenda[i]);
		}
	}
}

void inserir_pessoa(Pessoa *agenda, int *qtd_pessoas) {
	String nome;

	puts("Inserir nome: ");
	scanf("%s", nome);	
	
	int posicao = *qtd_pessoas; // Assume que será inserido no final

	// Verifica onde inserir
	for (int i = 0; i < *qtd_pessoas; i++) {
		if( strcmp(nome, agenda[i].nome) < 0 ) { 
			posicao = i;
			break;	
		}	
	}

	for (int i = *qtd_pessoas; i > posicao; i--) {
		agenda[i] = agenda[i - 1]; // desloca os nomes posteriores para a direita
	}
	
	strcpy(agenda[posicao].nome, nome);

	puts("Inserir E-Mail: ");
	scanf("%s", agenda[posicao].email);

	puts("Inserir CEP: ");
	scanf("%s", agenda[posicao].endereco.cep);

	puts("Inserir Rua: ");
	scanf("%s", agenda[posicao].endereco.rua);

	puts("Inserir número: ");
	scanf("%d", &agenda[posicao].endereco.numero);

	puts("Inserir complemento: ");
	scanf("%s", agenda[posicao].endereco.complemento);

	puts("Inserir bairro: ");
	scanf("%s", agenda[posicao].endereco.bairro);

	puts("Inserir cidade: ");
	scanf("%s", agenda[posicao].endereco.cidade);

	puts("Inserir estado: ");
	scanf("%s", agenda[posicao].endereco.estado);

	puts("Inserir País: ");
	scanf("%s", agenda[posicao].endereco.pais);

	// Limpa o buffer
	while (getchar() != '\n');

	puts("Insira o número de telefone no formato \"dd nnnnnnnnn\"");
	char telefone_str[12];
	fgets(telefone_str, sizeof(telefone_str), stdin);
	sscanf(telefone_str, "%2s %9s", agenda[posicao].telefone.ddd, agenda[posicao].telefone.numero);

	// Limpa o buffer
	while (getchar() != '\n');
		
	puts("Insira o aniversário no formado DD/MM/AAAA: ");
	scanf("%d/%d/%d", &agenda[posicao].aniversario.dia, &agenda[posicao].aniversario.mes, &agenda[posicao].aniversario.ano);


	// Depois arrumar para poder aceitar nenhuma observação
	puts("Insira alguma observação especial: ");
	scanf("%s", agenda[posicao].observacoes);

	*qtd_pessoas += 1;
}

void remover_pessoa(Pessoa *agenda, int *qtd_pessoas, char *nome) {
	int posicao = -1;

	for(int i = 0; i < *qtd_pessoas; i++) {
		if (strcmp(agenda[i].nome, nome) == 0) {
			posicao = i;	
			break;
		}
	}

	if (posicao == -1) {
		puts("Pessoa não encontrada na agenda!");
		return;
	}

		
	// Desloca os elementos p/a a esquerda
	for( int i = posicao; i < (*qtd_pessoas) - 1; i++) {
		agenda[i] = agenda[i + 1];
	}
	
	*qtd_pessoas -= 1;
}
