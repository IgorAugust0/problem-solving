#include <iostream>
#include <vector>
using namespace std;

// Tabuleiro 8x8
const int N = 8;
vector<string> tabuleiro(N);
int solucoes = 0;

// Verifica se uma rainha pode ser colocada na posicao (linha, col)
bool posicaoValida(int linha, int col, vector<pair<int, int>>& rainhas) {
    // Verifica se a posicao esta reservada
    if (tabuleiro[linha][col] == '*') return false;

    // Verifica conflitos com outras rainhas
    for (auto& rainha : rainhas) {
        int r_linha = rainha.first;
        int r_col = rainha.second;

        // Verifica linha, coluna e diagonais
        if (r_col == col) return false;
        if (abs(r_linha - linha) == abs(r_col - col)) return false;
    }
    return true;
}

// Funcao recursiva de backtracking
void resolverNRainhas(int linha, vector<pair<int, int>>& rainhas) {
    // Se encontrou uma solucao valida
    if (rainhas.size() == N) {
        solucoes++;
        return;
    }

    // Se passou da ultima linha
    if (linha >= N) return;

    // Tenta colocar uma rainha em cada coluna da linha atual
    for (int col = 0; col < N; col++) {
        if (posicaoValida(linha, col, rainhas)) {
            rainhas.push_back({linha, col});
            resolverNRainhas(linha + 1, rainhas);
            rainhas.pop_back();
        }
    }
}

int main() {
    // Le o tabuleiro
    for (int i = 0; i < N; i++) {
        cin >> tabuleiro[i];
    }

    vector<pair<int, int>> rainhas;
    resolverNRainhas(0, rainhas);

    cout << solucoes << endl;

    return 0;
}
