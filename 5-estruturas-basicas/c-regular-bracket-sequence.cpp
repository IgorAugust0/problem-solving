#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    string sequencia;
    cin >> sequencia;

    // Usamos uma pilha para validar a sequência de parênteses
    stack<int> pilha;
    // Vetor para marcar os parênteses que serão mantidos
    vector<bool> mantido(sequencia.length(), false);

    // Processando a sequência original
    for (int i = 0; i < sequencia.length(); i++) {
        if (sequencia[i] == '(') {
            // Se for um parêntese de abertura, empilhamos o índice
            pilha.push(i);
        } else {
            // Se for um parêntese de fechamento
            if (!pilha.empty()) {
                // Se temos um parêntese de abertura correspondente, marcamos ambos para manter
                mantido[pilha.top()] = true;
                mantido[i] = true;
                pilha.pop();
            }
        }
    }

    // Contando o comprimento da sequência válida resultante
    int comprimentoMaximo = 0;
    for (bool m : mantido) {
        if (m) {
            comprimentoMaximo++;
        }
    }

    cout << comprimentoMaximo << endl;

    return 0;
}
