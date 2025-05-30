/* Escreva um programa que receba dois structs do tipo dma, cada um representando uma data válida, e calcule o número de dias que decorreram entre as duas datas.
 *	struct dma {
 *		int dia;
 *		int mes;
 *		int ano;
 *	};
 */

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	// A limitação mais óbvia é que eu acho que não dá pra calcular anos A.C
	puts("DATA 1");
	struct dma *data1 = criar_struct_data();

	puts("DATA 2");
	struct dma *data2 = criar_struct_data();

	printf("%d dias se passaram.\n", calcularDiferenca(*data1, *data2));

	free(data1);
	free(data2);

	return 0;
}
