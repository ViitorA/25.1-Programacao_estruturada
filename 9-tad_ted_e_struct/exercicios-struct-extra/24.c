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
 * -> (d) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse mês.
 * -> (e) Definir um bloco de instruções busca por dia e mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse dia e mês.
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
		printf("CEP: %s\n", pessoa.endereco.cep);
		printf("Rua: %s, num. %d\n", pessoa.endereco.rua, pessoa.endereco.numero);
		printf("Complemento: %s\n", pessoa.endereco.complemento);
		printf("Bairro: %s\n", pessoa.endereco.bairro);
		printf("Cidade: %s\n", pessoa.endereco.cidade);
		printf("Estado: %s\n", pessoa.endereco.estado);
		printf("País: %s\n\n", pessoa.endereco.pais);
	printf("Número de Telefone: ");
	for(int i = 0; i < 2; i++) {
		printf("%d", pessoa.telefone.ddd);
	}
	printf(" ");
	for(int i = 0; i < 9; i++) {
		printf("%d", pessoa.telefone.numero);
	} 
	printf("\n");
	
	printf("Aniversário: %d/%d/%d\n", pessoa.aniversario.dia, pessoa.aniversario.mes, pessoa.aniversario.ano);
	printf("Observações: %s\n", pessoa.observacoes);
	printf("====================\n");
}


void busca_por_primeiro_nome(char *nome, Pessoa agenda[100]) {
	for(int i = 0; i < 100; i++) {
		if(strcmp(agenda[i].nome, nome) == 0) {
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
		scanf("%d", agenda[i].endereco.numero);

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

		// Depois mudar esse input para o método com char
		puts("Insira o número de telefone no formato \"dd nnnnnnnnn\"");
		scanf("%d%d %d%d%d%d%d%d%d%d%d",
				agenda[i].telefone.ddd[0],
				agenda[i].telefone.ddd[1],
				agenda[i].telefone.numero[0],
				agenda[i].telefone.numero[1],
				agenda[i].telefone.numero[2],
				agenda[i].telefone.numero[3],
				agenda[i].telefone.numero[4],
				agenda[i].telefone.numero[5],
				agenda[i].telefone.numero[6],
				agenda[i].telefone.numero[7],
				agenda[i].telefone.numero[8]);
	
	}
}

void menu(Pessoa *agenda) {
	int user_choice;
	
	while(1) {	
		printf("O QUE DESEJA FAZER? \n");
		printf("[1] inserir pessoa nova na agenda\n");
		printf("[2] Buscar pessoa por nome\n");

		scanf("%d", &user_choice);
		switch(user_choice) {
			case 1:
				inserir_pessoa(agenda);
				break;
			case 2:
				puts("Qual é o nome que você procura? ");
				String nome;
				scanf("%s", nome);
				busca_por_primeiro_nome(nome, agenda);
				break;
		}
	}
}	

int main()
{
	Pessoa agenda[100];
	menu(agenda);

	return 0;
}

