#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
#pragma warning(disable : 4996)

// Arrays para processamento
int alturas[1000000];    // Alturas de cada pessoa
int esquerda[1000000];   // Índice limite à esquerda para cada pessoa
int direita[1000000];    // Índice limite à direita para cada pessoa
int resultado[1000000];  // Resultado para cada comprimento

int main() {
    stack<int> pilha;
    int n;

    // Leitura da quantidade de pessoas
    cin >> n;

    // Inicializando arrays de limites
    fill(esquerda, esquerda + 1000000, -1);
    fill(direita, direita + 1000000, n);

    // Leitura das alturas
    for (int i = 0; i < n; i++)
        cin >> alturas[i];

    // Encontra para cada posição, a posição mais próxima à esquerda com altura menor
    for (int i = 0; i < n; i++) {
        while (!pilha.empty() && alturas[pilha.top()] >= alturas[i])
            pilha.pop();

        if (!pilha.empty())
            esquerda[i] = pilha.top();

        pilha.push(i);
    }

    // Limpa a pilha para reutilização
    while (!pilha.empty())
        pilha.pop();

    // Encontra para cada posição, a posição mais próxima à direita com altura menor
    for (int i = n - 1; i >= 0; i--) {
        while (!pilha.empty() && alturas[pilha.top()] >= alturas[i])
            pilha.pop();

        if (!pilha.empty())
            direita[i] = pilha.top();

        pilha.push(i);
    }

    // Calcula o resultado para cada comprimento possível
    for (int i = 0; i < n; i++) {
        int comprimento = direita[i] - esquerda[i] - 1;
        resultado[comprimento] = max(alturas[i], resultado[comprimento]);
    }

    // Processa os resultados garantindo que sejam não-crescentes
    for (int i = n; i > 0; i--)
        resultado[i] = max(resultado[i], resultado[i + 1]);

    // Exibe os resultados
    for (int i = 1; i <= n; i++)
        cout << resultado[i] << " ";

    return 0;
}