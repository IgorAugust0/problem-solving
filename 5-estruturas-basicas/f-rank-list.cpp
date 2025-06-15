#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int pontuacoes[50];
    for (int i = 0; i < n; i++) {
        int problemas, penalidade;
        cin >> problemas >> penalidade;
        // Cálculo da pontuação: problemas resolvidos são prioridade, tempo de penalidade é secundário
        pontuacoes[i] = problemas * 50 - penalidade;
    }

    // Ordena pontuações em ordem crescente
    sort(pontuacoes, pontuacoes + n);

    // Encontra a k-ésima posição a partir do final (k-ésima melhor pontuação)
    int pontuacaoAlvo = pontuacoes[n - k];

    // Conta quantas equipes têm a mesma pontuação que a k-ésima posição
    int equipesComMesmaPontuacao = 0;
    for (int i = 0; i < n; i++) {
        if (pontuacoes[i] == pontuacaoAlvo) {
            equipesComMesmaPontuacao++;
        }
    }

    cout << equipesComMesmaPontuacao << endl;
    return 0;
}

