#include <stdio.h>

int flavious(int n, int k)
{
	if (n == 0) return 0;

	return (flavious(n-1,k) + k) % n;
}

int main()
{
	int nc;
	scanf("%d", &nc);
	
	for(int i = 1; i <= nc; i++) {
		int n, k;
		scanf("%d %d", &n, &k);

		printf("Case %d: %d\n",i, flavious(n,k)+1);
	}
	return 0;
}
