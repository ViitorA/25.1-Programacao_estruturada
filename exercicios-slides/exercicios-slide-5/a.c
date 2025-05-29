#include <stdio.h>

int main() {
	int y = 0;
       	int *p;
	int x;

	y = 0;
	p = &y;
	x = *p; // x = 0;
	x = 4; // x = 4;
	(*p)++; // y = 1;
	x--; // x = 3;
	(*p) += x; // y = 4;
	printf ("x = %d e y = %d\n", x, y);

	return 0;
}
