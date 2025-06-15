#include <bits/stdc++.h>
using namespace std;

// Tamanho máximo do vetor de mensagens
const int TAMANHO_MAXIMO = 2e5 + 2;

// Vetor para armazenar as mensagens
string mensagens[TAMANHO_MAXIMO];

// Mapa para controlar mensagens já processadas
map<string, int> mensagensProcessadas;

int main() {
    // Quantidade de mensagens
    int quantidadeMensagens;
    scanf("%d", &quantidadeMensagens);

    // Leitura das mensagens
    for (int i = 0; i < quantidadeMensagens; i++) {
        cin >> mensagens[i];
    }

    // Processamento das mensagens em ordem inversa
    // para exibir apenas a primeira ocorrência de cada mensagem
    for (int i = quantidadeMensagens - 1; i >= 0; i--) {
        // Verifica se a mensagem ainda não foi processada
        if (!mensagensProcessadas[mensagens[i]]) {
            // Exibe a mensagem
            cout << mensagens[i] << "\n";
            // Marca a mensagem como processada
            mensagensProcessadas[mensagens[i]] = 1;
        }
    }

    return 0;
}