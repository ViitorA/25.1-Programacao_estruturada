#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct dma {
	int dia;
	int mes;
	int ano;
};

struct dma *criar_struct_data() {
	struct dma *data = (struct dma*) malloc(sizeof(struct dma));

	if(data == NULL) {
		printf("MEMÓRIA INSUFICIENTE!\n");
		exit(1);
	}
		
	printf("Dia: ");
	scanf("%d", &data->dia);
	
	printf("Mês: ");
	scanf("%d", &data->mes);

	printf("Ano: ");
	scanf("%d", &data->ano);

	return data;
}

int e_bissexto(int ano) {
	// Um ano é bissexto se:
	// É divisível por 4;
	// Não é divisível por 100;
	// É divisível por 400;

	if (ano % 400 == 0) {
		return 1;
	} else if( ano % 100 == 0) {
		return 0;
	} else if ( ano % 4 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int calcular_dias_no_mes(int mes, int ano) {
	switch(mes) {
		case 2:
			if(e_bissexto(ano)) {
				return 29;
			} else {
				return 28;
			}
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
	}
}

int calcularMeses(int mes, int ano) {
	int meses_em_dias = 0;
	
	for(int i = 1; i < mes; i++) {
		meses_em_dias += calcular_dias_no_mes(i,ano);
	}

	return meses_em_dias;
}

int calcularBissextos(int ano) {
	int qtd_bissextos = 0;

	for(int i = 0; i < ano; i++) {
		if(e_bissexto(i))
			qtd_bissextos += 1;
	}

	// Por algum motivo claculando um a mais então só retirei 1 unidade
	return qtd_bissextos - 1;
}

int calcularDias(int dias, int mes, int ano) {
	int anos_em_dias;
	int meses_em_dias;

	int qtd_bissextos = calcularBissextos(ano);
	int qtd_nao_bissextos = ano - qtd_bissextos;

	if(e_bissexto(ano)) {
		anos_em_dias = (qtd_bissextos * 366) + ( qtd_nao_bissextos * 365);
		meses_em_dias = calcularMeses(mes, ano);
	} else {
		anos_em_dias = (qtd_bissextos * 366) + (qtd_nao_bissextos * 365);
		meses_em_dias = calcularMeses(mes, ano);
	}
	
	return meses_em_dias + anos_em_dias + dias;
}

int calcularDiferenca(struct dma data1, struct dma data2) {
	int dias1 = calcularDias(data1.dia, data1.mes, data1.ano);
	int dias2 = calcularDias(data2.dia, data2.mes, data2.ano);

	// Calcula o valor absoluto da diferença
	return sqrt( (dias1 - dias2)*(dias1 - dias2)  );
}
