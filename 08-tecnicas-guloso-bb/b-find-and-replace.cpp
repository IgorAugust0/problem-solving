#include <bits/stdc++.h>
using namespace std;

// Verifica se é possível criar uma string alternada começando com valorInicial
bool verificaPadrao(string& s, int valorInicial) {
    int n = s.length();
    map<char, int> atribuicao;

    for (int i = 0; i < n; i++) {
        int valorEsperado = (valorInicial + i) % 2;

        if (atribuicao.count(s[i])) {
            if (atribuicao[s[i]] != valorEsperado) {
                return false;
            }
        } else {
            atribuicao[s[i]] = valorEsperado;
        }
    }
    return true;
}

void resolveProblema() {
    int n;
    string s;
    cin >> n >> s;

    // Tenta os dois possíveis padrões: começando com 0 ou com 1
    if (verificaPadrao(s, 0) || verificaPadrao(s, 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int casosTeste;
    cin >> casosTeste;

    while (casosTeste--) {
        resolveProblema();
    }

    return 0;
}
