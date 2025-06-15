#include <bits/stdc++.h>
using namespace std;

// Otimiza a entrada/saída
#define otimizar                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main() {
    otimizar;

    int numCasos;
    cin >> numCasos;

    // Para cada caso de teste
    while (numCasos--) {
        // Dimensões do tabuleiro
        int linhas, colunas;
        cin >> linhas >> colunas;

        // Posições dos dois pontos
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Conta movimentos possíveis para o primeiro ponto
        int movimentosPonto1 = 0;
        if (x1 + 1 <= linhas) movimentosPonto1++;
        if (x1 - 1 > 0) movimentosPonto1++;
        if (y1 + 1 <= colunas) movimentosPonto1++;
        if (y1 - 1 > 0) movimentosPonto1++;

        // Conta movimentos possíveis para o segundo ponto
        int movimentosPonto2 = 0;
        if (x2 + 1 <= linhas) movimentosPonto2++;
        if (x2 - 1 > 0) movimentosPonto2++;
        if (y2 + 1 <= colunas) movimentosPonto2++;
        if (y2 - 1 > 0) movimentosPonto2++;

        // Imprime o menor número de movimentos entre os dois pontos
        cout << min(movimentosPonto1, movimentosPonto2) << '\n';
    }

    return 0;
}
