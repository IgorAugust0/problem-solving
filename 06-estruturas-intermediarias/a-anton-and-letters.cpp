#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    // Declaração de variáveis
    string conjuntoEntrada;
    set<char> letrasDistintas;

    // Lê a linha de entrada completa
    getline(cin, conjuntoEntrada);

    // Percorre a string, ignorando colchetes, vírgulas e espaços
    for (char letra : conjuntoEntrada) {
        // Verifica se é uma letra minúscula do alfabeto inglês
        if (letra >= 'a' && letra <= 'z') {
            letrasDistintas.insert(letra);
        }
    }

    // Imprime o número de letras distintas
    cout << letrasDistintas.size() << endl;

    return 0;
}
