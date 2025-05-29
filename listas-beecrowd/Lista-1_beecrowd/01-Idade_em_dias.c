/* Leia um valor inteiro correspondente à idade de uma pessoa em dias e informe-a em anos, meses e dias
 * Obs.: apenas para facilitar o cálculo, considere todo ano com 365 dias e todo mês com 30 dias. Nos casos de teste nunca haverá uma situação que permite 12 meses e alguns dias, 
 * como 360, 363 ou 364. Este é apenas um exercício com objetivo de testar raciocínio matemático simples.
 *
 * Entrada
 * O arquivo de entrada contém um valor inteiro.
 *
 * Saída
 * Imprima a saída conforme exemplo fornecido.
 *
 * Exemplo de entrada: 400
 * Exemplo de saída:
 * 1 ano(s)
 * 1 mes(es)
 * 5 dia(s)
 */

#include <stdio.h>

int calcularAnos(int n);
int calcularMeses(int n);

int main()
{
	int n; 
	scanf("%d", &n);

	int anos = calcularAnos(n);
	
	n -= anos*365;
	int meses = calcularMeses(n);
		
	printf("%d ano(s)\n", anos);
	printf("%d mes(es)\n", meses);

	n -= meses*30;
	printf("%d dia(s)\n", n);


	return 0;
}

int calcularAnos(int n) 
{
	int anos = 0;

	while(n >= 365) {
		n -= 365;
		anos++;
	}

	return anos;
}

int calcularMeses(int n) 
{
	int meses = 0;

	while(n >= 30) {
		n -= 30;
		meses++;
	}

	return meses;
}
