#include <bits/stdc++.h>
using namespace std;

// Encontra o menor número com máximo popcount no intervalo [l,r]
long long encontraMelhorNumero(long long l, long long r) {
    long long resultado = l;
    for (long long bit = 0; bit <= 60; bit++) {
        long long mascara = 1LL << bit;
        long long novoNumero = resultado | mascara;

        if (novoNumero <= r) {
            resultado = novoNumero;
        }
    }
    return resultado;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        long long l, r;
        cin >> l >> r;
        cout << encontraMelhorNumero(l, r) << "\n";
    }

    return 0;
}
