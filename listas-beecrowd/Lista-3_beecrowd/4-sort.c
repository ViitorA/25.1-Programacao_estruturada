#include <stdio.h>
#include <stdlib.h>

// Função para calcular o módulo conforme as regras de C
int mod(int a, int m) {
    return a % m;
}

int M; // Variável global para M (necessária para a função de comparação)

int compare(const void *a, const void *b);

int main() {
    int N;
    
    while (1) {
        scanf("%d %d", &N, &M);
        printf("%d %d\n", N, M);
        
        if (N == 0 && M == 0) {
            break;
        }
        
        int numbers[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &numbers[i]);
        }
        
        // Ordena os números usando nossa função de comparação
        qsort(numbers, N, sizeof(int), compare);
        
        // Imprime os números ordenados
        for (int i = 0; i < N; i++) {
            printf("%d\n", numbers[i]);
        }
    }
    
    return 0;
}

// Função de comparação para o qsort
int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    int mod1 = mod(num1, M);
    int mod2 = mod(num2, M);
    
    // Primeiro critério: ordenar pelo módulo M
    if (mod1 != mod2) {
        return mod1 - mod2;
    }
    
    // Segundo critério: se módulo igual, ímpar vem antes de par
    int odd1 = abs(num1) % 2;
    int odd2 = abs(num2) % 2;
    
    if (odd1 != odd2) {
        // Se um é ímpar e outro é par, ímpar vem primeiro
        return odd2 - odd1;
    }
    
    // Terceiro critério: ambos ímpares ou ambos pares
    if (odd1) { // ambos ímpares
        // Maior ímpar vem primeiro
        return num2 - num1;
    } else { // ambos pares
        // Menor par vem primeiro
        return num1 - num2;
    }
}
