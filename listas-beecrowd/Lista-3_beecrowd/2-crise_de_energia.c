/* Durante uma crise de energia na Nova Zelândia no inverno passado (causada por uma escassez de chuva e, consequentemente, por causa dos níveis baixos nas barragens hidrográficas), 
 * um esquema de contingência foi desenvolvido para desligar a energia para as áreas do país de forma sistemática, de uma forma totalmente justa. O país foi dividido em N regiões 
 * (Auckland seria a região número 1 e Wellington a número 13). Um número, m, seria escolhido randomicamente e a energia deveria ser desligada primeiro na região 1 (claramente o ponto de início mais justo) 
 * e então em cada m região após esta, indo de uma a outra região e ignorando as regiões já desligadas. Por exemplo, se N = 17 e m = 5, a energia deverá ser desligada em todas as regiões seguindo 
 * a seguinte ordem: 1,6,11,16,5,12,2,9,17,10,4,15,14,3,8,13,7.
 *
 * O problema é que, claramente seria mais justo desligar a região de Wellington por último (Isso porque é onde a sede da empresa se encontra). Portanto, para um dado N (regiões), o número 
 * aleatório m (salto) precisa ser cuidadosamente escolhido de forma que a região 13 seja a última região a ser escolhida.
 *
 * Escreva um programa que leia o número de regiões e determine o menor número m que assegure que Wellington (região 13) possa continuar funcionando enquanto o resto do país esteja desligado.
 *
 * Entrada
 * A entrada consistirá de uma série de linhas, cada uma contendo o número de regiões N (13 ≤ N ≤ 100 ). O fim da entrada é indicado por uma linha consistindo de um valor zero (0).
 *
 * Saída
 * A saída consistirá de uma série de linhas, uma linha para cada linha de entrada. Cada linha consistirá de um m de acordo com o esquema acima apresentado
 *
 * Exemplo de Entrada	| Exemplo de Saída
 * 17			| 7
 * 0			|
 */

#include <stdio.h>
#include <stdbool.h>

// Função para verificar se o valor de m é válido para um dado N
int find_m(int N) {
    int m = 1;
    while (1) {
        int regions[N];
        for (int i = 0; i < N; i++) {
            regions[i] = i + 1; // Preenche as regiões de 1 a N
        }
        
        int current = 0; // Começa na primeira região (índice 0)
        int remaining = N;
        
        while (remaining > 1) {
            // Remove a região atual
            for (int i = current; i < remaining - 1; i++) {
                regions[i] = regions[i + 1];
            }
            remaining--;
            
            // Atualiza o índice para a próxima região a ser removida
            current = (current + m - 1) % remaining;
        }
        
        // Verifica se a última região é a 13
        if (regions[0] == 13) {
            return m;
        }
        m++;
    }
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        printf("%d\n", find_m(N));
    }
    return 0;
}
