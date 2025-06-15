#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declaração de variáveis
    int N, K;
    cin >> N >> K;

    // Leitura dos valores
    vector<int> numeros(N);
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    // Ordena o array para facilitar a busca
    sort(numeros.begin(), numeros.end());

    // Conta os pares com diferença K
    int contadorPares = 0;
    for (int i = 0; i < N; i++) {
        // Busca binária para encontrar o valor numeros[i] + K
        if (binary_search(numeros.begin(), numeros.end(), numeros[i] + K)) {
            contadorPares++;
        }
    }

    // Exibe o resultado
    cout << contadorPares << endl;

    return 0;
}
