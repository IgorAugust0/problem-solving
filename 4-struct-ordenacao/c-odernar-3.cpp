#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    // Declaração de variáveis
    int n;
    cin >> n;

    // Usando set para armazenar valores únicos
    set<int> valoresUnicos;

    // Leitura dos valores e inserção no set
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        valoresUnicos.insert(valor);
    }

    // Contagem de valores distintos
    int quantidadeDistintos = valoresUnicos.size();

    // Exibe o resultado
    cout << quantidadeDistintos << endl;

    return 0;
}
