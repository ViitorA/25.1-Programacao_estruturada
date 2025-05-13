#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formatar_string(char *string)
{
	// TODO: APPEND .txt
	char *p = strchr(string, '\n');
	
	chat txt[] = ".txt";
	strcat(p, txt);
	//if (p) *p = '\0';

}

void ler_linha(char linha[])
{
	FILE *arq_bairro;

	printf("A linha é: %s\n", linha);
	char *tok = strtok(linha, ";");

	int idade;
	char nome[150];
	char bairro[150];
		
	int i = 0;
	while(tok != NULL) {
		switch(i) {
			case 0:
				strcpy(nome,tok);
				printf("Nome: %s\n", nome);
				break;
			case 1:
				idade = atoi(tok);
				break;
			case 2:
				strcpy(bairro, tok);
				formatar_string(bairro);
				printf("Bairro:  %s\n", bairro);
				arq_bairro = fopen(bairro, "a+");
				break;
		}
		tok = strtok(NULL,";");
		i++;
	}
	fclose(arq_bairro);
}

void ler_arquivo(FILE *arq)
{
	char linha[250];
	while(fgets(linha,250,arq)){
		ler_linha(linha);
		printf("\n");
	}
	

}

int main(int argc, char *argv[])
{
	FILE *arq = fopen(argv[1], "r");
	if(arq == NULL) {
		printf("Erro na leitura do arquivo!\n");
		return 1;
	}

	ler_arquivo(arq);
	
	return 0;
}
