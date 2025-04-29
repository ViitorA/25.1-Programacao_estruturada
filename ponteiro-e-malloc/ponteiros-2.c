#include <stdio.h>

/* ARITMÉTICA DE PONTEIROS
 * -Somar 1 ao ponteiro indica que ele apontará para o próximo end. de memória
 *  P/a descobrir o tamanho do dado, use sizeof()
 *  Exemplo:
 *  	double num;
 *	double *ptr_num;
 *	ptr_num = &num; -> suponha que aponte para a memória n 1000
 *	prt_num += 2; -> agora ele aponta para 1016, já que double requer 8 bytes de memória
 *
 *  Você pode usar isso p/a acessar um vetor a partir do index 0.
 *
 */

void exibirString()
{
	char string[40] = "Exibindo uma string usando um ponteiro.";
	char *ptr_str;

	ptr_str = string; // Lembrando que com vetores não precisa usar o &, já que eles já apontam para o primeiro elemento do vetor
	printf("Apontando para o início da string => ptr_str = %c\n", *ptr_str);

	while(*ptr_str) { // Funciona porque as strings em C terminam com \0
		putchar(*ptr_str);
		ptr_str++;
	}

	printf("\n\n");
}

void exemplo2()
{
	int contestants[] = {1,2,3};
	int *choice = contestants;

	contestants[0] = 2;
	contestants[1] = contestants[2];
	contestants[2] = *choice;

	printf("%d %d %d\n\n", contestants[0], contestants[1], contestants[2]);

}

int main()
{
	exibirString();
	exemplo2();

	return 0;
}
