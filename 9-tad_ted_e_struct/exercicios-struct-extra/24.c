/* Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes dados:
 * Nome
 * E-mail
 * Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade, estado, país)
 * Telefone (contendo campo para DDD e número)
 * Data de aniversário (contendo campo para dia, mês, ano)
 * Observações: Uma linha (string) para alguma observação especial.
 * -> XXX(a) Definir a estrutura acima.
 * -> XXX(b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes.
 * -> XXX(c) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).
 * -> XXX(d) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse mês.
 * -> XXX(e) Definir um bloco de instruções busca por dia e mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse dia e mês.
 * -> (f) Definir um bloco de instruções insere pessoa: Insere por ordem alfabética de nome.
 * -> (g) Definir um bloco de instruções retira pessoa: Retira todos os dados dessa pessoa e desloca todos os elementos seguintes do vetor para a posição anterior.
 * -> (h) Definir um bloco de instruções imprime agenda com as opções:
 *        -> Imprime nome, telefone e e-mail.
 *        -> Imprime todos os dados.
 * -> (i) O programa deve ter um menu principal oferecendo as opções acima.
 */

#include <stdio.h>
#include <string.h>

typedef char String[80];

typedef struct Endereco {
	String rua;
	int numero;
	String complemento;
	String bairro;
	String cep;
	String cidade;
	String estado;
	String pais;
} Endereco;

typedef struct Telefone {
	// Se fosse int, teria problemas pois o número 09405 seria o mesmo que 9405?
	// Se fosse um vetor int, ficaria ruim para o input depois
	char ddd[3]; // mais um caractere p/a o \0
	char numero[10];	
} Telefone;

typedef struct Aniversario {
	int dia;
	int mes;
	int ano;
} Aniversario;

typedef struct Pessoa {
	String nome;
	String email;
	Endereco endereco;
	Telefone telefone;
	Aniversario aniversario;
	String observacoes;
} Pessoa;

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


void busca_por_primeiro_nome(char *nome, Pessoa *agenda) {
	for(int i = 0; i < 100; i++) {
		if(strcmp(agenda[i].nome, nome) == 0) {
			imprimir_dados(agenda[i]);
		}	
	}
}

void busca_mes(int mes, Pessoa *agenda) {
	for(int i = 0; i < 100; i++) {
		if(agenda[i].aniversario.mes == mes) {
			imprimir_dados(agenda[i]);
		}
	}
}

void busca_dia_mes(int dia, int mes, Pessoa *agenda) {
	for(int i = 0; i < 100; i++) {
		if(agenda[i].aniversario.mes == mes && agenda[i].aniversario.dia == dia) {
			imprimir_dados(agenda[i]);
		}
	}
}

void inserir_pessoa(Pessoa agenda[100]) {
	// Depois arrumar isso para encaixar no enunciado
	int choice;
	puts("Quntas pessoas deseja inserir? ");
	scanf("%d", &choice);

	for(int i = 0; i < choice; i++) {
		puts("Inserir nome: ");
		scanf("%s", agenda[i].nome);	

		puts("Inserir E-Mail: ");
		scanf("%s", agenda[i].email);

		puts("Inserir CEP: ");
		scanf("%s", agenda[i].endereco.cep);

		puts("Inserir Rua: ");
		scanf("%s", agenda[i].endereco.rua);

		// segfault
		puts("Inserir número: ");
		scanf("%d", &agenda[i].endereco.numero);

		puts("Inserir complemento: ");
		scanf("%s", agenda[i].endereco.complemento);

		puts("Inserir bairro: ");
		scanf("%s", agenda[i].endereco.bairro);

		puts("Inserir cidade: ");
		scanf("%s", agenda[i].endereco.cidade);

		puts("Inserir estado: ");
		scanf("%s", agenda[i].endereco.estado);

		puts("Inserir País: ");
		scanf("%s", agenda[i].endereco.pais);

		// Limpa o buffer
		while (getchar() != '\n');

		puts("Insira o número de telefone no formato \"dd nnnnnnnnn\"");
		char telefone_str[12];
		fgets(telefone_str, sizeof(telefone_str), stdin);
		sscanf(telefone_str, "%2s %9s", agenda[i].telefone.ddd, agenda[i].telefone.numero);

		// Limpa o buffer
		while (getchar() != '\n');
		
		puts("Insira o aniversário no formado DD/MM/AAAA: ");
		scanf("%d/%d/%d", &agenda[i].aniversario.dia, &agenda[i].aniversario.mes, &agenda[i].aniversario.ano);


		// Depois arrumar para poder aceitar nenhuma observação
		puts("Insira alguma observação especial: ");
		scanf("%s", agenda[i].observacoes);
	}
}

int menu(Pessoa *agenda) {
	int user_choice;
	
	while(1) {	
		puts("O QUE DESEJA FAZER? \n");
		puts("[0] SAIR\n");
		puts("[1] inserir pessoa nova na agenda\n");
		puts("[2] Buscar pessoa por nome\n");
		puts("[3] Buscar pessoa por mês de aniversário\n");
		puts("[4] Buscar pessoa por dia e mês de aniversário\n");

		scanf("%d", &user_choice);
		if(user_choice == 0) {
			return 0;
		} else if(user_choice == 1) {
			inserir_pessoa(agenda);
		} else if(user_choice == 2) {
			puts("Qual é o nome que você procura? ");
			String nome;
			scanf("%s", nome);
			busca_por_primeiro_nome(nome, agenda);
		} else if(user_choice == 3) {
			puts("Qual é o mês que você procura? ");
			int mes;
			scanf("%d", &mes);
			busca_mes(mes, agenda);
		} else if(user_choice == 4) {
			puts("Insira o dia e mês que você procura no formato dd/mm: ");
			int dia, mes;
			scanf("%d/%d", &dia, &mes);
			busca_dia_mes(dia, mes, agenda);
		}
	}
}	

int main()
{
	Pessoa agenda[100];
	menu(agenda);

	return 0;
}

