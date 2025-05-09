#include <stdio.h>

double raiz(int n, int i)
{
	double valor_aprox;
	
	if(n == 0) return 1;
	if(n == 1 && i != 0) return 2 + 1.0/2;
	if(n == 1) return 1 + 1.0/2;
	
	i += 1;

	if(i == 1){
		valor_aprox = 1 + ( 1.0/raiz(n-1, i) );
	} else if(n >= 1) {
		valor_aprox = 2 + 1.0/raiz(n-1, i);
	}

	return valor_aprox;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%.10lf\n", raiz(n,0));
	

	return 0;
}
