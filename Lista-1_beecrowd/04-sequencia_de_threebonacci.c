#include <stdio.h>

int tem_digito_3(long long num) {
    while (num > 0) {
        if (num % 10 == 3) {
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int pertence_a_threebonacci(long long num) {
    return tem_digito_3(num) || (num % 3 == 0);
}

int main() {
    int n;
    
    while (scanf("%d", &n) == 1) {
        int count = 0;
        long long fib1 = 0, fib2 = 1, atual;

        while (1) {
            atual = fib1 + fib2;
            fib1 = fib2;
            fib2 = atual;

            if (pertence_a_threebonacci(atual)) {
                count++;
                if (count == n) {
                    printf("%lld\n", atual);
                    break;
                }
            }
        }
    }

    return 0;
}

