#include <bits/stdc++.h>
using namespace std;

int main() {
    // Mapas para contagem
    map<int, int> freqNumeros;  // Conta frequência de cada número
    map<int, int> freqFreqs;    // Conta quantos números têm cada frequência

    // Número de casos de teste
    int casosTeste;
    cin >> casosTeste;

    while (casosTeste--) {
        // Limpar contadores para novo caso
        freqNumeros.clear();
        freqFreqs.clear();

        // Tamanho do array
        int tamanho;
        int minRemocoes = INT_MAX;
        cin >> tamanho;

        // Contar frequência de cada número
        for (int i = 0; i < tamanho; ++i) {
            int num;
            cin >> num;
            freqNumeros[num]++;
        }

        // Contar frequência das frequências
        for (auto par : freqNumeros) {
            freqFreqs[par.second]++;
        }

        // Testar cada frequência como alvo
        for (auto freqAlvo : freqFreqs) {
            int removidosTotal = 0;

            // Calcular remoções necessárias para cada frequência
            for (auto freq : freqFreqs) {
                if (freq == freqAlvo) continue;

                if (freq.first > freqAlvo.first) {
                    // Remover elementos excedentes
                    removidosTotal += (freq.first - freqAlvo.first) * freq.second;
                } else {
                    // Remover todos os elementos desta frequência
                    removidosTotal += freq.first * freq.second;
                }
            }

            minRemocoes = min(minRemocoes, removidosTotal);
        }

        cout << minRemocoes << endl;
    }

    return 0;
}
