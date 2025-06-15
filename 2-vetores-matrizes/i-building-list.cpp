#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Funcao para gerar todas as combinacoes possiveis de caracteres
void gerarCombos(string str, vector<string>& combos) {
    int n = str.length();
    // Total de combinacoes possiveis eh 2^n - 1
    int total = (1 << n) - 1;

    // Gera cada combinacao possivel
    for (int i = 1; i <= total; i++) {
        string combo = "";
        for (int j = 0; j < n; j++) {
            // Se o bit correspondente esta ativo, adiciona o caractere
            if (i & (1 << j)) {
                combo += str[j];
            }
        }
        combos.push_back(combo);
    }
}

int main() {
    int T;  // Numero de casos de teste
    cin >> T;

    while (T--) {
        int N;     // Tamanho da string
        string S;  // String de entrada

        cin >> N;
        cin >> S;

        vector<string> combos;
        gerarCombos(S, combos);

        // Ordena as combinacoes lexicograficamente
        sort(combos.begin(), combos.end());

        // Imprime todas as combinacoes
        for (const string& combo : combos) {
            cout << combo << endl;
        }
    }

    return 0;
}
