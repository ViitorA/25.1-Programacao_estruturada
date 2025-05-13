#include <stdio.h>
#include <string.h>

int contar_palavras_arquivo(char nome_arquivo[])
{
	FILE *arquivo = fopen(nome_arquivo, "r");
	if(arquivo == NULL) {
		printf("Erro na leitura do arquivo!\n");
		return 1;
	}

	char palavra[100];
	int qtd = 0;
	while(fscanf(arquivo, "%s", palavra) == 1) {
		qtd++;
	}

	return qtd;
}

int contar_palavras_frase(char frase[]) {

	char *tok = strtok(frase, " ");
	int qtd_palavras = 0;

	while(tok != NULL) {
		qtd_palavras++;
		tok = strtok(NULL, " ");
	}
	
	return qtd_palavras;	
}	

int main() {
	int usr_choice;	
	printf("Você deseja contar a qtd de palavras em uma frase (1) ou de um arquivo?(2)\n");
	scanf("%d", &usr_choice);
	
	// Limpa o buffer	
	while ((getchar()) != '\n');

	char usr_input[100];
	switch(usr_choice){
		case 1:
			printf("Insira sua frase: ");
			char frase[1000];
			fgets(frase, 1000, stdin);
			int i = contar_palavras_frase(frase);
			printf("%d palavras\n", i);
			break;
		case 2:
			printf("Digite o nome do arquivo: ");
			scanf("%s", usr_input);
			int j = contar_palavras_arquivo(usr_input);
			printf("%d palavras\n", j);
			break;
	}
	return 0;
}
