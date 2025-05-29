/* Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes dados:
 * Nome
 * E-mail
 * Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade, estado, país)
 * Telefone (contendo campo para DDD e número)
 * Data de aniversário (contendo campo para dia, mês, ano)
 * Observações: Uma linha (string) para alguma observação especial.
 * -> XXX(a) Definir a estrutura acima.
 * -> (b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes.
 * -> (c) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).
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
	int ddd[2];
	int numero[9];	
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



int main()
{
	Pessoa agenda[100];




	return 0;
}

