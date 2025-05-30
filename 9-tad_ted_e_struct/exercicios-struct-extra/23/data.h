#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct dma;

struct dma *criar_struct_data();

int e_bissexto(int ano);

int calcular_dias_no_mes(int mes, int ano);

int calcularMeses(int mes, int ano);

int calcularBissextos(int ano);

int calcularDias(int dias, int mes, int ano);

int calcularDiferenca(struct dma data1, struct dma data2);
