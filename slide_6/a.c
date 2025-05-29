#include <stdio.h>
#include <string.h>

void ler_string(char *string)
{
	for(int i = 0; string[i] != '\0'; i++) {
		printf("%c", *(string+i));
	}
	printf("\n");
}

int qtd_letras(char *string)
{
	int contador = 0;

	for(int i = 0; *(string+i) != '\0'; i++) {
		if( *(string+i) != ' ') {
			contador++;
		}
	}	
	
	return contador;
}

int main()
{
	char cidade[4];
	cidade[0] = 'R';
	cidade[1] = 'I';
	cidade[2] = 'O';
	cidade[3] = '\0';

	char estado[] = {'R','I','O','\0'};
	printf("A cidade do %s fica no estado do %s\n", cidade, estado);

	char pais[] = "Brasil"; // é um vetor de char, que é automaticamente concatenado com o caractere nulo (\0)
				// Ocupa 7 bytes de memória 
	pais[0] = 'C';
	printf("Que por sua vez fica no %s\n", pais);

	char *planeta = "MUNDO"; // planeta é um ponteiro p/a char, inicializando com o endereço de memória onde a constante "MUNDO" está
				 // planeta ocupa 4 bytes(espaço de um ponteiro)
	// planeta[0] = 'C'; não é válido pois não é possível alterar o valor de uma constante
	
	char nome[100];
	// scanf("%[^\n]", nome) -> Lê tudo, exceto quebra de linha
	scanf("%100[^\n]", nome); // Lê a linha toda até a quebra de linha, mas limita a leitura até no máximo 100 caracteres, evitando buffer overflow

	printf("Seu nome é: ");
	ler_string(nome);	

	int tamanho = qtd_letras(nome);
	printf("Seu nome tem %d letras!\n", tamanho);

	return 0;
}
