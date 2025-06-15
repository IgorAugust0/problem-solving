#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Contador de cliques
    int contadorCliques = 0;

    // Trabalhando de trás para frente, de m para n
    while (m > n) {
        // Se m for ímpar, só podemos chegar a ele adicionando 1
        // o que significa subtrair 1 no caminho direto
        if (m % 2 == 1) {
            m++;
            contadorCliques++;
        } else {
            // Se m for par, é mais eficiente dividir por 2
            // (equivalente a multiplicar por 2 no caminho direto)
            m /= 2;
            contadorCliques++;
        }
    }

    // Se m for menor que n, podemos apenas subtrair
    contadorCliques += (n - m);

    cout << contadorCliques << endl;

    return 0;
}
