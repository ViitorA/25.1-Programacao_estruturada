/* Escreva um programa que receba dois structs do tipo dma, cada um representando uma data válida, e calcule o número de dias que decorreram entre as duas datas.
 *	struct dma {
 *		int dia;
 *		int mes;
 *		int ano;
 *	};
 */

#include <stdio.h>
#include <math.h>

struct dma {
	int dia;
	int mes;
	int ano;
};

int calcularDias(struct dma data1, struct dma data2) {
	// 23/04/25
	// 14/05/25
	//
	
	int dias_totais_1 = data1.dias;
       	dias_totais_1 += data1.mes * 30;
	dias_totais	

	if(data1.ano == data2.ano) {
		if(data1.mes == data2.mes) {
			return sqrt( (data1.dia - data2.dia)*(data1.dia - data2.dia)  );
		} else {
		
		}
	}
}

int main() {

	struct dma data1;
	data1.ano = 2025;
	data1.mes = 04;
	data1.dia = 23;

	struct dma data2;
	data2.ano = 2025;
	data2.mes = 04;
	data2.dia = 14;

	int dias_decorridos = calcularDias(data2,data1);
	printf("%d\n", dias_decorridos);

	return 0;
}
