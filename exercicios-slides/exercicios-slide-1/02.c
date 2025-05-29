/* Escreva um programa que pergunta ao usuário qual o valor do seu salário bruto e informa o valor a ser descontado de imposto de renda, de acordo com
 * a tabela abaixo. A parcela a deduzir deve ser descontada da porcentagem de alíquota do IR para produzir o valor final a ser descontado.
 * SALÁRIO		|	DESCONTO	|	PARCELA A DEDUZIR	|
 * até 1499,14		|	isento		|		-		|
 * 1499,15 a 2246,75	|	7,5%		|	112,44			|
 * 2246,76 a 2995,70	|	15%		|	280,94			|
 * 2995,71 a 3743,19	|	22,5%		|	505,62			|
 * acima de 3743,19	|	27,5%		|	692,78			|
 */

#include <stdio.h>

float salarioFinal(float salario) {
	float imposto = 0;

	if (salario <= 1499.14) {
		return salario;
	} else if (salario <= 2246.75) {
		imposto = (salario*0.075) - 112.44;
	} else if (salario <= 2995.70) {
		imposto = (salario*0.15) - 280.94;
	} else if (salario <= 3743.19) {
		imposto = (salario*0.225) - 505.62;
	} else {
		imposto = (salario*0.275) - 692.78;
	}

	return salario-imposto;
}


int main() 
{
	float salario;

	printf("Qual o valor do seu salário bruto?\n");
	scanf("%f", &salario);

	printf("Seu salário líquido é de %.2f\n", salarioFinal(salario));

	return 0;
}



