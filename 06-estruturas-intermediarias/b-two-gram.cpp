#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Declaração de variáveis
    int tamanho;
    string texto;
    map<string, int> frequencia;

    // Leitura dos dados
    cin >> tamanho;
    cin >> texto;

    // Contagem das frequências dos bigramas
    for (int i = 0; i < tamanho - 1; i++) {
        string bigrama = texto.substr(i, 2);
        frequencia[bigrama]++;
    }

    // Encontrar o bigrama mais frequente
    string bigramaMaisFrequente;
    int maxFrequencia = 0;

    for (const auto& par : frequencia) {
        if (par.second > maxFrequencia) {
            maxFrequencia = par.second;
            bigramaMaisFrequente = par.first;
        }
    }

    // Imprimir resultado
    cout << bigramaMaisFrequente << endl;

    return 0;
}
