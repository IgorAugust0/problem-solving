#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Função para verificar se o grafo está conectado
bool verificarConectividade(const vector<vector<int>>& grafo, int n) {
    vector<bool> visitado(n + 1, false);
    queue<int> fila;

    // Iniciar BFS a partir do vértice 1
    fila.push(1);
    visitado[1] = true;

    int verticesVisitados = 0;
    while (!fila.empty()) {
        int verticeAtual = fila.front();
        fila.pop();
        verticesVisitados++;

        // Visitar todos os vizinhos não visitados
        for (int vizinho : grafo[verticeAtual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }

    // O grafo é conectado se todos os vértices foram visitados
    return verticesVisitados == n;
}

// Função para verificar se o grafo é um Cthulhu
bool verificarCthulhu(const vector<vector<int>>& grafo, int n, int m) {
    // Um grafo Cthulhu tem exatamente n arestas se tiver n vértices
    if (m != n) {
        return false;
    }

    // Verificar se o grafo está conectado
    if (!verificarConectividade(grafo, n)) {
        return false;
    }

    // Para ser um Cthulhu, precisa ter pelo menos 3 vértices
    if (n < 3) {
        return false;
    }

    // Se chegou até aqui, o grafo:
    // - Está conectado
    // - Tem n vértices e n arestas
    // - Tem pelo menos 3 vértices
    // Isso garante que o grafo tem exatamente um ciclo (pois um grafo conectado
    // sem ciclos teria n-1 arestas). Como está conectado e tem um ciclo, todos os
    // vértices não pertencentes ao ciclo formam árvores enraizadas nos vértices do ciclo.

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Inicializar o grafo como uma lista de adjacência
    vector<vector<int>> grafo(n + 1);

    // Ler as arestas
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);  // Grafo não direcionado
    }

    // Verificar se o grafo é um Cthulhu e imprimir o resultado
    if (verificarCthulhu(grafo, n, m)) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
