#include <stdio.h>

void exemplo1()
{
	double b,a;
	double *c;
	// Note que: int *c e depois c = &b daria errado, pois mesmo sendo ponteiro precisa ser do mesmo tipo
	b = 10.89;
	c = &b;
	a = *c;

	printf("a: %lf\nb: %lf\nc: %p\n", a,b,c);

}

// COMPARAÇÃO ENTRE PONTEIROS
void exemplo2()
{
	double *a, *b, c = 10, d = 10;
	b = &c;
	a = &d;

	if(b < a) {
		printf("\nO endereço apontado por b é menor : %p e %p\n", b, a);
	}else if(a < b) {
		printf("\nO endereço apontado por a é menor: %p e %p\n", a, b);
	} else if(a == b) {
		printf("Mesmo endereço.\n");
	}

	if(*a == *b) printf("Mesmo conteúdo: %lf\n", *a);
}

void exemplo3()
{
	int x = 10;
	int *p1 = &x;
	int **p2 = &p1;
	int ***p3 = &p2;

	printf("%d %p %p %p %ld %ld %ld\n", x, p1, p2, p3, sizeof(p1), sizeof(p2), sizeof(p3));
}

void exemplo4()
{
	int i = 10 , j = 20;
	int temp ;
	int *p1 , *p2 ;
	p1 = &i ;
	p2 = &j;
	temp = *p1;
	*p1 = *p2 ; // Ou seja, o valor armazenado em p1(end. de i) receberá o valor armazenado em p2(20)
	*p2 = temp;
	printf( "%i %i\n" , i , j );

}

void go_south_east(int *lat, int *lon) 
{
	*lat -= 1;
	*lon += 1;
}

void exemplo5()
{
	int lat = 32;
	int lon = -64;
	go_south_east(&lat,&lon);	
	printf("Now at [%i, %i]\n", lat, lon);

}
void func(int *px, int *py) {
        px = py;
        *py = (*py) * (*px);
        *px = *px + 2;
}

void exemplo6()
{
        int x = 3, y = 4;
        func(&x,&y);

        printf("x = %i, y = %i", x, y);
}


int main()
{
	exemplo1();
	exemplo2();
	exemplo3();
	exemplo4();
	exemplo5();
	exemplo6();

	return 0;
}
