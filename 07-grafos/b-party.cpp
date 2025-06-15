#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Função para calcular a profundidade de cada funcionário usando DFS
int calcularProfundidade(int funcionario, const vector<vector<int>>& subordinados, vector<int>& profundidades) {
    // Se a profundidade já foi calculada, retorne-a
    if (profundidades[funcionario] != -1) {
        return profundidades[funcionario];
    }

    // Se não houver subordinados, a profundidade é 0
    if (subordinados[funcionario].empty()) {
        profundidades[funcionario] = 0;
        return 0;
    }

    // Calcula a profundidade máxima dos subordinados
    int profundidadeMaxima = 0;
    for (int subordinado : subordinados[funcionario]) {
        profundidadeMaxima = max(profundidadeMaxima,
                                 calcularProfundidade(subordinado, subordinados, profundidades) + 1);
    }

    profundidades[funcionario] = profundidadeMaxima;
    return profundidadeMaxima;
}

int main() {
    int n;
    cin >> n;

    // Vetores para armazenar gerentes e subordinados
    vector<int> gerentes(n + 1);
    vector<vector<int>> subordinados(n + 1);
    vector<int> raizes;  // Funcionários sem gerente

    // Leitura dos dados
    for (int i = 1; i <= n; i++) {
        cin >> gerentes[i];

        if (gerentes[i] == -1) {
            raizes.push_back(i);
        } else {
            subordinados[gerentes[i]].push_back(i);
        }
    }

    // Vetor para armazenar as profundidades calculadas
    vector<int> profundidades(n + 1, -1);

    // Calculando a profundidade para cada raiz
    int profundidadeMaxima = 0;
    for (int raiz : raizes) {
        profundidadeMaxima = max(profundidadeMaxima,
                                 calcularProfundidade(raiz, subordinados, profundidades));
    }

    // O número mínimo de grupos é a profundidade máxima + 1
    cout << profundidadeMaxima + 1 << endl;

    return 0;
}
