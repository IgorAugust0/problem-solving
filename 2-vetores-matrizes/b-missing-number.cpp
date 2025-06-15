#include <iostream>
using namespace std;

int main() {
    // Leitura do tamanho n
    long long n;
    cin >> n;

    // Calcula a soma esperada (1 + 2 + ... + n)
    long long soma_esperada = (n * (n + 1)) / 2;

    // Calcula a soma real dos numeros fornecidos
    long long soma_real = 0;
    for (int i = 0; i < n - 1; i++) {
        long long num;
        cin >> num;
        soma_real += num;
    }

    // O numero faltante eh a diferenca entre a soma esperada e a soma real
    cout << soma_esperada - soma_real << endl;

    return 0;
}
