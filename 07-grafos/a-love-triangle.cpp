#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Número de aviões
    int n;
    cin >> n;

    // Vetor para armazenar as preferências
    vector<int> preferencias(n + 1);

    // Leitura das preferências (índices começando em 1)
    for (int i = 1; i <= n; i++) {
        cin >> preferencias[i];
    }

    // Procurando um triângulo amoroso
    bool trianguloAmoroso = false;

    for (int i = 1; i <= n; i++) {
        // Avião A gosta do avião B
        int aviaoB = preferencias[i];

        // Avião B gosta do avião C
        int aviaoC = preferencias[aviaoB];

        // Verificar se o avião C gosta do avião A (fechando o triângulo)
        if (preferencias[aviaoC] == i) {
            trianguloAmoroso = true;
            break;
        }
    }

    // Resultado
    cout << (trianguloAmoroso ? "YES" : "NO") << endl;

    return 0;
}
