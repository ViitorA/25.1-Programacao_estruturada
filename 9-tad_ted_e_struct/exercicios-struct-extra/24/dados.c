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


void limpar_buffer() {
	while (getchar() != '\n');
}

Pessoa *criar_agenda(int size) {
	Pessoa *agenda = (Pessoa*) malloc(sizeof(Pessoa)*size);
	
	if (agenda == NULL) {
		puts("MEMÓRIA INSUFICIENTE!");
		exit(1);
	}

	return agenda;
}

void imprimir_dados(Pessoa pessoa) {
	// Obs.: Em alguns eu não uso \n porque eu creio que seja por causa do fgets que ele já insere \n
	printf("====================\n");
	printf("Nome: %s", pessoa.nome);
	printf("E-Mail: %s\n", pessoa.email);
	printf("Endereço: \n");
		printf("\tCEP: %s\n", pessoa.endereco.cep);
		printf("\tRua: %s", pessoa.endereco.rua);
		printf("\tNúmero: %d\n", pessoa.endereco.numero);
		printf("\tComplemento: %s", pessoa.endereco.complemento);
		printf("\tBairro: %s", pessoa.endereco.bairro);
		printf("\tCidade: %s", pessoa.endereco.cidade);
		printf("\tEstado: %s", pessoa.endereco.estado);
		printf("\tPaís: %s\n", pessoa.endereco.pais);
	printf("Número de Telefone: %s %s\n", pessoa.telefone.ddd, pessoa.telefone.numero);
	printf("Aniversário: %d/%d/%d\n", pessoa.aniversario.dia, pessoa.aniversario.mes, pessoa.aniversario.ano);
	printf("Observações: %s\n", pessoa.observacoes);
	printf("====================\n");
}

void imprimir_agenda_parcialmente(Pessoa *agenda, int qtd_pessoas) {
	limpar_buffer();

	for (int i = 0; i < qtd_pessoas; i++) {
		if(i == 0) { 
			printf("====================\n");
		}
		printf("Nome: %s", agenda[i].nome);
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
	String usr_input;
	
	limpar_buffer();

	puts("Inserir nome: ");
	fgets(usr_input, sizeof(usr_input), stdin);
	
	int posicao = *qtd_pessoas; // Assume que será inserido no final

	// Verifica onde inserir
	for (int i = 0; i < *qtd_pessoas; i++) {
		if( strcmp(usr_input, agenda[i].nome) < 0 ) { 
			posicao = i;
			break;	
		}	
	}

	for (int i = *qtd_pessoas; i > posicao; i--) {
		agenda[i] = agenda[i - 1]; // desloca os nomes posteriores para a direita
	}
	
	strcpy(agenda[posicao].nome, usr_input);

	puts("Inserir E-Mail: ");
	scanf("%s", agenda[posicao].email);

	puts("Inserir CEP: ");
	scanf("%s", agenda[posicao].endereco.cep);
	
	limpar_buffer();
	puts("Inserir Rua: ");
	fgets(agenda[posicao].endereco.rua, sizeof(String), stdin);

	puts("Inserir número: ");
	scanf("%d", &agenda[posicao].endereco.numero);
	
	limpar_buffer();
	puts("Inserir complemento: ");
	fgets(agenda[posicao].endereco.complemento, sizeof(String), stdin);

	puts("Inserir bairro: ");
	fgets(agenda[posicao].endereco.bairro, sizeof(String), stdin);
	
	puts("Inserir cidade: ");
	fgets(agenda[posicao].endereco.cidade, sizeof(String), stdin);
	
	puts("Inserir estado: ");
	fgets(agenda[posicao].endereco.estado, sizeof(String), stdin);

	puts("Inserir País: ");
	fgets(agenda[posicao].endereco.pais, sizeof(String), stdin);

	puts("Insira o número de telefone no formato \"dd nnnnnnnnn\"");
	char telefone_str[12];
	fgets(telefone_str, sizeof(telefone_str), stdin);
	sscanf(telefone_str, "%2s %9s", agenda[posicao].telefone.ddd, agenda[posicao].telefone.numero);

	limpar_buffer();
	puts("Insira o aniversário no formado DD/MM/AAAA: ");
	scanf("%d/%d/%d", &agenda[posicao].aniversario.dia, &agenda[posicao].aniversario.mes, &agenda[posicao].aniversario.ano);

	limpar_buffer();
	puts("Insira alguma observação especial: ");
	fgets(agenda[posicao].observacoes, sizeof(String), stdin);

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
	} else {
		// Desloca os elementos p/a a esquerda
		for( int i = posicao; i < (*qtd_pessoas) - 1; i++) {
			agenda[i] = agenda[i + 1];
		}
		
		*qtd_pessoas -= 1;
	}
}
