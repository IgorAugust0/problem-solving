#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool visitado[100005]{false};

double buscaProfundidade(vector<vector<int>> &grafo, int origem, unsigned long long distancia) {
    double retorno = 0;
    visitado[origem] = true;
    int numeroFilhos = 0;

    for (auto destino : grafo[origem]) {
        if (!visitado[destino]) {
            retorno += buscaProfundidade(grafo, destino, distancia + 1);
            numeroFilhos++;
        }
    }

    visitado[origem] = false;

    if (numeroFilhos == 0) {
        return distancia;
    } else {
        return retorno / numeroFilhos;
    }
}

int main() {
    int numeroVertices;
    cin >> numeroVertices;

    vector<vector<int>> grafo(numeroVertices);

    // Leitura das arestas
    for (int i = 0; i < numeroVertices - 1; i++) {
        int origem, destino;
        cin >> origem >> destino;
        grafo[origem - 1].push_back(destino - 1);
        grafo[destino - 1].push_back(origem - 1);
    }

    double resultado = buscaProfundidade(grafo, 0, 0);
    cout << fixed << setprecision(16) << resultado << endl;

    return 0;
}
