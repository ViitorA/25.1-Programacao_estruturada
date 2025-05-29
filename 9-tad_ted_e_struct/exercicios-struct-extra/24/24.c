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

#include "dados.h"

int menu(Pessoa *agenda) {
	int user_choice;
	
	while(1) {	
		puts("==========|MENU|==========\n");
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
			buscar_nome(nome, agenda);
		} else if(user_choice == 3) {
			puts("Qual é o mês que você procura? ");
			int mes;
			scanf("%d", &mes);
			buscar_mes(mes, agenda);
		} else if(user_choice == 4) {
			puts("Insira o dia e mês que você procura no formato dd/mm: ");
			int dia, mes;
			scanf("%d/%d", &dia, &mes);
			buscar_dia_mes(dia, mes, agenda);
		}
	}
}	

int main() {
	Pessoa *agenda = criar_agenda(100);
	menu(agenda);
	
	free(agenda);

	return 0;
}

