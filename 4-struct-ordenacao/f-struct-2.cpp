#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// tempo de complexidade: O(n), onde N é o número de pontos do plano

int main() {
    // Declaração de variáveis
    int N;
    cin >> N;

    // Ponto inicial
    int tempoAtual = 0;
    int xAtual = 0;
    int yAtual = 0;

    // Verificar cada ponto do plano
    bool possivelCumprir = true;

    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        // Calcular a distância mínima (Manhattan) necessária para chegar ao ponto (x,y)
        int distanciaManhattan = abs(x - xAtual) + abs(y - yAtual);

        // Tempo disponível para percorrer a distância
        int tempoDisponivel = t - tempoAtual;

        // Verificar se é possível chegar ao ponto no tempo disponível
        if (distanciaManhattan > tempoDisponivel ||
            (tempoDisponivel - distanciaManhattan) % 2 != 0) {
            // Impossível chegar no tempo exato ou com número correto de passos
            possivelCumprir = false;
            break;
        }

        // Atualizar posição e tempo atual
        xAtual = x;
        yAtual = y;
        tempoAtual = t;
    }

    // Exibir resultado
    if (possivelCumprir) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
