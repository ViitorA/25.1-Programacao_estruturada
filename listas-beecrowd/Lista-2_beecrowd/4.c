#include <stdio.h>
#include <stdlib.h>

#define MAX_M 20

int num_digitos(unsigned long long x) {
    if (x == 0) return 1;
    int dig = 0;
    while (x) {
        dig++;
        x /= 10;
    }
    return dig;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int matriz = 0; matriz < N; matriz++) {
        int M;
        scanf("%d", &M);

        long long mat[MAX_M][MAX_M];
        unsigned long long mat_quadrado[MAX_M][MAX_M];
        int max_width = 0;

        // Leitura e cálculo dos quadrados
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%lld", &mat[i][j]);
                unsigned long long v = (unsigned long long)(mat[i][j]);
                mat_quadrado[i][j] = v * v;
                int largura = num_digitos(mat_quadrado[i][j]);
                if (largura > max_width)
                    max_width = largura;
            }
        }

        // Cabeçalho
        printf("Quadrado da matriz #%d:\n", matriz + 4);

        // Impressão da matriz com formatação
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (j > 0) printf(" ");  // só imprime espaço SE não for o primeiro
                printf("%*llu", max_width, mat_quadrado[i][j]);
            }
            printf("\n");
        }

        // Linha em branco ENTRE matrizes, mas não depois da última
        if (matriz < N - 1)
            printf("\n");
    }

    return 0;
}
