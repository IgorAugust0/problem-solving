#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declaração de variáveis
    int N;
    cin >> N;

    vector<long long> numeros(N);
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    // Contador de operações possíveis
    int operacoesMaximas = 0;
    bool todasPares = true;

    // Enquanto todas as entradas forem pares
    while (todasPares) {
        // Verifica se todos os números são pares
        todasPares = true;
        for (int i = 0; i < N; i++) {
            if (numeros[i] % 2 != 0) {
                todasPares = false;
                break;
            }
        }

        // Se todas são pares, executa a operação
        if (todasPares) {
            for (int i = 0; i < N; i++) {
                numeros[i] /= 2;
            }
            operacoesMaximas++;
        }
    }

    // Exibe o resultado
    cout << operacoesMaximas << endl;

    return 0;
}
