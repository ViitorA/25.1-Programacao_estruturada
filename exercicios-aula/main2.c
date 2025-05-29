#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_linha(char linha[])
{
	FILE *arq_bairro;
	arq_bairro = fopen(strcat(bairro, ".txt"), "a");

	int idade;
	char nome[150];
	char bairro[150];
	
	sscanf(linha, "%[^;] ; %d ; %[^\n]", nome, &idade, bairro);
	fprintf(arq_bairro, "%s;%d\n", nome, idade);

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
