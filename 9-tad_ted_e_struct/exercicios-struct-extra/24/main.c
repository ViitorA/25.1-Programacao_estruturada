/* Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes dados:
 * Nome
 * E-mail
 * Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade, estado, país)
 * Telefone (contendo campo para DDD e número)
 * Data de aniversário (contendo campo para dia, mês, ano)
 * Observações: Uma linha (string) para alguma observação especial.
 * -> (a) Definir a estrutura acima.
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
#include <stdlib.h>
#include <string.h>

#include "dados.h"

int menu(Pessoa *agenda);

int main() {
	Pessoa *agenda = criar_agenda(100);

	menu(agenda);	
	free(agenda);

	return 0;
}

int menu(Pessoa *agenda) {
	int qtd_pessoas_agenda = 0;
	
	int user_choice;
		
	while(1) {	
		puts("");
		puts("===============|MENU|===============");
		puts("[1] Inserir pessoa na agenda\n");
		puts("[2] Remover pessoa da agenda\n");
		puts("[3] Buscar pessoa por nome\n");
		puts("[4] Buscar pessoa por mês de aniversário\n");
		puts("[5] Buscar pessoa por dia e mês de aniversário\n");
		puts("[6] Imprimir agenda\n");
		puts("[7] SAIR");

		scanf("%d", &user_choice);

		if(user_choice == 1) {
			inserir_pessoa(agenda, &qtd_pessoas_agenda);
		} else if(user_choice == 2) {
			String nome;

			puts("Digite o nome COMPLETO da pessoa que você quer remover");

			limpar_buffer();
			fgets(nome, sizeof(String), stdin);

			remover_pessoa(agenda, &qtd_pessoas_agenda, nome);
		} else if(user_choice == 3) {
			String nome;

			puts("Qual é o nome COMPLETO que você procura? ");

			limpar_buffer();
			fgets(nome, sizeof(String), stdin);

			buscar_nome(nome, agenda);
		} else if(user_choice == 4) {
			puts("Qual é o mês que você procura? ");
			int mes;
			scanf("%d", &mes);
			buscar_mes(mes, agenda);
		} else if(user_choice == 5) {
			puts("Insira o dia e mês que você procura no formato dd/mm: ");
			int dia, mes;
			scanf("%d/%d", &dia, &mes);
			buscar_dia_mes(dia, mes, agenda);
		} else if(user_choice == 6) {
			puts("(1) Imprimir parcialmente(nome, e-mail e telefone");
			puts("(2) Imprimir todos os dados");	
			scanf("%d", &user_choice);
			
			if (user_choice == 1) {
				imprimir_agenda_parcialmente(agenda, qtd_pessoas_agenda); 	
			} else if (user_choice == 2) {
				imprimir_agenda_completa(agenda, qtd_pessoas_agenda);
			} else {
				puts("INPUT INVÁLIDO!");
			}
		} else if(user_choice == 7) {
			return 0;
		} else {
			puts("INPUT INVÁLIDO!");
		}
	}
}	
